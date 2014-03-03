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

void ComponentialElementParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    CCDictElement* elem=NULL;
    CCDICT_FOREACH(m_propertyParserMap, elem){
        PropertyParser* propertyParse=static_cast<PropertyParser* >(elem->getObject());
        propertyParse->parse(node, properties, parent,builder);
    }
//    yhge::Json::Value::Members members=properties.getMemberNames();
//    for (yhge::Json::Value::Members::iterator iter=members.begin(); iter!=members.end(); ++iter) {
//        PropertyParser* propertyParse=static_cast<PropertyParser* >(m_propertyParserMap->objectForKey((*iter)));
//        
//        if (propertyParse) {
//            propertyParse->parse(node, properties[*iter], parent,builder);
//        }
//    }
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