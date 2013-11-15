#ifndef COCOS_YHGUI_INTERACTIVE_INTERACTIVEDISPATCHER_H_
#define COCOS_YHGUI_INTERACTIVE_INTERACTIVEDISPATCHER_H_

#include "cocos2d.h"
#include "../YHGUIMacros.h"

NS_CC_YHGUI_BEGIN

/**
 * 处理交互事件
 * 主要接管touch事件
 */
class InteractiveDispatcher:public CCObject
{
public:
    
    InteractiveDispatcher();
    
    ~InteractiveDispatcher();

protected:
    

private:
    
    
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_INTERACTIVEDISPATCHER_H_
