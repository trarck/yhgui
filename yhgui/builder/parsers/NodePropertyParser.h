//
//  PropertyParser.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_PARSERS_NODEPROPERTYPARSER_H_
#define COCOS_YHGUI_BUILDER_PARSERS_NODEPROPERTYPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/Component.h>
#include "../ElementPropertyParser.h"

NS_CC_YHGUI_BEGIN


class NodePropertyParser:public ElementPropertyParser
{
public:
    
    virtual void parse(CCNode* node,const yhge::Json::Value& defineData,CCNode* parent);
    
protected:
    
    CCPoint getPosition(const yhge::Json::Value& defineData,CCNode* parent);
    
    CCSize getSize(const yhge::Json::Value& defineData,CCNode* parent);
    
    CCPoint getAnchor(const yhge::Json::Value& defineData,CCNode* parent);
    
    float getScaleX(const yhge::Json::Value& defineData,CCNode* parent);
    
    float getScaleY(const yhge::Json::Value& defineData,CCNode* parent);
    
    float getRotation(const yhge::Json::Value& defineData,CCNode* parent);
    
    bool getVisible(const yhge::Json::Value& defineData,CCNode* parent);
    
    int getZOrder(const yhge::Json::Value& defineData,CCNode* parent);
    
    int getTag(const yhge::Json::Value& defineData,CCNode* parent);
    
};

class SpritePropertyParser:public NodePropertyParser
{
public:
    
    virtual void parse(CCSprite* sprite,const yhge::Json::Value& defineData,CCNode* parent);
    
};

class ComponentPropertyParser:public NodePropertyParser
{
public:
    
    virtual void parse(yhgui::Component* component,const yhge::Json::Value& defineData,yhgui::Component* parent);
    
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PARSERS_NODEPROPERTYPARSER_H_
