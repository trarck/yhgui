#ifndef COCOS_YHGUI_INTERACTIVE_LISTORGANIZER_H_
#define COCOS_YHGUI_INTERACTIVE_LISTORGANIZER_H_

#include "Organizer.h"

NS_CC_YHGUI_BEGIN

/**
 * 处理交互事件
 * 使用无序的列表处理事件
 * 主要接管touch事件
 * 当点击事件发生时排列需要交互的元素。即记录需要交互的元素的队列是无序的
 */
class ListOrganizer:public Organizer
{
public:
    
    ListOrganizer();
    
    ~ListOrganizer();
    
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
    
    /**
     * 创建从元素到最顶层元素的的列表
     */
    std::vector<CCNode*> createAncestorList(CCNode* element);
    
    /**
     * 按祖先的关系获取是上面的元素
     */
    CCNode* getTopElementWithAncestor(std::vector<std::vector<CCNode*> >& elementList);
    
    /**
     * 按祖先的关系排序元素
     */
    void sortElementsWithAncestor(std::vector<std::vector<CCNode*> >& elementList);
    
    /**
     * 比较二个元素的层级大小
     */
    int compareElementZOrderWithAncestor(const std::vector<CCNode*>& src,const std::vector<CCNode*>& dest);
    
    /**
     * 比较二个元素的层级大小
     */
    int compareElementZOrder(CCNode* src,CCNode* dest);
    
protected:
    
    /**
     * 检查其祖先元素是否可以接收事件。
     * 每个先祖先素都可见。
     * 最上层祖先要在渲染树上。即m_bRunning为true。不用判断所有祖先，判断最上层就行
     */
    bool checkAncestorTouchable(CCNode* elem);
    
protected:
    
    /**
     * 需要进行交互处理的元素
     */
    CCArray* m_elements;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_LISTORGANIZER_H_
