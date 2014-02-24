//
//  ElementProperty.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_PROPERTIES_LABELPROPERTYPARSER_H_
#define COCOS_YHGUI_BUILDER_PROPERTIES_LABELPROPERTYPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/YHGUIMacros.h>
#include <yhgui/Component.h>
#include "../UIBuilderMacros.h"
#include "../ElementProperty.h"

NS_CC_YHGUI_BEGIN


//=======================label 相关=======================//
/**
 * @brief 文本属性处理
 */
class TextProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief LabelColor文本属性处理
 * 适应CCLabelTTF和CCLabelAltas
 */
class LabelColorProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

//===========CCLabelTTF 相关===========//
/**
 * @brief TTF文本属性处理
 */
class TTFTextProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 字体属性处理
 */
class FontFamilyProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 字体大小属性处理
 */
class FontSizeProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 横向对齐属性处理
 */
class HorizontalAlignmentProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 纵向对齐属性处理
 */
class VerticalAlignmentProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

//===========CCLabelBMFont 相关===========//

/**
 * @brief BMFont文本属性处理
 */
class BMFontTextProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief BMFont字体文件属性处理
 */
class FntFileProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief BMFont自动宽度属性处理
 */
class AutomaticWidthProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief BMFont对齐属性处理
 */
class BMFontAlignmentProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

///**
// * @brief BMFont图片偏移属性处理
// */
//class ImageOffsetProperty:public ElementProperty
//{
//public:
//    
//    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
//    
//};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PROPERTIES_LABELPROPERTYPARSER_H_
