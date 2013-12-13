#ifndef COCOS_YHGUI_INTERACTIVE_INDEPENDENTDOCUMENTTREEORGANIZER_H_
#define COCOS_YHGUI_INTERACTIVE_INDEPENDENTDOCUMENTTREEORGANIZER_H_

#include "DocumentTreeOrganizer.h"

NS_CC_YHGUI_BEGIN

/**
 * 处理交互事件
 * 独占处理touch事件
 * 无论有没有目标都占用
 */
class IndependentDocumentTreeOrganizer:public DocumentTreeOrganizer
{
public:
    
    IndependentDocumentTreeOrganizer();
    
    ~IndependentDocumentTreeOrganizer();
    
    //==================交互事件=====================//
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_INDEPENDENTDOCUMENTTREEORGANIZER_H_
