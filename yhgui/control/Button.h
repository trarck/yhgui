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

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    virtual void changeState(State newState);
    
    void setStateComponent(State state,CCNode* component);

protected:
    
    virtual void changeStateComponent(State newState);
    
protected:

    CCDictionary* m_states;
    
    bool m_stateDirty;
    
    //首次移动进入
    bool m_firstMoveEnter;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_CONTROL_BUTTON_H_
