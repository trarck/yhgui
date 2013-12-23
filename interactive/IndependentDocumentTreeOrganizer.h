#ifndef COCOS_YHGUI_INTERACTIVE_INDEPENDENTDOCUMENTTREEORGANIZER_H_
#define COCOS_YHGUI_INTERACTIVE_INDEPENDENTDOCUMENTTREEORGANIZER_H_

#include "DocumentTreeOrganizer.h"
#include "IndependentTouchDefine.h"

NS_CC_YHGUI_BEGIN

/**
 * 处理交互事件
 * 独占处理touch事件
 * 无论有没有目标都占用,这样可以继续处理touch move事件
 */
class IndependentDocumentTreeOrganizer:public DocumentTreeOrganizer
{
public:
    
    //==================交互事件=====================//
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
//    //==================交互事件=====================//
//    
//    /**
//     * 独占
//     */
//    CREATE_INDEPENDENT_TOUCH_DEFINE
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_INDEPENDENTDOCUMENTTREEORGANIZER_H_
