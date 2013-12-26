#include "Component.h"

NS_CC_YHGUI_BEGIN
	
Component::Component()
:m_name("")
{
	
}
	
Component::~Component()
{
	
}

/**
 * 消除注册的事件
 */
void Component::cleanup()
{
    UIEventListenerManager::sharedUIEventListenerManager()->removeEventListener(this);
    CCNode::cleanup();
}

NS_CC_YHGUI_END