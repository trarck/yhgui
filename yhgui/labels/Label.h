#ifndef COCOS_YHGUI_LABELS_LABEL_H_
#define COCOS_YHGUI_LABELS_LABEL_H_

#include "../Component.h"

NS_CC_YHGUI_BEGIN
	
class Label:public Component
{
public:
    
    Label();
    
    ~Label();

	//=============label的基本属性操作=================//
	void setText(const std::string& text);
	const std::string& getText();

	void setDimensions(const CCSize& dimensions);
	CCSize getDimensions();

	void setHorizontalAlignment(CCTextAlignment horizontalAlignment);
	CCTextAlignment getHorizontalAlignment();

	void setVerticalAlignment(CCVerticalTextAlignment verticalAlignment);
	CCVerticalTextAlignment getVerticalAlignment();

	void setFontName(const std::string& fontName);
	const std::string& getFontName();

	void setFontSize(float fontSize);
	float getFontSize();

    CREATE_FUNC(Label);
    
protected:
    
    CCLabelTTF* m_originalRenderer;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_LABELS_LABEL_H_
