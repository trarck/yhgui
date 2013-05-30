#ifndef COCOS_YHGUI_COMPONENT_H_
#define COCOS_YHGUI_COMPONENT_H_

#include "cocos2d.h"
#include "YHGUIMacros.h"

NS_CC_YHGUI_BEGIN
	
class Component:public CCNode
{
//方法
public:
    
    Component();
    
    ~Component();

	void show();

	void hide();

	inline addEventListener(const char* type,CCObject* handleObject,yhlib::SEL_EventHandle handle) {
        return UIEventListenerManager::sharedUIEventListenerManager->addEventListener(this,type,handleObject,handle);
    }

    void removeEventListener(const char* type,CCObject* handleObject,yhlib::SEL_EventHandle handle) {
        return UIEventListenerManager::sharedUIEventListenerManager->removeEventListener(this,type,handleObject,handle);
    }

    void getEventListeners:function(type){
        return UIEventListenerManager.getEventListeners(this,type);
    }

    void dispatchEvent: function(event) {
        return UIEventListenerManager.dispatchEvent(this,event);
    }

    void trigger:function(type,data,bubbles){
        return UIEventListenerManager.trigger(this,type,data,bubbles);
    }

	/**
	 * 组件状态
	 */
	enum State{
        Normal = 0x00,
        Focused = 0x01,
        Selected = 0x02,
        Pressed = 0x04,//active
        Checked = 0x08,
        Hover =0x10,
        Custom = 0x00FF0000,
        Disabled = 0x40000000
    };
protected:
    
//属性
protected:
	/**
	 * 名称
	 */
    std::string m_name;
    
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_COMPONENT_H_
