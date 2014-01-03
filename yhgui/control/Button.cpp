#include "Button.h"
#include "../event/UIEventNames.h"

NS_CC_YHGUI_BEGIN


Button::Button()
:m_states(NULL)
,m_stateDirty(false)
,m_firstMoveEnter(false)
{
    //不需要冒泡事件
    m_needBubbles=false;
}
	
Button::~Button()
{
	CC_SAFE_RELEASE_NULL(m_states);
}

bool Button::init()
{
    if (Control::init()) {
        
        m_states=new CCDictionary();
        
        return true;
    }
    return false;
}

bool Button::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    bool result=Control::ccTouchBegan(pTouch, pEvent);
	if (result)
	{
		 //处理touch事件
		changeState(kPressed);
	}
    return result;
}

void Button::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    Control::ccTouchMoved(pTouch, pEvent);
    
    //如果touch begin不返回true,则不会进入touch move里。所以这里已经是pressed
    //由于调用了父类的方法，所以直接使用m_touchInside和用方法isTouchInside返回的结果一致，减少方法调用
    if (m_touchInside) {
        if (m_state!=kPressed) {
            this->changeState(kPressed);
        }
    }else {
        if(m_state!=kNormal){
            
            this->changeState(kNormal);
        }
    }
}

void Button::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    Control::ccTouchEnded(pTouch, pEvent);
    
    if (m_state!=kNormal) {
        changeState(kNormal);
    }
}

void Button::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    Control::ccTouchCancelled(pTouch, pEvent);
    
    if (m_state!=kNormal) {
        changeState(kNormal);
    }
}

void Button::changeState(State newState)
{
    if (m_state!=newState) {
        CCLOG("changeState:from %d to %d",m_state,newState);
        m_stateDirty=true;
        changeStateComponent(newState);
        setState(newState);
    }
}

void Button::setStateComponent(State state,CCNode* component)
{
    m_states->setObject(component, state);
}

void Button::changeStateComponent(State newState)
{
    if (!m_stateDirty) {
        return;
    }
    
    m_stateDirty=false;
    
    CCNode* newComponent=static_cast<CCNode*>(m_states->objectForKey(newState));
    
    //no new component do nothing
    if (!newComponent) {
        return ;
    }
    
    
    CCNode* currentComponent=static_cast<CCNode*>(m_states->objectForKey(m_state));

    //remove current state component
    currentComponent->removeFromParentAndCleanup(false);
    
    //add new state component
    this->addChild(newComponent);
    
}

NS_CC_YHGUI_END