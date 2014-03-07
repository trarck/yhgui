
#ifndef COCOS_YHGUI_BUILDER_ElementEventParser_H_
#define COCOS_YHGUI_BUILDER_ElementEventParser_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include "../event/UIEventListenerManager.h"
#include "ElementParser.h"

NS_CC_YHGUI_BEGIN

/**
 * @brief 对象事件处理
 * 按照分成的部分来组成事件处理
 * 默认都在defualt段里
 * map<segment><handleName>=eventHandler
 */
class ElementEventParser:public CCObject
{
public:
    
    ElementEventParser();
    
    ~ElementEventParser();
    
    /**
     * @brief 初始化
     */
    virtual bool init();

    virtual void parse(CCNode* node,const yhge::Json::Value& events,const yhge::Json::Value& type);

    void addEventHandler(const std::string& name,yhge::EventHandle* handler,const std::string& segment);

    void addEventHandler(const std::string& name,yhge::EventHandle* handler);
    
    void addEventHandle(const std::string& name,CCObject* target,yhge::SEL_EventHandle handle,const std::string& segment);
    
    void addEventHandle(const std::string& name,CCObject* target,yhge::SEL_EventHandle handle);

    CREATE_FUNC(ElementEventParser);
    
public:
    
    void setEventHandleMaps(CCDictionary* eventHandleMaps)
    {
        CC_SAFE_RETAIN(eventHandleMaps);
        CC_SAFE_RELEASE(m_eventHandleMaps);
        m_eventHandleMaps = eventHandleMaps;
    }

    CCDictionary* getEventHandleMaps()
    {
        return m_eventHandleMaps;
    }

    void setDefaultEventHandleMap(CCDictionary* defaultEventHandleMap)
    {
        //CC_SAFE_RETAIN(defaultEventHandleMap);
        //CC_SAFE_RELEASE(m_defaultEventHandleMap);
        m_defaultEventHandleMap = defaultEventHandleMap;
    }

    CCDictionary* getDefaultEventHandleMap()
    {
        return m_defaultEventHandleMap;
    }

protected:
    
    CCDictionary* m_eventHandleMaps;
    CCDictionary* m_defaultEventHandleMap;
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_ElementEventParser_H_
