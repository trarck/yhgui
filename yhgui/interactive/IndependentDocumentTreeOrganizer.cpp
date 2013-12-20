#include "IndependentDocumentTreeOrganizer.h"
//#include "IndependentTouchDefine.h"

NS_CC_YHGUI_BEGIN

//如果在头文件中定义了，则这个文件可以不要

//==================交互事件=====================//

/**
 * 独占
 */
CREATE_INDEPENDENT_TOUCH_DEFINE_WITH_CLASS(IndependentDocumentTreeOrganizer)

//
//bool IndependentDocumentTreeOrganizer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
//{
//    CCPoint touchLocation = pTouch->getLocation();
//    Component* target=getTargetContainPoint(touchLocation);
//    if (target) {
//        setTarget(target);
//        //trigger elem events
//        target->ccTouchBegan(pTouch, pEvent);
//    }
//    
//    return true;
//}
//
//void IndependentDocumentTreeOrganizer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
//{
//    if(m_target){
//        m_target->ccTouchMoved(pTouch, pEvent);
//    }else{
//        CCPoint touchLocation = pTouch->getLocation();
//        Component* target=getTargetContainPoint(touchLocation);
//        if(target) target->ccTouchMoved(pTouch, pEvent);
//    }
//}
//
//void IndependentDocumentTreeOrganizer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
//{
//    if (m_target) {
//        m_target->ccTouchEnded(pTouch, pEvent);
//        //处理完成，把目录设置为空
//        setTarget(NULL);
//    }
//}
//
//void IndependentDocumentTreeOrganizer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
//{
//    if (m_target) {
//        m_target->ccTouchCancelled(pTouch, pEvent);
//        setTarget(NULL);
//    }
//}
NS_CC_YHGUI_END