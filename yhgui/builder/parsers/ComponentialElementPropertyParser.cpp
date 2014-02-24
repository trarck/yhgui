#include "ComponentialElementPropertyParser.h"
#include "ElementProperty.h"

NS_CC_YHGUI_BEGIN


ComponentialElementPropertyParser::ComponentialElementPropertyParser()
:m_propertyParserMap(NULL)
{
    m_propertyParserMap=new CCDictionary();
}

ComponentialElementPropertyParser::~ComponentialElementPropertyParser()
{
    CC_SAFE_RELEASE_NULL(m_propertyParserMap);
}

void ComponentialElementPropertyParser::parse(CCNode* node,const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value::Members members=defineData.getMemberNames();
    for (yhge::Json::Value::Members::iterator iter=members.begin(); iter!=members.end(); ++iter) {
        ElementProperty* propertyParse=static_cast<ElementProperty* >(m_propertyParserMap->objectForKey((*iter)));
        
        if (propertyParse) {
            propertyParse->parse(node, defineData[*iter], parent);
        }
    }
}

void ComponentialElementPropertyParser::registerElementPropertyParser(const std::string& property,ElementProperty* elementProperty)
{
    m_propertyParserMap->setObject(elementProperty,property);
}

void ComponentialElementPropertyParser::removeElementPropertyParser(const std::string& property)
{
    m_propertyParserMap->removeObjectForKey(property);
}

NS_CC_YHGUI_END