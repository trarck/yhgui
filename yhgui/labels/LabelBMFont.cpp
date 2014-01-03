#include "LabelBMFont.h"

NS_CC_YHGUI_BEGIN
	
LabelBMFont::LabelBMFont()
:m_originalRenderer(NULL)
{
	
}
	
LabelBMFont::~LabelBMFont()
{

}

bool LabelBMFont::init()
{
    return this->init("", "Helvetica", 12);
}

bool LabelBMFont::init(const std::string& text, const std::string& fntFile, float width, CCTextAlignment alignment, CCPoint imageOffset)
{
    if (Component::init()) {
        m_needDispatchToChildrenWhenCapthure=false;
        
        m_originalRenderer=new CCLabelBMFont();
        m_originalRenderer->initWithString(text.c_str(), fntFile.c_str(),width,alignment,imageOffset);
        addChild(m_originalRenderer);
        m_originalRenderer->release();
        this->setContentSize(m_originalRenderer->getContentSize());
        return true;
    }
    
    return false;
}


LabelBMFont* LabelBMFont::create(const std::string& text, const std::string& fntFile, float width, CCTextAlignment alignment, CCPoint imageOffset)
{

    yhgui::LabelBMFont* pRet=new yhgui::LabelBMFont();
    if (pRet && pRet->init(text, fntFile,width,alignment,imageOffset)) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return NULL;
}

LabelBMFont* LabelBMFont::create(const std::string& text, const std::string& fntFile, float width, CCTextAlignment alignment)
{
    return LabelBMFont::create(text, fntFile, kCCLabelAutomaticWidth, alignment, CCPointZero);
}

LabelBMFont* LabelBMFont::create(const std::string& text, const std::string& fntFile, float width)
{
    return LabelBMFont::create(text, fntFile, width, kCCTextAlignmentLeft, CCPointZero);
}

LabelBMFont* LabelBMFont::create(const std::string& text, const std::string& fntFile)
{
    return LabelBMFont::create(text, fntFile, kCCLabelAutomaticWidth, kCCTextAlignmentLeft, CCPointZero);
}


//=============LabelBMFont的基本属性操作=================//
void LabelBMFont::setText(const std::string& text)
{
    m_originalRenderer->setString(text.c_str());
    this->setContentSize(m_originalRenderer->getContentSize());
}

std::string LabelBMFont::getText()
{
    return m_originalRenderer->getString();
}

void LabelBMFont::setHorizontalAlignment(CCTextAlignment horizontalAlignment)
{
    m_horizontalAlignment=horizontalAlignment;
    m_originalRenderer->setAlignment(horizontalAlignment);
    this->setContentSize(m_originalRenderer->getContentSize());
}

void LabelBMFont::setFontName(const std::string& fontName)
{
	
}

std::string LabelBMFont::getFontName()
{
    return  "";
}

NS_CC_YHGUI_END