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