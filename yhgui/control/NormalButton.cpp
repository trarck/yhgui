#include "NormalButton.h"
#include "Utils.h"

NS_CC_YHGUI_BEGIN

static const int kLabelZOrder=10;
static const int kBackgroundZOrder=1;
	
NormalButton::NormalButton()
:m_label(NULL)
,m_labelType(kLabelTypeTTF)
{
	
}
	
NormalButton::~NormalButton()
{

}

bool NormalButton::init()
{
    if (Button::init()) {
        
        return true;
    }
    return false;
}

void NormalButton::changeStateComponent(State newState)
{    
    if (!m_stateDirty) {
        return;
    }
    m_stateDirty=false;
    
    CCRect labelRect;
    
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
        
        labelRect=m_label->boundingBox();
    }
    
    CCRect backgroundRect;
    
    //set background
    
    CCNode* newBackground=static_cast<CCNode*>(m_states->objectForKey(newState));
    
    //no new component do nothing
    if (newBackground) {
        CCNode* currentBackground=static_cast<CCNode*>(m_states->objectForKey(m_state));
        
        //remove current state component
        currentBackground->removeFromParentAndCleanup(false);
        
        //add new state component
        this->addChild(newBackground,kBackgroundZOrder);
        
        backgroundRect=newBackground->boundingBox();
    }

    //set content size
    CCRect maxRect = Utils::CCRectUnion(labelRect, backgroundRect);
    
    setContentSize(CCSizeMake(maxRect.size.width, maxRect.size.height));
    
    //fix label and background position to center
    
    if (m_label) {
        m_label->setPosition(ccp(maxRect.size.width/2, maxRect.size.height/2));
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
    
    labelBMFont->release();
}

/**
 * 设置label状态对应的颜色
 */
void NormalButton::setStateLabelColor(State state,ccColor3B& color)
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