
#ifndef COCOS_YHGUI_BUILDER_PROPERTYIES_COMPONENTPROPERTYPARSER_H_
#define COCOS_YHGUI_BUILDER_PROPERTYIES_COMPONENTPROPERTYPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/YHGUIMacros.h>
#include "../UIBuilderMacros.h"
#include "../PropertyParser.h"

NS_CC_YHGUI_BEGIN

//=======================component 相关=======================//

/**
 * @brief 名子属性处理
 */
class ComponentNamePropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ComponentNamePropertyParser,create);
};

/**
 * @brief 是否属性处理
 */
class ComponentEnablePropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ComponentEnablePropertyParser,create);
};


/**
 * @brief 交互范围属性处理
 */
class ComponentInteractiveBoundsPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ComponentInteractiveBoundsPropertyParser,create);
};


//=======================button 相关=======================//
/**
 * @brief 希望大小属性处理
 */
class PreferredSizePropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(PreferredSizePropertyParser,create);
};

//=======================normal button 相关=======================//
/**
 * @brief 普通按钮状态属性处理
 */
class NormalButtonStatesPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(NormalButtonStatesPropertyParser,create);
    
protected:
    
    Component::State getStateEnum(const std::string& stateString);
};

/**
 * @brief 希望大小属性处理
 */
class NormalButtonLabelPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(NormalButtonLabelPropertyParser,create);
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PROPERTYIES_COMPONENTPROPERTYPARSER_H_
