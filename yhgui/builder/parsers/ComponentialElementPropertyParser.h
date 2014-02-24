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
#include "../ElementPropertyParser.h"
#include "../ElementProperty.h"

NS_CC_YHGUI_BEGIN

/**
 * @brief 分散式元素属性处理
 * 每个元素的属性单独成一相处理单元，把他们组合在一起就是一个对象的属性。
 */
class ComponentialElementPropertyParser:public ElementPropertyParser
{
public:
    
    ComponentialElementPropertyParser();
    ~ComponentialElementPropertyParser();
    
    virtual void parse(CCNode* node,const yhge::Json::Value& defineData,CCNode* parent);
    
    void registerElementPropertyParser(const std::string& property,ElementProperty* elementProperty);
    
    void removeElementPropertyParser(const std::string& property);
    
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
