#ifndef COCOS_YHGUI_LABELS_LABELTTF_H_
#define COCOS_YHGUI_LABELS_LABELTTF_H_

#include "../Component.h"

NS_CC_YHGUI_BEGIN
	
class LabelTTF:public Component
{
public:
    
    LabelTTF();
    
    ~LabelTTF();
    
    bool init();
    
    bool init(const std::string& text, const std::string& fontName, float fontSize);
    
    bool init(const std::string& text, const std::string& fontName, float fontSize,
              const CCSize& dimensions, CCTextAlignment alignment);
    
    bool init(const std::string& text, const std::string& fontName, float fontSize,
              const CCSize& dimensions, CCTextAlignment alignment,CCVerticalTextAlignment vAlignment);

    
    CREATE_FUNC(LabelTTF);
    
    
    static LabelTTF* create(const std::string& text, const std::string& fontName, float fontSize);
    
    static LabelTTF* create(const std::string& text, const std::string& fontName, float fontSize,
              const CCSize& dimensions, CCTextAlignment alignment);
    
    static LabelTTF* create(const std::string& text, const std::string& fontName, float fontSize,
              const CCSize& dimensions, CCTextAlignment alignment,CCVerticalTextAlignment vAlignment);
    
    
	//=============LabelTTF的基本属性操作=================//
	void setText(const std::string& text);
	std::string getText();

	void setDimensions(const CCSize& dimensions);
	CCSize getDimensions();

	void setHorizontalAlignment(CCTextAlignment horizontalAlignment);
	CCTextAlignment getHorizontalAlignment();

	void setVerticalAlignment(CCVerticalTextAlignment verticalAlignment);
	CCVerticalTextAlignment getVerticalAlignment();

	void setFontName(const std::string& fontName);
	std::string getFontName();

	void setFontSize(float fontSize);
	float getFontSize();
    
    //=============LabelTTF的效果=================//
    /** enable or disable shadow for the LabelTTF */
    void enableShadow(const CCSize &shadowOffset, float shadowOpacity, float shadowBlur, bool mustUpdateTexture = true);
    
    /** disable shadow rendering */
    void disableShadow(bool mustUpdateTexture = true);
    
    /** enable or disable stroke */
    void enableStroke(const ccColor3B &strokeColor, float strokeSize, bool mustUpdateTexture = true);
    
    /** disable stroke */
    void disableStroke(bool mustUpdateTexture = true);
    
    /** set text tinting */
    void setFontFillColor(const ccColor3B &tintColor, bool mustUpdateTexture = true);
    
protected:
    
    CCLabelTTF* m_originalRenderer;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_LABELS_LABELTTF_H_
