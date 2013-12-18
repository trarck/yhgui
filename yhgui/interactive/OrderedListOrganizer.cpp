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
    if (m_elementsAncestors.find(component->m_uID)!=m_elementsAncestors.end()){
        m_elementsAncestors.erase(component->m_uID);
        
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
    //由于已经排好序，直接取最上面的元素
    return m_elements->count()>0?static_cast<Component*>(m_elements->objectAtIndex(0)):NULL;
}

NS_CC_YHGUI_END