#include "DocumentTreeOrganizer.h"

NS_CC_YHGUI_BEGIN
	
DocumentTreeOrganizer::DocumentTreeOrganizer()
:m_document(NULL)
{
	
}
	
DocumentTreeOrganizer::~DocumentTreeOrganizer()
{
	CC_SAFE_RELEASE_NULL(m_document);
}

////==================交互事件=====================//
//
///**
// * 分享
// */
//bool DocumentTreeOrganizer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
//{
//    CCPoint touchLocation = pTouch->getLocation();
//    Component* target=getTargetContainPoint(touchLocation);
//    if (target && target->isEnabled()) {
//        //只有可用组件才可以处理事件
//        setTarget(target);
//        //trigger elem events
//        return target->ccTouchBegan(pTouch, pEvent);
//    }
//    
//    return false;
//}
//
//void DocumentTreeOrganizer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
//{
//    //只有有了target才会到此步，所以不需要判断target在不在
//    m_target->ccTouchMoved(pTouch, pEvent);
//}
//
//void DocumentTreeOrganizer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
//{
//    m_target->ccTouchEnded(pTouch, pEvent);
//    //处理完成，把目录设置为空
//    setTarget(NULL);
//}
//
//void DocumentTreeOrganizer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
//{
//    if (m_target) {
//        m_target->ccTouchCancelled(pTouch, pEvent);
//        setTarget(NULL);
//    }
//}

/**
 * 取得最上层元素包含要触摸点
 *TODO:给组件定义一个属性，如果组件不可用，则不接收事件(该组件件的子组件也不接收事件，java中叫重量级组件)
 java 文档关于Enabled的描述
 注：禁用轻量级组件不会阻止其接收 MouseEvents。
 注：禁用重量级容器可以阻止此容器中的所有组件接收任何输入事件。但是禁用轻量级容器只影响此容器。
 */
Component* DocumentTreeOrganizer::getTargetContainPoint(const CCPoint& point)
{
//    struct timeval start;
//    struct timeval end;
//    
//    gettimeofday(&start, NULL);
    
    if (!m_document) return NULL;
    
    Component* elem=NULL;
    
    CCArray* elements=CCArray::create();
    elements->addObject(m_document);
    
//    elements->addObjectsFromArray(m_root->getChildren());
    
    CCPoint modelPoint;
    CCSize elemSize;
    CCArray* children=NULL;
    CCObject* pObj=NULL;
    
    CCArray* opens=CCArray::create();
    
    while ((pObj=elements->lastObject())) {
        //防止不是Component被加进去
        elem=dynamic_cast<Component*>(pObj);
        
        //检查是否可见。不可见则不接收事件
        if (elem && elem->isVisible()) {
            
            //判断是否在开启列表中，如果是，则表示子类已经处理完成，现在比较自己
            if (opens->lastObject()==pObj) {
                //从开启列表中删除
                opens->fastRemoveObjectAtIndex(opens->data->num-1);
            }else if(elem->isNeedDispatchToChildrenWhenCapthure()){
                //处理子元素
                children=elem->getChildren();
                if (children && children->count()) {
                    elements->addObjectsFromArray(children);
                    opens->addObject(pObj);
                    //如果有子元素，先处理子元素。
                    continue;
                }
            }

            //如果组件不可用，则接收事件,但不处理。        
            if (elem->isPointInside(point)){
//                gettimeofday(&end, NULL);
//                CCLOG("getTargetContainPoint:%d",(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec));
                return elem;
            }
            
            //if (elem->isPointInside(point)){
            //    return elem;
            //}
        }
        
        elements->fastRemoveObjectAtIndex(elements->data->num-1);
    }
    
//    gettimeofday(&end, NULL);
//    CCLOG("getTargetContainPoint:%d",(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec));
    
    return NULL;
}

NS_CC_YHGUI_END