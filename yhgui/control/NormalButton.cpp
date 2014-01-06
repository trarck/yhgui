#include "NormalButton.h"
#include "../utils/Utils.h"

NS_CC_YHGUI_BEGIN

static const int kLabelZOrder=10;
static const int kBackgroundZOrder=1;
	
NormalButton::NormalButton()
:m_label(NULL)
,m_labelType(kLabelTypeTTF)
,m_labelOffset(CCPointZero)
{
	
}
	
NormalButton::~NormalButton()
{

}

bool NormalButton::init()
{
    if (Button::init()) {
        //set normal state color
		this->setStateLabelColor(kNormal,ccWHITE);
        return true;
    }
    return false;
}

#if COCOS2D_DEBUG>0
void NormalButton::draw()
{
    CCSize contentSize=getContentSize();
//	ccDrawColor4B(255,0,0,255);
//	ccDrawRect(m_boundsOrigin,ccp(m_boundsOrigin.x+contentSize.width,m_boundsOrigin.y+contentSize.height));
	ccDrawColor4B(255,250,0,255);
	ccDrawRect(CCPointZero,contentSize);
    
    if (m_label) {
        ccDrawColor4B(0,0,255,255);
        CCRect labelRect=m_label->boundingBox();
        ccDrawRect(labelRect.origin,ccp(labelRect.getMaxX(),labelRect.getMaxY()));
    }
    
    CCNode* currentBackground=static_cast<CCNode*>(m_states->objectForKey(m_state));

    if (currentBackground) {
        ccDrawColor4B(0,255,0,255);
        CCRect bgRect=currentBackground->boundingBox();
        ccDrawRect(bgRect.origin,ccp(bgRect.getMaxX(),bgRect.getMaxY()));
    }
}
#endif

/**
 * 文字不会超过背景,所以button的大小是背景的大小
 */
void NormalButton::changeStateComponent(State newState)
{    
    if (!m_stateDirty) {
        return;
    }
    m_stateDirty=false;

    CCRect maxRect=CCRectZero;
    
    if (m_label) {
        //set label color
        if (m_stateColors.find(newState)!=m_stateColors.end()) {
            switch (m_labelType) {
                case kLabelTypeTTF:{
                    
                    CCLabelTTF* labelTTF=static_cast<CCLabelTTF*>(m_label);
                    
                    labelTTF->setColor(m_stateColors[newState]);
                    
                    break;
                }
                case kLabelTypeBMFont:{
                    CCLabelBMFont* labelBMFont=static_cast<CCLabelBMFont*>(m_label);
                    labelBMFont->setColor(m_stateColors[newState]);
                    break;
                }
                default:
                    break;
            }
        }
        
        maxRect=m_label->boundingBox();
    }
    
    //set background
    
    CCNode* newBackground=static_cast<CCNode*>(m_states->objectForKey(newState));
    
    //no new component do nothing
    if (newBackground) {
        
        CCNode* currentBackground=static_cast<CCNode*>(m_states->objectForKey(m_state));
        
        if (currentBackground){
            //remove current state component
            currentBackground->removeFromParentAndCleanup(false);
        }
        
        //add new state component
        this->addChild(newBackground,kBackgroundZOrder);
        
        maxRect=newBackground->boundingBox();
    }

    //set content size
    setContentSize(maxRect.size);

    //setBoundsOrigin(maxRect.origin);
    //fix label and background position to center
    if (m_label) {
		//修正之前的位置
        m_label->setPosition(ccp(maxRect.size.width/2+m_labelOffset.x, maxRect.size.height/2+m_labelOffset.y));
    }
    
    if (newBackground) {
        newBackground->setPosition(ccp(maxRect.size.width/2, maxRect.size.height/2));
    }
}

/**
 * 设置通用的label
 */
void NormalButton::setLabel(CCNode* label)
{
    this->addChild(label,kLabelZOrder);
    m_label=label;
}

/**
 * 设置状态对应的ttf label
 */
void NormalButton::setLabelTTF(const std::string& text,const std::string& fontName,float fontSize)
{
    CCLabelTTF* labelTTF=new CCLabelTTF();
    labelTTF->initWithString(text.c_str(), fontName.c_str(), fontSize);
    setLabel(labelTTF);
	setLabelType(kLabelTypeTTF);
    
    labelTTF->release();
}

/**
 * 设置状态对应的ttf label
 */
void NormalButton::setLabelTTF(const std::string& text, ccFontDefinition &textDefinition)
{
    CCLabelTTF* labelTTF=new CCLabelTTF();
    labelTTF->initWithStringAndTextDefinition(text.c_str(), textDefinition);
    
    setLabel(labelTTF);
	setLabelType(kLabelTypeTTF);
    
    labelTTF->release();
}

/**
 * 设置状态对应的bmfont label
 */
void NormalButton::setLabelBMFont(const std::string& text,const std::string& fontFile)
{
    CCLabelBMFont* labelBMFont=new CCLabelBMFont();
    labelBMFont->initWithString(text.c_str(), fontFile.c_str());
    
    setLabel(labelBMFont);
    setLabelType(kLabelTypeBMFont);
    labelBMFont->release();
}

/**
 * 设置label状态对应的颜色
 */
void NormalButton::setStateLabelColor(State state,const ccColor3B& color)
{
    CCLOG("set state color:%d",state);
    m_stateColors[state]=color;
}

/**
 * 设置状态对应的background
 */
void NormalButton::setStateBackground(State state,CCNode* background)
{
    //get default state component
    m_states->setObject(background, state);
}

/**
 * 设置状态对应的background
 */
void NormalButton::setStateBackground(State state,const std::string& imageFile)
{
    CCSprite* background=new CCSprite();
    background->initWithFile(imageFile.c_str());
    
    setStateBackground(state, background);
    
    background->release();
}

NS_CC_YHGUI_END