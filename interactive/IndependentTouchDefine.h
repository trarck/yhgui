#ifndef COCOS_YHGUI_INTERACTIVE_INDEPENDENTTOUCHDEFINE_H_
#define COCOS_YHGUI_INTERACTIVE_INDEPENDENTTOUCHDEFINE_H_

#define CREATE_INDEPENDENT_TOUCH_DEFINE                                                     \
bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)                                         \
{                                                                                           \
    CCPoint touchLocation = pTouch->getLocation();                                          \
    Component* target=getTargetContainPoint(touchLocation);                                 \
    if (target) {                                                                           \
        setTarget(target);                                                                  \
        target->ccTouchBegan(pTouch, pEvent);                                               \
    }                                                                                       \
                                                                                            \
    return true;                                                                            \
}                                                                                           \
                                                                                            \
void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)                                         \
{                                                                                           \
    if(m_target){                                                                           \
        m_target->ccTouchMoved(pTouch, pEvent);                                             \
    }else{                                                                                  \
        CCPoint touchLocation = pTouch->getLocation();                                      \
        Component* target=getTargetContainPoint(touchLocation);                             \
        if(target) target->ccTouchMoved(pTouch, pEvent);                                    \
    }                                                                                       \
}                                                                                           \
                                                                                            \
void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)                                  \
{                                                                                           \
    if (m_target) {                                                                         \
        m_target->ccTouchEnded(pTouch, pEvent);                                             \
        /*处理完成，把目录设置为空*/                                                            \
        setTarget(NULL);                                                                    \
    }                                                                                       \
}                                                                                           \
                                                                                            \
void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)                              \
{                                                                                           \
    if (m_target) {                                                                         \
        m_target->ccTouchCancelled(pTouch, pEvent);                                         \
        setTarget(NULL);                                                                    \
    }                                                                                       \
}


#define CREATE_INDEPENDENT_TOUCH_DEFINE_WITH_CLASS(Class)                                   \
bool Class::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)                                  \
{                                                                                           \
    CCPoint touchLocation = pTouch->getLocation();                                          \
    Component* target=getTargetContainPoint(touchLocation);                                 \
    if (target) {                                                                           \
        setTarget(target);                                                                  \
        target->ccTouchBegan(pTouch, pEvent);                                               \
    }                                                                                       \
                                                                                        \
    return true;                                                                            \
}                                                                                           \
                                                                                        \
void Class::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)                                  \
{                                                                                           \
    if(m_target){                                                                           \
        m_target->ccTouchMoved(pTouch, pEvent);                                             \
    }else{                                                                                  \
        CCPoint touchLocation = pTouch->getLocation();                                      \
        Component* target=getTargetContainPoint(touchLocation);                             \
        if(target) target->ccTouchMoved(pTouch, pEvent);                                    \
    }                                                                                       \
}                                                                                           \
                                                                                            \
void Class::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)                                  \
{                                                                                           \
    if (m_target) {                                                                         \
        m_target->ccTouchEnded(pTouch, pEvent);                                             \
        /*处理完成，把目录设置为空*/                                                            \
        setTarget(NULL);                                                                    \
    }                                                                                       \
}                                                                                           \
                                                                                            \
void Class::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)                              \
{                                                                                           \
    if (m_target) {                                                                         \
        m_target->ccTouchCancelled(pTouch, pEvent);                                         \
        setTarget(NULL);                                                                    \
    }                                                                                       \
}

#endif //COCOS_YHGUI_INTERACTIVE_INDEPENDENTTOUCHDEFINE_H_