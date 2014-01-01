#ifndef COCOS_YHGUI_COMPONENT_H_
#define COCOS_YHGUI_COMPONENT_H_

#include "cocos2d.h"
#include "YHGUIMacros.h"
#include "event/UIEventListenerManager.h"

NS_CC_YHGUI_BEGIN

/**
 * ui 基类
 * 包含事件操作
 * 用户交互(Interactive)。手机中是touch事件，使用cocos2d的touch机制。将来使用自己的方式来管理交互事件
 */
class Component:public CCNode,public CCTouchDelegate//, public CCAccelerometerDelegate, public CCKeypadDelegate
{
//方法
public:
    
    Component();
    
    ~Component();
    
    CREATE_FUNC(Component);

//	virtual void onEnter();
//
//	virtual void onExit();
    
    /**
     * 消除注册的事件
     */
    virtual void cleanup();
    
    virtual void setEnabled(bool enabled);
    
    virtual void setTouchPriority(int touchPriority);
    
    /**
     * 注册一个touch dispatcher。默认直接使用cocos2d的组织方式
     */
    virtual void registerWithTouchDispatcher(void);
    
    /**
     * 取消注册一个touch dispatcher。
     */
    virtual void unregisterWithTouchDispatcher(void);
    
    /**
     * 点击是否在物体内
     */
    bool isTouchInside(CCTouch* touch);
    
    /**
     * 点是否在物体内
     */
    bool isPointInside(const CCPoint& point);
    
    /**
     * 所有祖先结点是否能可见
     */
    bool hasVisibleParents();
    
    //==================事件处理=====================//

	inline void addEventListener(const char* type,CCObject* handleObject,yhge::SEL_EventHandle handle) {
        UIEventListenerManager::sharedUIEventListenerManager()->addEventListener(this,type,handleObject,handle);
    }

    inline void removeEventListener(const char* type,CCObject* handleObject,yhge::SEL_EventHandle handle) {
        UIEventListenerManager::sharedUIEventListenerManager()->removeEventListener(this,type,handleObject,handle);
    }

    inline CCArray* getEventListeners(const char* type){
        return UIEventListenerManager::sharedUIEventListenerManager()->getEventListeners(this,type);
    }

    inline void dispatchEvent(yhge::Event* evt) {
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
    
    //==================交互事件=====================//
    //
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);
    
    //default do nothing
//    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
//    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
//    virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);
//    virtual void ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent);
    
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
    
    //=============get set===============//
    
    inline void setName(const std::string name)
    {
        m_name = name;
    }
    
    inline const std::string getName()
    {
        return m_name;
    }
    
    
    inline bool isEnabled()
    {
        return m_enabled;
    }

    inline int getTouchPriority()
    {
        return m_touchPriority;
    }
    
	void setNeedDispatchToChildrenWhenCapthure(bool needDispatchToChildrenWhenCapthure)
	{
		m_needDispatchToChildrenWhenCapthure = needDispatchToChildrenWhenCapthure;
	}

	bool getNeedDispatchToChildrenWhenCapthure()
	{
		return m_needDispatchToChildrenWhenCapthure;
	}

    inline void setNeedBubbles(bool needBubbles)
    {
        m_needBubbles = needBubbles;
    }
    
    inline bool isNeedBubbles()
    {
        return m_needBubbles;
    }
    
//属性
protected:
	/**
	 * 名称
	 */
    std::string m_name;
    
    //是否有效，主要用于是否接受用户交互。
    bool m_enabled;
    
    //touch 是否在component内
    bool m_touchInside;
    
    //touch 等级
    int m_touchPriority;
    
	/**
	 * 在事件的捕捉介段，交互事件是否向子元素传递
	 * 默认子元素会接爱事件的投递。
	 * 对于有些组件，其不希望子元素接收事件的投递(出于性能或特殊需要)，可以把该事件设置为false。
	 * 对于混合组件(其子元素不是继承Component)，由于用到原始渲染元素，不希望渲染元素接受事件，可以设置为false
	 *
	 */
	bool m_needDispatchToChildrenWhenCapthure;

    //设置touch事件是否需要冒泡
    bool m_needBubbles;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_COMPONENT_H_
