#ifndef COCOS_YHGUI_INTERACTIVE_ORDEREDLISTORGANIZER_H_
#define COCOS_YHGUI_INTERACTIVE_ORDEREDLISTORGANIZER_H_

#include "ListOrganizer.h"

NS_CC_YHGUI_BEGIN

/**
 * 处理交互事件
 * 使用有序列表处理事件
 * 主要接管touch事件
 * 保证需要处理的元素队列是有序的。先处理的元素在最前面，即倒序。
 */
class OrderedListOrganizer:public ListOrganizer
{
public:
    
    OrderedListOrganizer();
    
    ~OrderedListOrganizer();
    
    /**
     * 添加一个组件
     */
    void addComponent(Component* component);
    
    /**
     * 删除一个组件
     */
    void removeComponent(Component* component);
    
    /**
     * 取得最上层元素包含要触摸点
     */
    Component* getTargetContainPoint(const CCPoint& point);
    
protected:
    
    std::map<int, std::vector<CCNode*> > m_elementsAncestors;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_ORDEREDLISTORGANIZER_H_
