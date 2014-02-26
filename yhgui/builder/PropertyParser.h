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

NS_CC_YHGUI_BEGIN

/**
 * @brief 属性处理
 */
class PropertyParser:public CCObject
{
public:
    
    virtual void parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)=0;
    
    virtual void parse(CCNode* node,const yhge::Json::Value& propertyValue)
    {
        parse(node, propertyValue, NULL);
    }
};



NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PROPERTYPARSER_H_
