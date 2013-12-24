#include "UIEventListenerManager.h"

NS_CC_YHGUI_BEGIN

static UIEventListenerManager* s_sharedUIEventListenerManager=NULL;

UIEventListenerManager* UIEventListenerManager::sharedUIEventListenerManager()
{
	if(!s_sharedUIEventListenerManager){
		s_sharedUIEventListenerManager=new UIEventListenerManager();
		s_sharedUIEventListenerManager->init();
	}
	return s_sharedUIEventListenerManager;
}


NS_CC_YHGUI_END