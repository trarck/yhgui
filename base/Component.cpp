#include "Component.h"
#include "../event/UIEventNames.h"

NS_CC_YHGUI_BEGIN
	
Component::Component()
:m_name("")
,m_enabled(true)
,m_touchInside(false)
,m_touchPriority(0)
,m_needBubbles(true)
{
	
}
	
Component::~Component()
{
	
}

//void Component::onEnter()
//{
//    if(m_enabled){
//        this->registerWithTouchDispatcher();
//    }
//    CCNode::onEnter();
//}
//
//void Component::onExit()
//{
//    if (m_enabled) {
//        this->unregisterWithTouchDispatcher();
//    }
//    CCNode::onExit();
//}

/**
 * 消除注册的事件
 */
void Component::cleanup()
{
    UIEventListenerManager::sharedUIEventListenerManager()->removeEventListener(this);
    CCNode::cleanup();
}

void Component::setEnabled(bool enabled)
{
    if (m_enabled!=enabled) {
        m_enabled = enabled;
//        if (m_bRunning) {
//            if (m_enabled) {
//                this->registerWithTouchDispatcher();
//            }else{
//                this->unregisterWithTouchDispatcher();
//            }
//        }
    }
}

void Component::setTouchPriority(int touchPriority)
{
    m_touchPriority = touchPriority;
    CCDirector::sharedDirector()->getTouchDispatcher()->setPriority(touchPriority, this);
}

void Component::registerWithTouchDispatcher(void)
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,m_touchPriority, true);
}

void Component::unregisterWithTouchDispatcher(void)
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool Component::isTouchInside(CCTouch* touch)
{
    CCPoint touchLocation = touch->getLocation(); // Get the touch position
    touchLocation = this->getParent()->convertToNodeSpace(touchLocation);
    CCRect bBox=boundingBox();
    return bBox.containsPoint(touchLocation);
}

/**
 * 点是否在物体内
 */
bool Component::isPointInside(const CCPoint& point)
{
    CCPoint localPoint=this->convertToNodeSpace(point);
    CCSize contentSize=this->getContentSize();
    
    return localPoint.x>=0 && localPoint.x<=contentSize.width && localPoint.y>=0 &&localPoint.y<=contentSize.height;
}

bool Component::hasVisibleParents()
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

bool Component::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
//    if (!isTouchInside(pTouch) || !isEnabled() || !isVisible() || !hasVisibleParents() )
//    {
//        return false;
//    }
    
    m_touchInside=true;
    
    //touch enter
    this->trigger(kEventNameTouchMoveEnter,NULL,m_needBubbles);
    
    //touch down
    this->trigger(kEventNameTouchDown,NULL,m_needBubbles);
    
    return true;
}

void Component::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    //如果touch begin不返回true,则不会进入touch move里。所以这里已经是pressed
    bool isTouchMoveInside = isTouchInside(pTouch);
    
    if (isTouchMoveInside) {
        
        //如果已经在里面则不触发move enter。
        if (!m_touchInside) {
            m_touchInside=true;
            
            //按钮事件，不需要冒泡
            this->trigger(kEventNameTouchMoveEnter,NULL,m_needBubbles);
        }
        
    }else if(m_touchInside){
        m_touchInside=false;
        //touch exit
        this->trigger(kEventNameTouchMoveExit,NULL,m_needBubbles);
    }
    
    //touch move
    this->trigger(kEventNameTouchMove, CCBool::create(isTouchMoveInside),m_needBubbles);
}

void Component::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    if (isTouchInside(pTouch)) {
        //touch up inside
        this->trigger(kEventNameTouchUpInside,NULL,m_needBubbles);
    }else{
        //touch up outside
        this->trigger(kEventNameTouchUpOutside,NULL,m_needBubbles);
    }
}

void Component::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    
}

NS_CC_YHGUI_END