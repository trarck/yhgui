#ifndef COCOS_YHGUI_CONTROL_NormalButton_H_
#define COCOS_YHGUI_CONTROL_NormalButton_H_

#include "Button.h"

NS_CC_YHGUI_BEGIN

/**
 * 普通的按钮
 * 尽量减少资源占用
 * 只有一个label,根据不同的状态来改变label属性。
 * 背景会有多个,根据不同状态来切换。
 * 背景技能9宫格
 * label和背景的锚点都是(0.5,0.5)
 */
class NormalButton:public Button
{
public:
    
    NormalButton();
    
    ~NormalButton();
    
    bool init();

	#if COCOS2D_DEBUG>0
	void draw();
	#endif
    
    /**
     * 设置通用的label
     */
    void setLabel(CCNode* label);
    
    /**
     * 取得通用的label
     */
    CCNode* getLabel()
    {
        return m_label;
    }
    
    /**
     * 设置状态对应的ttf label
     */
    void setLabelTTF(const std::string& text,const std::string& fontName,float fontSize);

    /**
     * 设置状态对应的ttf label
     */
    void setLabelTTF(const std::string& text, ccFontDefinition &textDefinition);
    
    /**
     * 设置状态对应的bmfont label
     */
    void setLabelBMFont(const std::string& text,const std::string& fontFile);
    
    /**
     * 设置label状态对应的颜色
     */
    void setStateLabelColor(State state,const ccColor3B& color);
    
    /**
     * 设置状态对应的background
     */
    void setStateBackground(State state,CCNode* background);
    
    /**
     * 设置状态对应的background
     */
    void setStateBackground(State state,const std::string& imageFile);
    
    CREATE_FUNC(NormalButton);
    
    enum LabelType
    {
        kLabelTypeTTF=1,
        kLabelTypeBMFont,
        kLabelTypeAtlas
    };
    
    
    inline void setLabelType(LabelType labelType)
    {
        m_labelType = labelType;
    }
    
    inline LabelType getLabelType()
    {
        return m_labelType;
    }
    
    inline void setLabelOffset(const CCPoint& labelOffset)
    {
        m_labelOffset = labelOffset;
        if (m_label) {
            m_label->setPosition(labelOffset);
        }
    }
    
    inline const CCPoint& getLabelOffset()
    {
        return m_labelOffset;
    }
    
protected:
    
    virtual void updateStateComponent(State newState);
    
protected:
    
    CCNode* m_label;
    
    std::map<State, ccColor3B> m_stateColors;
    
    LabelType m_labelType;
    
    /**
     * label的偏移量
     */
    CCPoint m_labelOffset;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_CONTROL_NormalButton_H_
