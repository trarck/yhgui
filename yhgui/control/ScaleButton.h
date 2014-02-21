#ifndef COCOS_YHGUI_CONTROL_SCALEBUTTON_H_
#define COCOS_YHGUI_CONTROL_SCALEBUTTON_H_

#include "NormalButton.h"
#include "cocos-ext.h"

NS_CC_YHGUI_BEGIN

/**
 * 可放大的按钮
 * 9宫格，3段
 */
class ScaleButton:public NormalButton
{
public:
    
    ScaleButton();
    
    ~ScaleButton();
        
    /**
     * 设置状态对应的background
     */
    void setStateBackgroundScale9(State state,extension::CCScale9Sprite* background);
    
    /**
     * 设置状态对应的background
     * 只提供一种普通的扩展，其它可以使用上面的方法实现
     */
    void setStateBackgroundScale9(State state,const std::string& imageFile);
    
    CREATE_FUNC(ScaleButton);
    
    inline extension::CCScale9Sprite* getCurrentBackground()
    {
        return m_currentBackground;
    }
    
protected:
    
    virtual void updateStateComponent(State newState);
    
protected:
    
    extension::CCScale9Sprite* m_currentBackground;

};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_CONTROL_SCALEBUTTON_H_
