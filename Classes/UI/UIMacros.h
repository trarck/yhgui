#ifndef YH_UI_MACROS_H_
#define YH_UI_MACROS_H_

#ifdef __cplusplus
	#define NS_YH_UI_BEGIN                     namespace yh {namespace ui{
	#define NS_YH_UI_END                       }}
	#define USING_NS_YH_UI                     using namespace yh::ui
#else
    #define NS_YH_UI_BEGIN 
    #define NS_YH_UI_END 
    #define USING_NS_YH_UI
#endif 

#endif //YH_UI_MACROS_H_