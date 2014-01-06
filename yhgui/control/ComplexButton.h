#ifndef COCOS_YHGUI_CONTROL_ComplexButton_H_
#define COCOS_YHGUI_CONTROL_ComplexButton_H_

#include "Button.h"

NS_CC_YHGUI_BEGIN
	
/**
 * 普通的按钮
 * 一个状态对应一个node，由node来决定显示的内容。
 * 可以自己扩展
 */
class ComplexButton:public Button
{
public:
    
    ComplexButton();
    
    ~ComplexButton();
    
    bool init();
    
    /**
     * 点是否在物体内
     */
    bool isPointInside(const CCPoint& point);
    
    /**
     * 设置状态对应的label
     */
    void setStateLabel(State state,CCNode* label);

    /**
     * 设置状态对应的ttf label
     */
    void setStateLabelTTF(State state,CCLabelTTF* labelTTF);
    
    /**
     * 设置状态对应的ttf label
     */
    void setStateLabelTTF(State state,const std::string& text,const std::string& fontName,float fontSize);
    
    /**
     * 设置状态对应的ttf label
     */
    void setStateLabelTTF(State state,const std::string& text,const std::string& fontName,float fontSize,const ccColor3B& color);
    
    /**
     * 设置状态对应的ttf label
     */
    void setStateLabelTTF(State state,const std::string& text, ccFontDefinition &textDefinition);
    
    /**
     * 设置状态对应的ttf label
     */
    void setStateLabelTTF(State state,const std::string& text, ccFontDefinition &textDefinition,const ccColor3B& color);
    
    /**
     * 设置状态对应的bmfont label
     */
    void setStateLabelBMFont(State state,CCLabelBMFont* labelBMFont);
    
    /**
     * 设置状态对应的bmfont label
     */
    void setStateLabelBMFont(State state,const std::string& text,const std::string& fontFile);
    
    /**
     * 设置状态对应的bmfont label
     */
    void setStateLabelBMFont(State state,const std::string& text,const std::string& fontFile,const ccColor3B& color);
    
    /**
     * 设置状态对应的background
     */
    void setStateBackground(State state,CCNode* background);
    
    /**
     * 设置状态对应的background
     */
    void setStateBackground(State state,const std::string& imageFile);
    
    /**
     * 设置状态对应的background
     */
    void setStateBackground(State state,const std::string& imageFile,const CCRect& rect);
    
    /**
     * 设置状态对应的9宫格background
     */
    void setStateBackground9Scale(State state,const std::string& imageFile);
    
    CREATE_FUNC(ComplexButton);
    
protected:
    
    virtual void changeStateComponent(State newState);
    
protected:
    
    CCNode* m_currentStateComponet;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_CONTROL_ComplexButton_H_
