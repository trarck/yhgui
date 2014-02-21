#ifndef COCOS_YHGUI_CONTROL_BUTTON_H_
#define COCOS_YHGUI_CONTROL_BUTTON_H_

#include "Control.h"

NS_CC_YHGUI_BEGIN
	
/**
 * 普通的按钮
 * 一个状态对应一个node，由node来决定显示的内容。
 * 可以自己扩展
 */
class Button:public Control
{
public:
    
    Button();
    
    ~Button();
    
    bool init();
    
    virtual void onEnter();
    
//    virtual void onExit();

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    virtual void changeState(State newState);
    
    void setStateComponent(State state,CCNode* component);

    CREATE_FUNC(Button);
    
    inline void setTouchDownZoomable(bool touchDownZoomable)
    {
        m_touchDownZoomable = touchDownZoomable;
    }
    
    inline bool isTouchDownZoomable()
    {
        return m_touchDownZoomable;
    }
    
    inline void setTouchDownZoomSize(float touchDownZoomSize)
    {
        m_touchDownZoomSize = touchDownZoomSize;
    }
    
    inline float getTouchDownZoomSize()
    {
        return m_touchDownZoomSize;
    }
    
    inline void setPreferredSize(const CCSize& preferredSize)
    {
        setContentSize(preferredSize);
        m_preferredSize = preferredSize;
    }
    
    inline const CCSize& getPreferredSize()
    {
        return m_preferredSize;
    }
    
    inline CCNode* getCurrentComponent()
    {
        return m_currentComponent;
    }
    
protected:
    
    virtual void updateStateComponent(State newState);
    
    virtual void updateCurrentStateComponent(State state);
    
protected:

    CCDictionary* m_states;
    
    bool m_stateDirty;
    
    //首次移动进入
    bool m_firstMoveEnter;
    
    //点击变大
    bool m_touchDownZoomable;
    
    //点击变大的大小
    float m_touchDownZoomSize;
    
    //希望的大小
    CCSize m_preferredSize;
    
    CCNode* m_currentComponent;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_CONTROL_BUTTON_H_
