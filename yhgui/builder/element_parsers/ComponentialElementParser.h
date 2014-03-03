//
//  PropertyParser.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_PARSERS_COMPONENTIALELEMENTPROPERTYPARSER_H_
#define COCOS_YHGUI_BUILDER_PARSERS_COMPONENTIALELEMENTPROPERTYPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include "../ElementParser.h"
#include "../PropertyParser.h"

NS_CC_YHGUI_BEGIN

/**
 * @brief 分散式元素属性处理
 * 每个元素的属性单独成一相处理单元，把他们组合在一起就是一个对象的属性。
 */
class ComponentialElementParser:public ElementParser
{
public:
    
    ComponentialElementParser();
    ~ComponentialElementParser();
    
    virtual bool init();
    
    virtual void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    void registerPropertyParser(const std::string& property,PropertyParser* propertyParser);
    
    void removePropertyParser(const std::string& property);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ComponentialElementParser,create);
    
public:
    
    inline void setPropertyParserMap(CCDictionary* propertyParserMap)
    {
        CC_SAFE_RETAIN(propertyParserMap);
        CC_SAFE_RELEASE(m_propertyParserMap);
        m_propertyParserMap = propertyParserMap;
    }
    
    inline CCDictionary* getPropertyParserMap()
    {
        return m_propertyParserMap;
    }
    
protected:
    
    CCDictionary* m_propertyParserMap;
    
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PARSERS_COMPONENTIALELEMENTPROPERTYPARSER_H_
