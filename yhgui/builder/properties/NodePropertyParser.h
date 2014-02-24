//
//  ElementProperty.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_PROPERTYIES_NODEPROPERTYPARSER_H_
#define COCOS_YHGUI_BUILDER_PROPERTYIES_NODEPROPERTYPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/YHGUIMacros.h>
#include <yhgui/Component.h>
#include "../UIBuilderMacros.h"
#include "../ElementProperty.h"

NS_CC_YHGUI_BEGIN

//=======================node 相关=======================//

/**
 * @brief 位置属性处理
 */
class PositionProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
};

/**
 * @brief 大小属性处理
 */
class SizeProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 锚点属性处理
 */
class AnchorProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 缩放属性处理
 */
class ScaleProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 旋转属性处理
 */
class RotationProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 可见性属性处理
 */
class VisibleProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 遮挡属性处理
 */
class ZOrderProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 标记属性处理
 */
class TagProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

//=======================color 相关=======================//
/**
 * @brief 颜色属性处理
 */
class ColorProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

//=======================sprite 相关=======================//
/**
 * @brief 翻转属性处理
 */
class FlipProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 精灵颜色属性处理
 */
class SpriteColorProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

/**
 * @brief 图片属性处理
 */
class TexutreProperty:public ElementProperty
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PROPERTYIES_NODEPROPERTYPARSER_H_
