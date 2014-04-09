#include "UIBuilder.h"
#include "UIBuilderConsts.h"

NS_CC_YHGUI_BEGIN

UIBuilder::UIBuilder()
:m_elementCreatorFactory(NULL)
,m_elementParserFactory(NULL)
,m_elementEventParser(NULL)
,m_currentFile("")
,m_resourcePath("")
{
    
}

UIBuilder::~UIBuilder()
{
    CC_SAFE_RELEASE_NULL(m_elementCreatorFactory);
    CC_SAFE_RELEASE_NULL(m_elementParserFactory);
    CC_SAFE_RELEASE_NULL(m_elementEventParser);
}

bool UIBuilder::init()
{
    m_elementCreatorFactory=new ElementCreatorFactory();
    m_elementCreatorFactory->init();
    
    m_elementParserFactory=new ElementParserFactory();
    m_elementParserFactory->init();
    
    m_elementEventParser=new ElementEventParser();
    m_elementEventParser->init();
    
    return true;
}

bool UIBuilder::init(ElementCreatorFactory* elementCreatorFactory,ElementParserFactory* elementParserFactory,ElementEventParser* elementEventParser)
{
    setElementCreatorFactory(elementCreatorFactory);
    setElementParserFactory(elementParserFactory);
    setElementEventParser(elementEventParser);
    
    return true;
}

CCNode* UIBuilder::buildWithJSONFile(const std::string& jsonFile)
{
    return  buildWithJSONFile(jsonFile,NULL,false);
}

CCNode* UIBuilder::buildWithJSONFile(const std::string& jsonFile,CCNode* parent)
{
    return  buildWithJSONFile(jsonFile,parent,true);
}

CCNode* UIBuilder::buildWithJSONFile(const std::string& jsonFile,CCNode* parent,bool autoAddToParent)
{
    m_currentFile=jsonFile;
    
    unsigned long size = 0;
    unsigned char * pBytes=CCFileUtils::sharedFileUtils()->getFileData(jsonFile.c_str(), "rb", &size);
    
    CCNode* root=NULL;
    if (size) {
        root=buildWithJSONData((char*)pBytes);
    }
    
    CC_SAFE_DELETE_ARRAY(pBytes);
    
    return  root;
}

CCNode* UIBuilder::buildWithJSONData(const char* jsonString)
{
    return buildWithJSONData(jsonString,NULL,false);
}

CCNode* UIBuilder::buildWithJSONData(const char* jsonString,CCNode* parent)
{
    return buildWithJSONData(jsonString,parent,true);;
}

CCNode* UIBuilder::buildWithJSONData(const char* jsonString,CCNode* parent,bool autoAddToParent)
{
    yhge::Json::Reader reader;
    yhge::Json::Value root;
    
    bool parsingSuccessful=reader.parse(jsonString, root,false);
    if (parsingSuccessful) {
        return buildUI(root,parent,autoAddToParent);
    }
    
    return NULL;
}

CCNode* UIBuilder::buildUI(const yhge::Json::Value& json)
{
    return buildUI(json,NULL);
}

CCNode* UIBuilder::buildUI(const yhge::Json::Value& json,CCNode* parent)
{
    return buildUI(json,parent,true);
}

CCNode* UIBuilder::buildUI(const yhge::Json::Value& json,CCNode* parent,bool autoAddToParent)
{
//    unsigned int dataVersion=this->getDataVersion(json);
    
    CCNode* root=this->buildElement(json[kPropertyNameGraphData],parent,autoAddToParent);
    
    return root;
}

CCNode* UIBuilder::buildElement(const yhge::Json::Value& defineData)
{
    return buildElement(defineData,NULL);
}

CCNode* UIBuilder::buildElement(const yhge::Json::Value& defineData,CCNode* parent)
{
    return buildElement(defineData, parent, true);
}

