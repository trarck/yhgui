
#ifndef COCOS_YHGUI_BUILDER_PARSERS_INTEGRATIVENODEPARSER_H_
#define COCOS_YHGUI_BUILDER_PARSERS_INTEGRATIVENODEPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/Component.h>
#include "../ElementParser.h"

NS_CC_YHGUI_BEGIN


class IntegrativeNodeParser:public ElementParser
{
public:
    
    virtual void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
protected:
    
    CCPoint getPosition(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    CCSize getSize(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    CCPoint getAnchor(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    float getScaleX(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    float getScaleY(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    float getRotation(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    bool getVisible(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    int getZOrder(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
    int getTag(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
};

class IntegrativeSpritePropertyParser:public IntegrativeNodeParser
{
public:
    
    virtual void parse(CCSprite* sprite,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder);
    
};

class IntegrativeComponentPropertyParser:public IntegrativeNodeParser
{
public:
    
    virtual void parse(yhgui::Component* component,const yhge::Json::Value& properties,yhgui::Component* parent,UIBuilder* builder);
    
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PARSERS_NODEPROPERTYPARSER_H_
