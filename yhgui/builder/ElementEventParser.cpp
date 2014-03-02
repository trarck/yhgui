#include "ElementEventParser.h"
#include "element_parsers/NodeParser.h"
#include "UIBuilderConsts.h"

USING_NS_CC_YHGE;

NS_CC_YHGUI_BEGIN


ElementEventParser::ElementEventParser()
:m_eventHandleMaps(NULL)
,m_defaultEventHandleMap(NULL)
{
    
}

ElementEventParser::~ElementEventParser()
{
    CC_SAFE_RELEASE_NULL(m_eventHandleMaps);
    m_defaultEventHandleMap=NULL;
    //CC_SAFE_RELEASE_NULL(m_defaultEventHandleMap);
}

bool ElementEventParser::init()
{
    m_eventHandleMaps=new CCDictionary();
    m_defaultEventHandleMap=new CCDictionary();
    m_eventHandleMaps->setObject(m_defaultEventHandleMap,kDefaultSegmentName);
    m_defaultEventHandleMap->release();
    return true;
}

/**
 *
 * events={
        touchInSide="handleA",
        touchOutSide={
            segment:"default",
            handle:"handleB"
        }
   }

   events=[
    {
        handle:"handleA",
        eventType:"touchInSide"
    },
    {
        segment:"default",
        handle:"handleB",
        eventType:"touchOutSide"
    },
   ]
 */
void ElementEventParser::parse(CCNode* node,const yhge::Json::Value& events,const yhge::Json::Value& type)
{
    UIEventListenerManager* eventManager=UIEventListenerManager::sharedUIEventListenerManager();

    yhge::Json::Value::Members members=events.getMemberNames();
    yhge::Json::Value eventItem;

    std::string segment="";
    std::string handleKey="";
    std::string eventType="";

    CCDictionary* eventHandleMap=NULL;
    EventHandle* eventHandler=NULL;

    bool isDefaultSegment=false;

    for (yhge::Json::Value::Members::iterator iter=members.begin(); iter!=members.end(); ++iter) {
        eventItem=events[*iter];

        //get key
        switch (eventItem.type())
        {
            case yhge::Json::stringValue:{
                //segment=kDefaultSegmentName;
                handleKey=eventItem.asString();
                eventType=*iter;
                isDefaultSegment=true;
                break;
            }
            case yhge::Json::objectValue:{
                isDefaultSegment=eventItem[kPropertyNameSegment].isNull();
                if (!isDefaultSegment)
                {
                    segment=eventItem[kPropertyNameSegment].asString();
                }
                //segment=isDefaultSegment?kDefaultSegmentName:eventItem[kPropertyNameSegment].asString();
                handleKey=eventItem[kPropertyNameSegment].asString();
                eventType=eventItem[kPropertyNameEventName].isNull()?(*iter):eventItem[kPropertyNameEventName].asString();
                break;
            }
            default:
                CCAssert(false,"ElementEventParser::parse unknow event define");
                break;
        }

        //���Ҫ����ĺ���key�����ڣ��������һ��
        if (handleKey.empty())
            continue;

         //add listener
        //ʹ��default����һ��hash���ң��ӿ��ٶȡ�ͨ���������default
        if (isDefaultSegment){
            if (m_defaultEventHandleMap){
                eventHandler=static_cast<EventHandle*>(m_defaultEventHandleMap->objectForKey(handleKey));
                if (eventHandler){
                    eventManager->addEventListener(node,eventType.c_str(),eventHandler);
                }
            }
        }else{
            eventHandleMap = static_cast<CCDictionary*>(m_eventHandleMaps->objectForKey(segment));
            if (eventHandleMap){
                eventHandler=static_cast<EventHandle*>(eventHandleMap->objectForKey(handleKey));
                if (eventHandler){
                    eventManager->addEventListener(node,eventType.c_str(),eventHandler);
                }
            }
        }
    }
}

void ElementEventParser::addEventHandle(const std::string& name,yhge::EventHandle* handler,const std::string& segment)
{
    CCDictionary* handleMap=static_cast<CCDictionary*>(m_eventHandleMaps->objectForKey(segment));
    if (!handleMap)
    {
        handleMap=new CCDictionary();
        m_eventHandleMaps->setObject(handleMap,segment);
        handleMap->release();
    }

    handleMap->setObject(handler,name);
}

void ElementEventParser::addEventHandle(const std::string& name,yhge::EventHandle* handler)
{
    addEventHandle(name,handler,kDefaultSegmentName);
}

NS_CC_YHGUI_END