#ifndef COCOS_YHGUI_BUILDER_PROPERTIES_LABELPROPERTYPARSER_H_
#define COCOS_YHGUI_BUILDER_PROPERTIES_LABELPROPERTYPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/YHGUIMacros.h>
#include <yhgui/Component.h>
#include "../UIBuilderMacros.h"
#include "../PropertyParser.h"

NS_CC_YHGUI_BEGIN


//=======================label 相关=======================//
/**
 * @brief 文本属性处理
 */
class TextPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TextPropertyParser,create);
};

/**
 * @brief LabelColor文本属性处理
 * 适应CCLabelTTF和CCLabelAltas
 */
class LabelColorPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LabelColorPropertyParser,create);
};

//===========CCLabelTTF 相关===========//
/**
 * @brief TTF文本属性处理
 */
class TTFTextPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TTFTextPropertyParser,create);
};

/**
 * @brief 字体属性处理
 */
class FontFamilyPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(FontFamilyPropertyParser,create);
};

/**
 * @brief 字体大小属性处理
 */
class FontSizePropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(FontSizePropertyParser,create);
};

/**
 * @brief 横向对齐属性处理
 */
class HorizontalAlignmentPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(HorizontalAlignmentPropertyParser,create);
};

/**
 * @brief 纵向对齐属性处理
 */
class VerticalAlignmentPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(VerticalAlignmentPropertyParser,create);
};

//===========CCLabelBMFont 相关===========//

/**
 * @brief BMFont文本属性处理
 */
class BMFontTextPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BMFontTextPropertyParser,create);
};

/**
 * @brief BMFont字体文件属性处理
 */
class FntFilePropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(FntFilePropertyParser,create);
};

/**
 * @brief BMFont自动宽度属性处理
 */
class AutomaticWidthPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AutomaticWidthPropertyParser,create);
};

/**
 * @brief BMFont对齐属性处理
 */
class BMFontAlignmentPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(BMFontAlignmentPropertyParser,create);
};

///**
// * @brief BMFont图片偏移属性处理
// */
//class ImageOffsetPropertyParser:public PropertyParser
//{
//public:
//    
//    void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
//    
//};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PROPERTIES_LABELPROPERTYPARSER_H_
