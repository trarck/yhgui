#include "LabelAtlas.h"

NS_CC_YHGUI_BEGIN
	
LabelAtlas::LabelAtlas()
:m_originalRenderer(NULL)
{
	
}
	
LabelAtlas::~LabelAtlas()
{

}

bool LabelAtlas::init(const std::string& text, const std::string& fontFile)
{
    if (Component::init()) {
        
        m_originalRenderer=new CCLabelAtlas();
        m_originalRenderer->initWithString(text.c_str(), fontFile.c_str());
        
        return true;
    }
    
    return false;
}

bool LabelAtlas::init(const std::string& text, const std::string& charMapFile, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap)
{
    if (Component::init()) {
        
        m_originalRenderer=new CCLabelAtlas();
        m_originalRenderer->initWithString(text.c_str(), charMapFile.c_str(), itemWidth, itemHeight, startCharMap);
        
        return true;
    }
    
    return false;
}

bool LabelAtlas::init(const std::string& text, CCTexture2D* texture, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap)
{
    if (Component::init()) {
        m_needDispatchToChildrenWhenCapthure=false;
        m_originalRenderer=new CCLabelAtlas();
        m_originalRenderer->initWithString(text.c_str(), texture, itemWidth, itemHeight, startCharMap);
        addChild(m_originalRenderer);
        m_originalRenderer->release();
        
        return true;
    }
    
    return false;
}

LabelAtlas* LabelAtlas::create(const std::string& text, const std::string& fontFile)
{
    yhgui::LabelAtlas* pRet=new yhgui::LabelAtlas();
    if (pRet && pRet->init(text,fontFile)) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return NULL;
}

LabelAtlas* LabelAtlas::create(const std::string& text, const std::string& charMapFile, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap)
{
    yhgui::LabelAtlas* pRet=new yhgui::LabelAtlas();
    if (pRet && pRet->init(text,charMapFile,itemWidth,itemHeight,startCharMap)) {
        pRet->autorelease();
        return pRet;
    }
    
    CC_SAFE_DELETE(pRet);
    return NULL;
}


//=============LabelAtlas的基本属性操作=================//
void LabelAtlas::setText(const std::string& text)
{
    m_originalRenderer->setString(text.c_str());
}

std::string LabelAtlas::getText()
{
    return m_originalRenderer->getString();
}

NS_CC_YHGUI_END