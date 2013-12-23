#include "PriorityOrganizer.h"

NS_CC_YHGUI_BEGIN
	
PriorityOrganizer::PriorityOrganizer()
:m_elements(NULL)
{
	
}
	
PriorityOrganizer::~PriorityOrganizer()
{
	CC_SAFE_RELEASE_NULL(m_elements);
}

bool PriorityOrganizer::init()
{
    if (Organizer::init()) {
        m_elements=new CCArray();
        m_elements->init();
        return true;
    }
    
    return false;
}

/**
 * 添加一个组件
 * priority越小越先被执行,和cocos的touch dispatcher保持一致
 * 采用倒序放置元素。即大的在前面，小的在后面，相同的后添加的放后面。
 */
void PriorityOrganizer::addComponent(Component* component)
{
    CCObject* pObj=NULL;
    Component* elem=NULL;
    
    int i=0;
    
    CCARRAY_FOREACH(m_elements, pObj)
    {
        elem=static_cast<Component*>(pObj);
        if (component->getTouchPriority()>elem->getTouchPriority()) {
            break;
        }
        ++i;
    }
    
    m_elements->insertObject(component, i);
}

/**
 * 删除一个组件
 */
void PriorityOrganizer::removeComponent(Component* component)
{
    m_elements->removeObject(component);
}

/**
 * 取得最上层元素包含要触摸点
 */
Component* PriorityOrganizer::getTargetContainPoint(const CCPoint& point)
{
    //由于已经排好序，从最后向前比较
    
    CCObject* pObj=NULL;
    Component* elem=NULL;
    CCARRAY_FOREACH_REVERSE(m_elements, pObj){
        elem=static_cast<Component*>(pObj);
        //检查是否可见。不可见则不接收事件
        if (elem && elem->isVisible()) {
            //如果组件不可用，则接收事件,但不处理。
            if (elem->isPointInside(point)){
                return elem;
            }
        }
    }
    
    return NULL;
}

NS_CC_YHGUI_END