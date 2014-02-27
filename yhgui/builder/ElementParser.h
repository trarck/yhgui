//
//  PropertyParser.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_ELEMENTPARSER_H_
#define COCOS_YHGUI_BUILDER_ELEMENTPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/Component.h>
#include "../YHGUIMacros.h"
#include "UIBuilderMacros.h"

NS_CC_YHGUI_BEGIN

/**
 * @brief 元素处理
 * 主要处理属性
 */
class ElementParser:public CCObject
{
public:
    
    virtual void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent)=0;
    
    virtual void parse(CCNode* node,const yhge::Json::Value& properties)
    {
        parse(node, properties, NULL);
    }
    
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_ELEMENTPARSER_H_
