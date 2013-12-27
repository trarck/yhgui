#include "OrderedListOrganizer.h"

NS_CC_YHGUI_BEGIN
	
OrderedListOrganizer::OrderedListOrganizer()
{
	
}
	
OrderedListOrganizer::~OrderedListOrganizer()
{

}

/**
 * 添加一个组件
 */
void OrderedListOrganizer::addComponent(Component* component)
{
    //会自动替换，不用删除
//    if (m_elementsAncestors.find(component->m_uID)!=m_elementsAncestors.end()){
//        m_elementsAncestors.erase(component->m_uID);
//    }
    
    //检查是不是已经添加过，如果已经添加过，则删除旧的重新添加一次
    int index=m_elements->indexOfObject(component);
    if (index!=CC_INVALID_INDEX) {
        m_elements->removeObjectAtIndex(index);
    }
    
    std::vector<CCNode*> componentAncestor=this->createAncestorList(component);
    
    m_elementsAncestors[component->m_uID]=componentAncestor;
    
    CCObject* pObj=NULL;
    Component* elem=NULL;
    int pos=-1,i=0;
    CCARRAY_FOREACH(m_elements, pObj){
        elem=static_cast<Component*>(pObj);
        if (this->compareElementZOrderWithAncestor(componentAncestor,m_elementsAncestors[elem->m_uID])>=0){
            pos=i;
            break;
        }
        ++i;
    }
    
    if (pos==-1) {
        m_elements->addObject(component);
    }else{
        m_elements->insertObject(component, pos);
    }
   
}

/**
 * 删除一个组件
 */
void OrderedListOrganizer::removeComponent(Component* component)
{
    m_elements->removeObject(component);
    m_elementsAncestors.erase(component->m_uID);
}

/**
 * 取得最上层元素包含要触摸点
 * 一直比较到最上层的元素
 * 二种方式：
 * 1.先处理是否在点击范围内，再进行排序处理。
 * 2.先进行排序，再测试是否在点击范围内。
 */
Component* OrderedListOrganizer::getTargetContainPoint(const CCPoint& point)
{
    //由于已经排好序，直接从上向下比较元素
    
    CCObject* pObj=NULL;
    Component* elem=NULL;
    CCARRAY_FOREACH(m_elements, pObj){
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

NS_CC_YHGUI_END