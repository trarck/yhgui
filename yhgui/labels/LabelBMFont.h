#ifndef COCOS_YHGUI_LABELS_LABELBMFONT_H_
#define COCOS_YHGUI_LABELS_LABELBMFONT_H_

#include "../Component.h"

NS_CC_YHGUI_BEGIN
	
class LabelBMFont:public Component
{
public:
    
    LabelBMFont();
    
    ~LabelBMFont();
    
    bool init();
    
    bool init(const std::string& text, const std::string& fntFile, float width = kCCLabelAutomaticWidth, CCTextAlignment alignment = kCCTextAlignmentLeft, CCPoint imageOffset = CCPointZero);


    static LabelBMFont* create(const std::string& text, const std::string& fntFile, float width, CCTextAlignment alignment, CCPoint imageOffset);
    
	static LabelBMFont* create(const std::string& text, const std::string& fntFile, float width, CCTextAlignment alignment);
    
	static LabelBMFont* create(const std::string& text, const std::string& fntFile, float width);
    
	static LabelBMFont* create(const std::string& text, const std::string& fntFile);
    
    CREATE_FUNC(LabelBMFont);

	//=============LabelBMFont的基本属性操作=================//
	void setText(const std::string& text);
	std::string getText();

	void setHorizontalAlignment(CCTextAlignment horizontalAlignment);
    
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
    CCLabelBMFont* m_originalRenderer;
    
    CCTextAlignment m_horizontalAlignment;
    CCVerticalTextAlignment m_verticalAlignment;
    float m_fontSize;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_LABELS_LABELBMFONT_H_
