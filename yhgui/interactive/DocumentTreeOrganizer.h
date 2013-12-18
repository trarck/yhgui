#ifndef COCOS_YHGUI_INTERACTIVE_DOCUMENTTREEORGANIZER_H_
#define COCOS_YHGUI_INTERACTIVE_DOCUMENTTREEORGANIZER_H_

#include "Organizer.h"

NS_CC_YHGUI_BEGIN

/**
 * 处理交互事件
 * 分享处理touch事件
 * 只有有对标时才占用此次点击，没有目标则不占用.如果目标不处理，则不会继续触发touch move事件。
 * 分享性能好，默认使用
 */
class DocumentTreeOrganizer:public Organizer
{
public:
    
    DocumentTreeOrganizer();
    
    ~DocumentTreeOrganizer();
    
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
    
    inline void setDocument(Component* document)
    {
        CC_SAFE_RETAIN(document);
        CC_SAFE_RELEASE(m_document);
        m_document = document;
    }
    
    inline Component* getDocument()
    {
        return m_document;
    }

protected:
    
    Component* m_document;

};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_DOCUMENTTREEORGANIZER_H_
