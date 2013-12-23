#ifndef COCOS_YHGUI_INTERACTIVE_PRIORITYORGANIZER_H_
#define COCOS_YHGUI_INTERACTIVE_PRIORITYORGANIZER_H_

#include "Organizer.h"

NS_CC_YHGUI_BEGIN

/**
 * 处理交互事件
 * 主要接管touch事件
 * 当点击事件发生时排列需要交互的元素。即记录需要交互的元素的队列是无序的
 */
class PriorityOrganizer:public Organizer
{
public:
    
    PriorityOrganizer();
    
    ~PriorityOrganizer();
    
    bool init();

    /**
     * 添加一个组件
     */
    virtual void addComponent(Component* component);
    
    /**
     * 删除一个组件
     */
    virtual void removeComponent(Component* component);
    
//    //==================交互事件=====================//
//    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
//    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
//    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
//    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    /**
     * 取得最上层元素包含要触摸点
     */
    virtual Component* getTargetContainPoint(const CCPoint& point);
    
protected:
    
    /**
     * 需要进行交互处理的元素
     */
    CCArray* m_elements;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_PRIORITYORGANIZER_H_
