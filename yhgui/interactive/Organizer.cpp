#include "Organizer.h"

NS_CC_YHGUI_BEGIN

Organizer::Organizer()
:m_interactivePriority(0)
,m_registeredTouchDispatcher(false)
,m_target(NULL)
{
	
}

Organizer::~Organizer()
{
	CC_SAFE_RELEASE_NULL(m_target);
}

bool Organizer::init()
{
    return true;
}

/**
 * 注册一个touch dispatcher。
 */
void Organizer::registerWithTouchDispatcher(void)
{
    if (!m_registeredTouchDispatcher) {
        m_registeredTouchDispatcher=true;
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,m_interactivePriority, true);
    }
}

/**
 * 取消注册一个touch dispatcher。
 */
void Organizer::unregisterWithTouchDispatcher(void)
{
    if (m_registeredTouchDispatcher) {
        m_registeredTouchDispatcher=false;
        CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
    }
}

//==================交互事件=====================//
bool Organizer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint touchLocation = pTouch->getLocation();
    //    struct timeval start;
    //    struct timeval end;
    //
    //    gettimeofday(&start, NULL);
    
    Component* target=getTargetContainPoint(touchLocation);
    
    //    gettimeofday(&end, NULL);
    //
    //    CCLOG("use:%ld",(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec));
    
    if (target && target->isEnabled()) {
        //只有可用组件才可以处理事件
        setTarget(target);
        //trigger elem events
        return target->ccTouchBegan(pTouch, pEvent);
    }
    
    return false;
}

void Organizer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    //只有有了target才会到此步，所以不需要判断target在不在
    m_target->ccTouchMoved(pTouch, pEvent);
}

void Organizer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    m_target->ccTouchEnded(pTouch, pEvent);
    //处理完成，把目录设置为空
    setTarget(NULL);
}

void Organizer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    if (m_target) {
        m_target->ccTouchCancelled(pTouch, pEvent);
        setTarget(NULL);
    }
}

/**
 * 取得最上层元素包含要触摸点
 * 一直比较到最上层的元素
 * 二种方式：
 * 1.先处理是否在点击范围内，再进行排序处理。
 * 2.先进行排序，再测试是否在点击范围内。
 */
Component* Organizer::getTargetContainPoint(const CCPoint& point)
{
    return NULL;
}

/**
 * 设置交互优先值
 */
void Organizer::setInteractivePriority(int interactivePriority)
{
    if (m_interactivePriority!=interactivePriority) {
        m_interactivePriority = interactivePriority;
        if (m_registeredTouchDispatcher) {
            CCDirector::sharedDirector()->getTouchDispatcher()->setPriority(m_interactivePriority, this);
        }
    }
}

NS_CC_YHGUI_END