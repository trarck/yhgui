#ifndef COCOS_YHGUI_COMPONENT_H_
#define COCOS_YHGUI_COMPONENT_H_

#include "cocos2d.h"
#include "YHGUIMacros.h"
#include "./event/UIEventListenerManager.h"

NS_CC_YHGUI_BEGIN
	
class Component:public CCNode
{
//方法
public:
    
    Component();
    
    ~Component();

	void show();

	void hide();
    
    /**
     * 消除注册的事件
     */
    virtual void cleanup();

	inline void addEventListener(const char* type,CCObject* handleObject,yhlib::SEL_EventHandle handle) {
        UIEventListenerManager::sharedUIEventListenerManager()->addEventListener(this,type,handleObject,handle);
    }

    inline void removeEventListener(const char* type,CCObject* handleObject,yhlib::SEL_EventHandle handle) {
        UIEventListenerManager::sharedUIEventListenerManager()->removeEventListener(this,type,handleObject,handle);
    }

    inline CCArray* getEventListeners(const char* type){
        return UIEventListenerManager::sharedUIEventListenerManager()->getEventListeners(this,type);
    }

    inline void dispatchEvent(yhlib::Event* evt) {
        UIEventListenerManager::sharedUIEventListenerManager()->dispatchEvent(this,evt);
    }

    inline void trigger(const char* type,CCObject* data,bool bubbles){
        UIEventListenerManager::sharedUIEventListenerManager()->trigger(this,type,data,bubbles);
    }
    
    inline void trigger(const char* type,CCObject* data){
        UIEventListenerManager::sharedUIEventListenerManager()->trigger(this,type,data,true);
    }
    
    inline void trigger(const char* type){
        UIEventListenerManager::sharedUIEventListenerManager()->trigger(this,type,NULL,true);
    }

    CREATE_FUNC(Component);
    
	/**
	 * 组件状态
	 */
	enum State{
        kIdle = 0x00,
        kNormal = 0x01,
        kHover = 0x02,
        kPressed = 0x04,//active
        kSelected = 0x08,
        kChecked = 0x10,
        kFocused =0x20,
        kCustom = 0x00FF0000,
        kDisabled = 0x40000000
    };

    inline void setName(const std::string name)
    {
        m_name = name;
    }
    
    inline const std::string getName()
    {
        return m_name;
    }

//属性
protected:
	/**
	 * 名称
	 */
    std::string m_name;
    
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_COMPONENT_H_
