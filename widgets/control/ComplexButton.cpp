#include "ComplexButton.h"

NS_CC_YHGUI_BEGIN

static const int kLabelZOrder=10;
static const int kBackgroundZOrder=1;
	
ComplexButton::ComplexButton()
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

void ComplexButton::changeStateComponent(State newState)
{
    if (!m_stateDirty) {
        return;
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
    
    stateComponent->addChild(label,kLabelZOrder);
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
}

/**
 * 设置状态对应的background
 */
void ComplexButton::setStateBackground(State state,const std::string& imageFile)
{
    
}
NS_CC_YHGUI_END