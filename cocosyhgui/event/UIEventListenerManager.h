#ifndef COCOS_YHGUI_UIEVENTLISTENERMANAGER_H_
#define COCOS_YHGUI_UIEVENTLISTENERMANAGER_H_

#include "cocos2d.h"
#include "../YHGUIMacros.h"
#include "Event/EventListenerManager.h"

NS_CC_YHGUI_BEGIN
	
class UIEventListenerManager:public yhlib::EventListenerManager
{
//∑Ω∑®
public:
    
	static UIEventListenerManager* sharedUIEventListenerManager();
    
// Ù–‘
protected:
    
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_UIEVENTLISTENERMANAGER_H_
