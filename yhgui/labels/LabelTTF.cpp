#include "LabelTTF.h"

NS_CC_YHGUI_BEGIN
	
LabelTTF::LabelTTF()
:m_originalRenderer(NULL)
{

}
	
LabelTTF::~LabelTTF()
{

}

bool LabelTTF::init()
{
    return this->init("", "Helvetica", 12);
}

bool LabelTTF::init(const std::string& text, const std::string& fontName, float fontSize)
{
    return this->init(text, fontName, fontSize, CCSizeZero, kCCTextAlignmentLeft,kCCVerticalTextAlignmentTop);
}

bool LabelTTF::init(const std::string& text, const std::string& fontName, float fontSize,
          const CCSize& dimensions, CCTextAlignment alignment)
{
    return this->init(text, fontName, fontSize, dimensions, alignment, kCCVerticalTextAlignmentTop);
}

bool LabelTTF::init(const std::string& text, const std::string& fontName, float fontSize,
          const CCSize& dimensions, CCTextAlignment alignment,CCVerticalTextAlignment vAlignment)
{
    if (Component::init()) {
        m_needDispatchToChildrenWhenCapthure=false;
        
        m_originalRenderer=new CCLabelTTF();
        m_originalRenderer->initWithString(text.c_str(), fontName.c_str(), fontSize, dimensions, alignment, vAlignment);
        addChild(m_originalRenderer);
        m_originalRenderer->release();
        
        this->setContentSize(m_originalRenderer->getContentSize());
        
        return true;
    }
    
    return false;
}


LabelTTF* LabelTTF::create(const std::string& text, const std::string& fontName, float fontSize)
{
    return LabelTTF::create(text, fontName, fontSize, CCSizeZero, kCCTextAlignmentLeft, kCCVerticalTextAlignmentTop);
}

LabelTTF* LabelTTF::create(const std::string& text, const std::string& fontName, float fontSize,
              const CCSize& dimensions, CCTextAlignment alignment)
{
    return LabelTTF::create(text, fontName, fontSize, dimensions, alignment, kCCVerticalTextAlignmentTop);
}

LabelTTF* LabelTTF::create(const std::string& text, const std::string& fontName, float fontSize,
                     const CCSize& dimensions, CCTextAlignment alignment,CCVerticalTextAlignment vAlignment)
{
    yhgui::LabelTTF* pRet=new yhgui::LabelTTF();
    if (pRet && pRet->init(text, fontName, fontSize, dimensions, alignment, vAlignment)) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return NULL;
}


//=============LabelTTF的基本属性操作=================//
void LabelTTF::setText(const std::string& text)
{
    m_originalRenderer->setString(text.c_str());
    setContentSize(m_originalRenderer->getContentSize());
}

std::string LabelTTF::getText()
{
    return m_originalRenderer->getString();
}

void LabelTTF::setDimensions(const CCSize& dimensions)
{
    m_originalRenderer->setDimensions(dimensions);
    setContentSize(m_originalRenderer->getContentSize());
}

CCSize LabelTTF::getDimensions()
{
    return m_originalRenderer->getDimensions();
}

void LabelTTF::setHorizontalAlignment(CCTextAlignment horizontalAlignment)
{
    m_originalRenderer->setHorizontalAlignment(horizontalAlignment);
    setContentSize(m_originalRenderer->getContentSize());
}

CCTextAlignment LabelTTF::getHorizontalAlignment()
{
    return m_originalRenderer->getHorizontalAlignment();
}

void LabelTTF::setVerticalAlignment(CCVerticalTextAlignment verticalAlignment)
{
	m_originalRenderer->setVerticalAlignment(verticalAlignment);
    setContentSize(m_originalRenderer->getContentSize());
}

CCVerticalTextAlignment LabelTTF::getVerticalAlignment()
{
	return m_originalRenderer->getVerticalAlignment();
}

void LabelTTF::setFontName(const std::string& fontName)
{
	m_originalRenderer->setFontName(fontName.c_str());
    setContentSize(m_originalRenderer->getContentSize());
}

std::string LabelTTF::getFontName()
{
    return m_originalRenderer->getFontName();
}

void LabelTTF::setFontSize(float fontSize)
{
	m_originalRenderer->setFontSize(fontSize);
    setContentSize(m_originalRenderer->getContentSize());
}

float LabelTTF::getFontSize()
{
    return m_originalRenderer->getFontSize();
}

//=============LabelTTF的效果=================//
/** enable or disable shadow for the LabelTTF */
void LabelTTF::enableShadow(const CCSize &shadowOffset, float shadowOpacity, float shadowBlur, bool mustUpdateTexture)
{
    m_originalRenderer->enableShadow(shadowOffset, shadowOpacity, shadowBlur,mustUpdateTexture);
    if (mustUpdateTexture){
        setContentSize(m_originalRenderer->getContentSize());
    }
}

/** disable shadow rendering */
void LabelTTF::disableShadow(bool mustUpdateTexture)
{
    m_originalRenderer->disableShadow(mustUpdateTexture);
    if (mustUpdateTexture){
        setContentSize(m_originalRenderer->getContentSize());
    }
}

/** enable or disable stroke */
void LabelTTF::enableStroke(const ccColor3B &strokeColor, float strokeSize, bool mustUpdateTexture)
{
    m_originalRenderer->enableStroke(strokeColor, strokeSize,mustUpdateTexture);
    if (mustUpdateTexture){
        setContentSize(m_originalRenderer->getContentSize());
    }
}

/** disable stroke */
void LabelTTF::disableStroke(bool mustUpdateTexture)
{
    m_originalRenderer->disableStroke(mustUpdateTexture);
    if (mustUpdateTexture){
        setContentSize(m_originalRenderer->getContentSize());
    }
}

/** set text tinting */
void LabelTTF::setFontFillColor(const ccColor3B &tintColor, bool mustUpdateTexture)
{
    m_originalRenderer->setFontFillColor(tintColor,mustUpdateTexture);
    if (mustUpdateTexture){
        setContentSize(m_originalRenderer->getContentSize());
    }
}

NS_CC_YHGUI_END