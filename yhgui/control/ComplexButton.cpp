#include "ComplexButton.h"
#include "cocos-ext.h"
#include "../utils/Utils.h"

NS_CC_YHGUI_BEGIN

static const int kLabelZOrder=10;
static const int kBackgroundZOrder=1;
	
ComplexButton::ComplexButton()
:m_currentStateComponet(NULL)
{
	
}
	
ComplexButton::~ComplexButton()
{
	CC_SAFE_RELEASE_NULL(m_states);
}

bool ComplexButton::init()
{
    if (Button::init()) {
        
        return true;
    }
    return false;
}

/**
 * 点是否在物体内
 */
bool ComplexButton::isPointInside(const CCPoint& point)
{
    if (m_currentStateComponet) {
        CCObject* pObj=NULL;
        CCArray* children=m_currentStateComponet->getChildren();
        
        CCARRAY_FOREACH(children, pObj){
            if(Utils::isPointInside(point, static_cast<CCNode*>(pObj))){
                return true;
            }
        }
    }
    
    return false;
}

void ComplexButton::updateStateComponent(State newState)
{
    if (!m_stateDirty) {
        return;
    }
    m_stateDirty=false;
    
    m_currentStateComponet=static_cast<CCNode*>(m_states->objectForKey(newState));
    if (m_currentStateComponet) {
        
        CCNode* oldStateComponent=static_cast<CCNode*>(m_states->objectForKey(m_state));
        
        if (oldStateComponent) {
            oldStateComponent->removeFromParentAndCleanup(false);
        }
        
        this->addChild(m_currentStateComponet);
    }
    
}

/**
 * 设置状态对应的label
 */
void ComplexButton::setStateLabel(State state,CCNode* label)
{
    //get default state component
    CCNode* stateComponent=static_cast<CCNode*>(m_states->objectForKey(state));
    
    if (!stateComponent) {
        stateComponent=new CCNode();
        
        m_states->setObject(stateComponent, state);
        
        stateComponent->release();
    }
    
    label->removeFromParentAndCleanup(false);
    
    stateComponent->addChild(label,kLabelZOrder);
    
    updateCurrentStateComponent(state);
}

/**
 * 设置状态对应的ttf label
 */
void ComplexButton::setStateLabelTTF(State state,CCLabelTTF* labelTTF)
{
    setStateLabel(state, labelTTF);
}

/**
 * 设置状态对应的ttf label
 */
void ComplexButton::setStateLabelTTF(State state,const std::string& text,const std::string& fontName,float fontSize)
{
    CCLabelTTF* labelTTF=new CCLabelTTF();
    labelTTF->initWithString(text.c_str(), fontName.c_str(), fontSize);
    
    setStateLabel(state, labelTTF);
    
    labelTTF->release();
}

/**
 * 设置状态对应的ttf label
 */
void ComplexButton::setStateLabelTTF(State state,const std::string& text,const std::string& fontName,float fontSize,const ccColor3B& color)
{
    CCLabelTTF* labelTTF=new CCLabelTTF();
    labelTTF->initWithString(text.c_str(), fontName.c_str(), fontSize);
    labelTTF->setColor(color);
    
    setStateLabel(state, labelTTF);
    
    labelTTF->release();
}

/**
 * 设置状态对应的ttf label
 */
void ComplexButton::setStateLabelTTF(State state,const std::string& text, ccFontDefinition &textDefinition)
{
    CCLabelTTF* labelTTF=new CCLabelTTF();
    labelTTF->initWithStringAndTextDefinition(text.c_str(), textDefinition);
    
    setStateLabel(state, labelTTF);
    
    labelTTF->release();
}

/**
 * 设置状态对应的ttf label
 */
void ComplexButton::setStateLabelTTF(State state,const std::string& text, ccFontDefinition &textDefinition,const ccColor3B& color)
{
    CCLabelTTF* labelTTF=new CCLabelTTF();
    labelTTF->initWithStringAndTextDefinition(text.c_str(), textDefinition);
    labelTTF->setColor(color);
    
    setStateLabel(state, labelTTF);
    
    labelTTF->release();
}

/**
 * 设置状态对应的bmfont label
 */
void ComplexButton::setStateLabelBMFont(State state,CCLabelBMFont* labelBMFont)
{
    setStateLabel(state, labelBMFont);
}

/**
 * 设置状态对应的bmfont label
 */
void ComplexButton::setStateLabelBMFont(State state,const std::string& text,const std::string& fontFile)
{
    CCLabelBMFont* labelBMFont=new CCLabelBMFont();
    labelBMFont->initWithString(text.c_str(), fontFile.c_str());
    
    setStateLabelBMFont(state, labelBMFont);
    
    labelBMFont->release();
}

/**
 * 设置状态对应的bmfont label
 */
void ComplexButton::setStateLabelBMFont(State state,const std::string& text,const std::string& fontFile,const ccColor3B& color)
{
    CCLabelBMFont* labelBMFont=new CCLabelBMFont();
    labelBMFont->initWithString(text.c_str(), fontFile.c_str());
    labelBMFont->setColor(color);
    
    setStateLabelBMFont(state, labelBMFont);
    
    labelBMFont->release();
}


/**
 * 设置状态对应的background
 */
void ComplexButton::setStateBackground(State state,CCNode* background)
{
    //get default state component
    CCNode* stateComponent=static_cast<CCNode*>(m_states->objectForKey(state));
    
    if (!stateComponent) {
        stateComponent=new CCNode();
        
        m_states->setObject(stateComponent, state);
        
        stateComponent->release();
    }
    
    stateComponent->addChild(background,kBackgroundZOrder);
    
    updateCurrentStateComponent(state);
}

/**
 * 设置状态对应的background
 */
void ComplexButton::setStateBackground(State state,const std::string& imageFile)
{
    CCSprite* background=CCSprite::create(imageFile.c_str());
    
    setStateBackground(state, background);
}

/**
 * 设置状态对应的background
 */
void ComplexButton::setStateBackground(State state,const std::string& imageFile,const CCRect& rect)
{
    CCSprite* background=CCSprite::create(imageFile.c_str(),rect);
    
    setStateBackground(state, background);
}

/**
 * 设置状态对应的9宫格background
 */
void ComplexButton::setStateBackground9Scale(State state,const std::string& imageFile)
{
    extension::CCScale9Sprite* background=extension::CCScale9Sprite::create(imageFile.c_str());
    setStateBackground(state, background);
}

NS_CC_YHGUI_END