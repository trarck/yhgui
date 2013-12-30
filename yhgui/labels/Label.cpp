#include "Label.h"

NS_CC_YHGUI_BEGIN
	
Label::Label()
:m_originalRenderer(NULL)
{
	
}
	
Label::~Label()
{
	CC_SAFE_RELEASE_NULL(m_originalRenderer);
}

void Label::setText(const std::string& text)
{
    m_originalRenderer->setString(text.c_str());
}

const std::string& Label::getText()
{
    return std::string(m_originalRenderer->getString());
}

void Label::setDimensions(const CCSize& dimensions)
{
    m_originalRenderer->setDimensions(dimensions);
}

CCSize Label::getDimensions()
{
    return m_originalRenderer->getDimensions();
}

void Label::setHorizontalAlignment(CCTextAlignment horizontalAlignment)
{
    m_originalRenderer->setHorizontalAlignment(horizontalAlignment);
}

CCTextAlignment Label::getHorizontalAlignment()
{
    return m_originalRenderer->getHorizontalAlignment();
}

void Label::setVerticalAlignment(CCVerticalTextAlignment verticalAlignment)
{
	m_originalRenderer->setVerticalAlignment(verticalAlignment);
}

CCVerticalTextAlignment Label::getVerticalAlignment()
{
	return m_originalRenderer->getVerticalAlignment();
}

void Label::setFontName(const std::string& fontName)
{
	m_originalRenderer->setFontName(fontName.c_str());
}

const std::string& Label::getFontName()
{
    return m_originalRenderer->getFontName();
}

void Label::setFontSize(float fontSize)
{
	m_originalRenderer->setFontSize(fontSize);
}

float Label::getFontSize()
{
    return m_originalRenderer->getFontSize();
}

NS_CC_YHGUI_END