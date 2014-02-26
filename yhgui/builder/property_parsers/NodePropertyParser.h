
#ifndef COCOS_YHGUI_BUILDER_PROPERTYIES_NODEPROPERTYPARSER_H_
#define COCOS_YHGUI_BUILDER_PROPERTYIES_NODEPROPERTYPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/YHGUIMacros.h>
#include <yhgui/Component.h>
#include "../UIBuilderMacros.h"
#include "../PropertyParser.h"

NS_CC_YHGUI_BEGIN

//=======================node 相关=======================//

/**
 * @brief 位置属性处理
 */
class PositionPropertyParser:public PropertyParser
{
public:
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(PositionPropertyParser,create);
};

/**
 * @brief 大小属性处理
 */
class SizePropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SizePropertyParser,create);
};

/**
 * @brief 锚点属性处理
 */
class AnchorPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(AnchorPropertyParser,create);
};

/**
 * @brief 缩放属性处理
 */
class ScalePropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ScalePropertyParser,create);
};

/**
 * @brief 旋转属性处理
 */
class RotationPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RotationPropertyParser,create);
};

/**
 * @brief 可见性属性处理
 */
class VisiblePropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(VisiblePropertyParser,create);
};

/**
 * @brief 遮挡属性处理
 */
class ZOrderPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ZOrderPropertyParser,create);
};

/**
 * @brief 标记属性处理
 */
class TagPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TagPropertyParser,create);
};

//=======================color 相关=======================//
/**
 * @brief 颜色属性处理
 */
class ColorPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ColorPropertyParser,create);
};

//=======================sprite 相关=======================//
/**
 * @brief 翻转属性处理
 */
class FlipPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(FlipPropertyParser,create);
};

/**
 * @brief 精灵颜色属性处理
 */
class SpriteColorPropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SpriteColorPropertyParser,create);
};

/**
 * @brief 图片属性处理
 */
class TexutrePropertyParser:public PropertyParser
{
public:
    
    void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(TexutrePropertyParser,create);
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PROPERTYIES_NODEPROPERTYPARSER_H_
