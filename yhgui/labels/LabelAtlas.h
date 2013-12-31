#ifndef COCOS_YHGUI_LABELS_LabelAtlas_H_
#define COCOS_YHGUI_LABELS_LabelAtlas_H_

#include "../Component.h"

NS_CC_YHGUI_BEGIN
	
class LabelAtlas:public Component
{
public:
    
    LabelAtlas();
    
    ~LabelAtlas();
    
    bool init(const std::string& text, const std::string& fontFile);
    
    bool init(const std::string& text, const std::string& charMapFile, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);
    
    bool init(const std::string& text, CCTexture2D* texture, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);
    
    static LabelAtlas* create(const std::string& text, const std::string& fontFile);
    
    static LabelAtlas* create(const std::string& text, const std::string& charMapFile, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);
    
    
	//=============LabelAtlas的基本属性操作=================//
	void setText(const std::string& text);
	std::string getText();

    inline void setHorizontalAlignment(CCTextAlignment horizontalAlignment)
    {
        m_horizontalAlignment=horizontalAlignment;
    }
    
	inline CCTextAlignment getHorizontalAlignment()
    {
        return m_horizontalAlignment;
    }
    
	inline void setVerticalAlignment(CCVerticalTextAlignment verticalAlignment)
    {
        m_verticalAlignment = verticalAlignment;
    }
    
    inline CCVerticalTextAlignment getVerticalAlignment()
    {
        return m_verticalAlignment;
    }
    
	void setFontName(const std::string& fontName);
	std::string getFontName();
    
	inline void setFontSize(float fontSize)
    {
        m_fontSize = fontSize;
    }
    
    inline float getFontSize()
    {
        return m_fontSize;
    }
    
protected:
    
    CCLabelAtlas* m_originalRenderer;
    
    CCTextAlignment m_horizontalAlignment;
    CCVerticalTextAlignment m_verticalAlignment;
    float m_fontSize;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_LABELS_LabelAtlas_H_
