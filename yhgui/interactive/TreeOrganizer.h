#ifndef COCOS_YHGUI_INTERACTIVE_TREEORGANIZER_H_
#define COCOS_YHGUI_INTERACTIVE_TREEORGANIZER_H_

#include "Organizer.h"
#include "../Component.h"

NS_CC_YHGUI_BEGIN

/**
 * 处理交互事件
 * 分享处理touch事件
 * 只有有对标时才占用此次点击，没有目标则不占用.
 * 分享性能好，默认使用
 */
class TreeOrganizer:public Organizer
{
public:
    
    TreeOrganizer();
    
    ~TreeOrganizer();
    
    //==================交互事件=====================//
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

protected:
    
    /**
     * 取得最上层元素包含要触摸点
     */
    Component* getTargetContainPoint(const CCPoint& point);

public:
    
    inline void setRoot(Component* root)
    {
        CC_SAFE_RETAIN(root);
        CC_SAFE_RELEASE(m_root);
        m_root = root;
    }
    
    inline Component* getRoot()
    {
        return m_root;
    }
    
    inline void setTarget(Component* target)
    {
        CC_SAFE_RETAIN(target);
        CC_SAFE_RELEASE(m_target);
        m_target = target;
    }
    
    inline Component* getTarget()
    {
        return m_target;
    }

protected:
    
    Component* m_root;
    
    Component* m_target;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_TREEORGANIZER_H_
