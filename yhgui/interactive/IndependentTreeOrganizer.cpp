#include "IndependentTreeOrganizer.h"

NS_CC_YHGUI_BEGIN
	
IndependentTreeOrganizer::IndependentTreeOrganizer()
{
	
}
	
IndependentTreeOrganizer::~IndependentTreeOrganizer()
{
	CC_SAFE_RELEASE_NULL(m_root);
    CC_SAFE_RELEASE_NULL(m_target);
}

//==================交互事件=====================//

/**
 * 独占
 */
bool IndependentTreeOrganizer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint touchLocation = pTouch->getLocation();
    Component* target=getTargetContainPoint(touchLocation);
    if (target) {
        setTarget(target);
        //trigger elem events
        target->ccTouchBegan(pTouch, pEvent);
    }
    
    return true;
}

void IndependentTreeOrganizer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    //只有有了target才会到此步，所以不需要判断target在不在
    if(m_target){
        m_target->ccTouchMoved(pTouch, pEvent);
    }else{
        CCPoint touchLocation = pTouch->getLocation();
        Component* target=getTargetContainPoint(touchLocation);
        if(target) target->ccTouchMoved(pTouch, pEvent);
    }
}

void IndependentTreeOrganizer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    if (m_target) {
        m_target->ccTouchEnded(pTouch, pEvent);
        //处理完成，把目录设置为空
        setTarget(NULL);
    }
}

void IndependentTreeOrganizer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    if (m_target) {
        m_target->ccTouchCancelled(pTouch, pEvent);
        setTarget(NULL);
    }
}
NS_CC_YHGUI_END