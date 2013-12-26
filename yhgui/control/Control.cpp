#include "Control.h"

NS_CC_YHGUI_BEGIN
	
Control::Control()
:m_state(kIdle)
,m_enabled(true)
,m_touchPriority(0)
{
	
}
	
Control::~Control()
{
	
}

bool Control::init()
{
    if (Component::init()) {
        
//        setEnabled(true);
        
        return true;
    }
    
    return false;
}

void Control::onEnter()
{
    if(m_enabled){
        this->registerWithTouchDispatcher();
    }
    Component::onEnter();
}

void Control::onExit()
{
    if (m_enabled) {
        this->unregisterWithTouchDispatcher();
    }
    Component::onExit();
}

void Control::changeState(State newState)
{
    setState(newState);
}

void Control::registerWithTouchDispatcher(void)
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,m_touchPriority, true);
}

void Control::unregisterWithTouchDispatcher(void)
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool Control::isTouchInside(CCTouch* touch)
{
    CCPoint touchLocation = touch->getLocation(); // Get the touch position
    touchLocation = this->getParent()->convertToNodeSpace(touchLocation);
    CCRect bBox=boundingBox();
    return bBox.containsPoint(touchLocation);
}

bool Control::hasVisibleParents()
{
    CCNode* pParent = this->getParent();
    for( CCNode *c = pParent; c != NULL; c = c->getParent() )
    {
        if( !c->isVisible() )
        {
            return false;
        }
    }
    return true;
}

void Control::setEnabled(bool enabled)
{
    if (m_enabled!=enabled) {
        m_enabled = enabled;
        if (m_bRunning) {
            if (m_enabled) {
                this->registerWithTouchDispatcher();
            }else{
                this->unregisterWithTouchDispatcher();
            }
        }
    }
}

void Control::setTouchPriority(int touchPriority)
{
    m_touchPriority = touchPriority;
    CCDirector::sharedDirector()->getTouchDispatcher()->setPriority(touchPriority, this);
}

NS_CC_YHGUI_END