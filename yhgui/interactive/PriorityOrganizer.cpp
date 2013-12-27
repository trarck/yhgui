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
        if (elem && elem->isVisible() && this->checkAncestorTouchable(elem)) {
            //如果组件不可用，则接收事件,但不处理。
            if (elem->isPointInside(point)){
                return elem;
            }
        }
    }
    
    return NULL;
}

/**
 * 检查其祖先元素是否可以接收事件。
 * 每个先祖先素都可见。
 * 最上层祖先要在渲染树上。即m_bRunning为true。不用判断所有祖先，判断最上层就行
 */
bool PriorityOrganizer::checkAncestorTouchable(CCNode* elem)
{
    CCNode* pParent = elem->getParent();
    
    if (!pParent) {
        //如果没有父元素(最上层元素或没有加入渲染对)。
        return elem->isRunning();
    }
    
    for( CCNode *c = pParent; c != NULL; c = c->getParent() )
    {
        if( !c->isVisible())// ||!c->isRunning()
        {
            return false;
        }
        pParent=c;
    }
    
    //检查最上层元素是否在渲染树。
    
    return pParent->isRunning();
}

NS_CC_YHGUI_END