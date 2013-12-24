#ifndef COCOS_YHGUI_YHGUIMACROS_H_
#define COCOS_YHGUI_YHGUIMACROS_H_

#ifdef __cplusplus
    #define NS_CC_YHGUI_BEGIN                     namespace cocos2d { namespace yhgui {
    #define NS_CC_YHGUI_END                       }}
    #define USING_NS_CC_YHGUI                     using namespace cocos2d::yhgui
#else
    #define NS_CC_YHGUI_BEGIN 
    #define NS_CC_YHGUI_END 
    #define USING_NS_CC_YHGUI
#endif 

#endif //COCOS_YHGUI_YHGUIMACROS_H_