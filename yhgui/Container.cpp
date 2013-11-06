#include "Container.h"

NS_CC_YHGUI_BEGIN
	
Container::Container()
{
	
}
	
Container::~Container()
{
	
}

/**
 * 根据名称获取一个子元素。如果有多个只取第一个
 */
Component* Container::getChildByName(const std::string& name)
{
    Component* child=NULL;
    for (int i=0,l=m_pChildren->count(); i<l; ++i) {
        child=static_cast<Component*>(m_pChildren->objectAtIndex(i));
        if (strcmp(child->getName().c_str(), name.c_str())==0){
            return child;
        }
    }
    return NULL;
}

/**
 * 根据名称获取子元素。
 */
CCArray* Container::getChildrenByName(const std::string& name)
{
    CCArray* children=CCArray::create();
    
    Component* child=NULL;
    for (int i=0,l=m_pChildren->count(); i<l; ++i) {
        child=static_cast<Component*>(m_pChildren->objectAtIndex(i));
        if (strcmp(child->getName().c_str(), name.c_str())==0){
            children->addObject(child);
        }
    }
    return children;
}

/**
 * 根据名称获取一个后代元素。如果有多个只取第一个
 */
Component* Container::getDescendantByName(const std::string& name)
{
    Component* child=NULL;
    
    CCArray* elements=CCArray::create();
    
    elements->addObjectsFromArray(m_pChildren);
    
    int i=0;
    for (; i<elements->count(); ++i) {
        child=static_cast<Component*>(elements->objectAtIndex(i));
        if (strcmp(child->getName().c_str(), name.c_str())==0){
            break;
        }
        
        if (child->getChildren()) {
            elements->addObjectsFromArray(child->getChildren());
        }
    }
    
    return i < elements->count() ? child:NULL;
}

/**
 * 根据名称获取后代元素。
 */
CCArray* Container::getDescendantsByName(const std::string& name)
{
    CCArray* children=CCArray::create();
    
    Component* child=NULL;
    
    CCArray* elements=CCArray::create();
    
    elements->addObjectsFromArray(m_pChildren);
    
    for (int i=0; i<elements->count(); ++i) {
        child=static_cast<Component*>(elements->objectAtIndex(i));
        if (strcmp(child->getName().c_str(), name.c_str())==0){
            children->addObject(child);
        }
        
        if (child->getChildren()) {
            elements->addObjectsFromArray(child->getChildren());
        }
    }
    
    return children;
}

NS_CC_YHGUI_END