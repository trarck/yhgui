#include "Button.h"

NS_CC_YHGUI_BEGIN

static const char* kEventNameTouchDown="touchDown";
//static const char* kEventNameTouchMoveInside="touchMoveInside";
//static const char* kEventNameTouchMoveOutside="touchMoveOutside";
static const char* kEventNameTouchMove="touchMove";
static const char* kEventNameTouchMoveEnter="touchMoveEnter";
static const char* kEventNameTouchMoveExit="touchMoveExit";
static const char* kEventNameTouchUpInside="touchUpInside";
static const char* kEventNameTouchUpOutside="touchUpOutside";

Button::Button()
:m_states(NULL)
,m_stateDirty(false)
,m_firstMoveEnter(false)
{
	
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
    if (!isTouchInside(pTouch) || !isEnabled() || !isVisible() || !hasVisibleParents() )
    {
        return false;
    }
    
    //处理touch事件
    changeState(kPressed);
    
    //按钮事件，不需要冒泡
    this->trigger(kEventNameTouchDown,NULL,false);
    
    m_firstMoveEnter=true;
    
    return true;
}

void Button::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    //如果touch begin不返回true,则不会进入touch move里。所以这里已经是pressed
    bool isTouchMoveInside = isTouchInside(pTouch);

    if (isTouchMoveInside) {
        //在controll中移动
        
        //如果还没有触发过move enter，则触发一次，仅触发一次。
        if (m_firstMoveEnter) {
            m_firstMoveEnter=false;
            
            //按钮事件，不需要冒泡
            this->trigger(kEventNameTouchMoveEnter,NULL,false);
            
        }else if (m_state!=kPressed) {
            this->changeState(kPressed);
            
            //按钮事件，不需要冒泡
            this->trigger(kEventNameTouchMoveEnter,NULL,false);
        }
        
    }else {
        if(m_state!=kNormal){
            if (m_firstMoveEnter) m_firstMoveEnter=false;
            
            this->changeState(kNormal);
            
            //按钮事件，不需要冒泡
            this->trigger(kEventNameTouchMoveExit,NULL,false);
        }
    }
    
    //按钮事件，不需要冒泡
    this->trigger(kEventNameTouchMove, CCBool::create(isTouchMoveInside),false);
    
}

void Button::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    if (m_state!=kNormal) {
        changeState(kNormal);
    }
    
    if (isTouchInside(pTouch)) {
        //按钮事件，不需要冒泡
        this->trigger(kEventNameTouchUpInside,NULL,false);
    }else{
        //按钮事件，不需要冒泡
        this->trigger(kEventNameTouchUpOutside,NULL,false);
    }
}

void Button::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    if (m_state!=kNormal) {
        changeState(kNormal);
    }
}

void Button::changeState(State newState)
{
    if (m_state!=newState) {
        setState(newState);
        m_stateDirty=true;
        changeStateComponent(newState);
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