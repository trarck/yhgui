#include "UIBuilder.h"
#include "UIBuilderConsts.h"

NS_CC_YHGUI_BEGIN

UIBuilder::UIBuilder()
:m_elementCreatorFactory(NULL)
,m_elementParserFactory(NULL)
{
    
}

UIBuilder::~UIBuilder()
{
    CC_SAFE_RELEASE_NULL(m_elementCreatorFactory);
    CC_SAFE_RELEASE_NULL(m_elementParserFactory);
}

bool UIBuilder::init()
{
    m_elementCreatorFactory=new ElementCreatorFactory();
    m_elementParserFactory->init();
    
    m_elementParserFactory=new ElementParserFactory();
    m_elementParserFactory->init();
    
    return true;
}

CCNode* UIBuilder::buildWithJSONFile(const char* jsonFile)
{
    unsigned long size = 0;
    unsigned char * pBytes=CCFileUtils::sharedFileUtils()->getFileData(jsonFile, "rb", &size);
    
    CCNode* root=buildWithJSONData((char*)pBytes);
    
    CC_SAFE_DELETE_ARRAY(pBytes);
    
    return  root;
}

CCNode* UIBuilder::buildWithJSONData(const char* jsonString)
{
    yhge::Json::Reader reader;
    yhge::Json::Value root;
    
    bool parsingSuccessful=reader.parse(jsonString, root,false);
    if (parsingSuccessful) {
        return buildUI(root);
    }
    
    return NULL;
}

CCNode* UIBuilder::buildUI(const yhge::Json::Value& json)
{
    return buildUI(json,NULL);
}

CCNode* UIBuilder::buildUI(const yhge::Json::Value& json,CCNode* parent)
{
    unsigned int dataVersion=this->getDataVersion(json);
    
    CCNode* root=this->createElement(json,parent);
    
    return root;
}

CCNode* UIBuilder::createElement(const yhge::Json::Value& defineData)
{
    return createElement(defineData,NULL);
}

CCNode* UIBuilder::createElement(const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value type=defineData[kPropertyNameType];
    
    //get element creator
    ElementCreator* elementCreator=m_elementCreatorFactory->getElementCreator(type);
    
    //create element
    CCNode* element=elementCreator->createElement(defineData);
    
    //set element property
    setElementPropertiesWithDefine(element, defineData,parent);
    
    //create element children
    this->createChildren(defineData[kPropertyNameChildren], element);
    
    if(parent)
        parent->addChild(element);
    
    return element;
}

void UIBuilder::createChildren(const yhge::Json::Value& children,CCNode* parent)
{
    if (!children.isNull() && parent) {
        CCNode* child=NULL;
        for (int i=0; i<children.size(); ++i) {
            child=this->createElement(children[i]);
            parent->addChild(child);
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

void UIBuilder::setElementPropertiesWithDefine(CCNode* node,const yhge::Json::Value& defineData,CCNode* parent)
{
    setElementProperties(node,defineData[kPropertyNameType],defineData[kPropertyNameProperties], parent);
}

void UIBuilder::setElementProperties(CCNode* node,const yhge::Json::Value& type,const yhge::Json::Value& properties)
{
    setElementProperties(node, type,properties,NULL);
}

void UIBuilder::setElementProperties(CCNode* node,const yhge::Json::Value& type,const yhge::Json::Value& properties,CCNode* parent)
{
    ElementParser* elementParser=m_elementParserFactory->getElementParser(type);
    
    elementParser->parse(node, properties, parent);
}

unsigned int UIBuilder::tanslateElementTypeFromStringToInteger(const std::string& typeString)
{
    return 0;
}

NS_CC_YHGUI_END