CCNode* UIBuilder::buildElement(const yhge::Json::Value& defineData,CCNode* parent,bool autoAddToParent)
{
    yhge::Json::Value type=defineData[kPropertyNameType];
    
    CCNode* element=createElement(defineData,parent);
    
    if(element){
        
        //parse element
        parseElement(element, defineData,parent);
        
        //create element children
        buildChildren(defineData[kPropertyNameChildren], element);
        
        if(parent && autoAddToParent)
            parent->addChild(element);
        
    }else{
        CCLOG("UIBuilder::buildElement unknown element type:%s",type.asString().c_str());
    }
    
    return element;
}

void UIBuilder::buildChildren(const yhge::Json::Value& children,CCNode* parent)
{
    if (!children.isNull() && parent) {
        CCNode* child=NULL;
        for (int i=0; i<children.size(); ++i) {
            child=this->buildElement(children[i],parent);
//            if (child) {
//                parent->addChild(child);
//            }
        }
    }
}

unsigned int UIBuilder::getDataFormat(yhge::Json::Value root)
{
    return kUIDataFormatSimple;
}

unsigned int UIBuilder::getDataVersion(yhge::Json::Value root)
{
    return root[kPropertyNameVersion].asUInt();
}


CCNode* UIBuilder::createElement(const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value type=defineData[kPropertyNameType];
    
    //get element creator
    ElementCreator* elementCreator=m_elementCreatorFactory->getElementCreator(type);
    if(elementCreator){
        //create element
        return elementCreator->createElement(defineData,this,parent);
    }
    
    return NULL;
}

void UIBuilder::parseElement(CCNode* element,const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value type=defineData[kPropertyNameType];
    
    //set element property
    setElementProperties(element,type,defineData[kPropertyNameProperties], parent);
    
    //register event
    registerElementEvents(element,type,defineData[kPropertyNameEvents],parent);
}

void UIBuilder::setElementProperties(CCNode* node,const yhge::Json::Value& type,const yhge::Json::Value& properties)
{
    setElementProperties(node, type,properties,NULL);
}

void UIBuilder::setElementProperties(CCNode* node,const yhge::Json::Value& type,const yhge::Json::Value& properties,CCNode* parent)
{
//    yhge::Json::Value::Members members=properties.getMemberNames();
//    for (yhge::Json::Value::Members::iterator iter=members.begin(); iter!=members.end(); ++iter) {
//        CCLOG("%s",(*iter).c_str());
//    }
    
    ElementParser* elementParser=m_elementParserFactory->getElementParser(type);
    if (elementParser) {
        elementParser->parse(node, properties, parent,this);
    }else{
        CCLOG("UIBuilder::setElementProperties unkwon type %s",type.asString().c_str());
    }
}

void UIBuilder::registerElementEvents(CCNode* node,const yhge::Json::Value& type,const yhge::Json::Value& events)
{
    registerElementEvents(node,type,events,NULL);
}

void UIBuilder::registerElementEvents(CCNode* node,const yhge::Json::Value& type,const yhge::Json::Value& events,CCNode* parent)
{
    if (!events.isNull()){
        m_elementEventParser->parse(node,events,type);
    }
}

unsigned int UIBuilder::tanslateElementTypeFromStringToInteger(const std::string& typeString)
{
    return 0;
}

std::string UIBuilder::getRelationPath(const std::string& path)
{
    //如果是绝对路径，直接返回
    if (path.substr(0,1)=="/") {
        return path;
    }
    
    std::string newPath;
    
    int pos=m_currentFile.find_last_of("/");
    
    if (pos != std::string::npos)
    {
        //没有指定资源路径，直接使用程序运动目录
        std::string dir = m_currentFile.substr(0, pos + 1);
        newPath = dir + path;
    }else{
        //使用资源路径
        newPath=m_resourcePath+path;
    }
    
    return newPath;
}


UIBuilder* UIBuilder::clone()
{
    UIBuilder* newBuilder=new UIBuilder();
    
    cloneProperties(newBuilder);
    
    newBuilder->autorelease();
    
    return newBuilder;
}

void UIBuilder::cloneProperties(UIBuilder* builder)
{
    builder->init(m_elementCreatorFactory, m_elementParserFactory, m_elementEventParser);
    builder->setCurrentFile(m_currentFile);
    builder->setResourcePath(m_resourcePath);
}

NS_CC_YHGUI_END