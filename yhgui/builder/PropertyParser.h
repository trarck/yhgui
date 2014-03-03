//
//  PropertyParser.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_PROPERTYPARSER_H_
#define COCOS_YHGUI_BUILDER_PROPERTYPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/Component.h>
#include "../YHGUIMacros.h"
#include "UIBuilderMacros.h"
#include "UIBuilderConsts.h"

NS_CC_YHGUI_BEGIN

class UIBuilder;

/**
 * @brief 属性处理
 */
class PropertyParser:public CCObject
{
public:
    
    virtual void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent,UIBuilder* builder)=0;
    
    virtual void parse(CCNode* node,const yhge::Json::Value& propertyValue)
    {
        parse(node, propertyValue, NULL,NULL);
    }
    
    //===============utils===============//
public:
    
    /**
     * @brief 从json中取得矩形
     */
    inline static CCRect getRect(const yhge::Json::Value& rectValue)
    {
        return rectValue.isArray()?getRectFromArray(rectValue):getRectFromObject(rectValue);
    }
    
    /**
     * @brief 从json中取得矩形
     */
    inline static CCRect getRectFromArray(const yhge::Json::Value& rectValue)
    {
        return CCRectMake(rectValue[0u].asDouble(), rectValue[1u].asDouble(), rectValue[2u].asDouble(), rectValue[3u].asDouble());
    }
    
    /**
     * @brief 从json中取得矩形
     */
    inline static CCRect getRectFromObject(const yhge::Json::Value& rectValue)
    {
        return CCRectMake(
                          rectValue[kPropertyNameX].asDouble(), rectValue[kPropertyNameY].asDouble(),
                          rectValue[kPropertyNameWidth].asDouble(), rectValue[kPropertyNameHeight].asDouble());
    }
    
    /**
     * @brief 从json中取得颜色
     */
    inline static ccColor3B getColor(const yhge::Json::Value& colorValue)
    {
        return colorValue.isArray()?getColorFromArray(colorValue):getColorFromObject(colorValue);
    }
    
    /**
     * @brief 从json中取得颜色
     */
    inline static ccColor3B getColorFromArray(const yhge::Json::Value& colorValue)
    {
        return ccc3(colorValue[0u].asUInt(), colorValue[1u].asUInt(), colorValue[2u].asUInt());
    }
    
    /**
     * @brief 从json中取得颜色
     */
    inline static ccColor3B getColorFromObject(const yhge::Json::Value& colorValue)
    {
        return ccc3(colorValue[kPropertyNameR].asUInt(), colorValue[kPropertyNameG].asUInt(), colorValue[kPropertyNameB].asUInt());
    }
};



NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PROPERTYPARSER_H_
