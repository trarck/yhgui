#include "ComponentialElementParser.h"
#include "PropertyParser.h"

NS_CC_YHGUI_BEGIN


ComponentialElementParser::ComponentialElementParser()
:m_propertyParserMap(NULL)
{
    
}

ComponentialElementParser::~ComponentialElementParser()
{
    CC_SAFE_RELEASE_NULL(m_propertyParserMap);
}

bool ComponentialElementParser::init()
{
    m_propertyParserMap=new CCDictionary();
    return true;
}

void ComponentialElementParser::parse(CCNode* node,const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value::Members members=defineData.getMemberNames();
    for (yhge::Json::Value::Members::iterator iter=members.begin(); iter!=members.end(); ++iter) {
        PropertyParser* propertyParse=static_cast<PropertyParser* >(m_propertyParserMap->objectForKey((*iter)));
        
        if (propertyParse) {
            propertyParse->parse(node, defineData[*iter], parent);
        }
    }
}

void ComponentialElementParser::registerPropertyParser(const std::string& property,PropertyParser* elementProperty)
{
    m_propertyParserMap->setObject(elementProperty,property);
}

void ComponentialElementParser::removePropertyParser(const std::string& property)
{
    m_propertyParserMap->removeObjectForKey(property);
}

NS_CC_YHGUI_END