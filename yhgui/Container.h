#ifndef COCOS_YHGUI_CONTAINER_H_
#define COCOS_YHGUI_CONTAINER_H_

#include "Component.h"

NS_CC_YHGUI_BEGIN
	
class Container:public Component
{
public:
    
    Container();
    
    ~Container();

    /**
     * 根据名称获取一个子元素。如果有多个只取第一个
     */
	Component* getChildByName(const std::string& name);
	
    /**
     * 根据名称获取子元素。
     */
    CCArray* getChildrenByName(const std::string& name);
    
    /**
     * 根据名称获取一个后代元素。如果有多个只取第一个
     */
	Component* getDescendantByName(const std::string& name);
	
    /**
     * 根据名称获取后代元素。
     */
    CCArray* getDescendantsByName(const std::string& name);

    CREATE_FUNC(Container);
    
protected:
    
    
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_CONTAINER_H_
