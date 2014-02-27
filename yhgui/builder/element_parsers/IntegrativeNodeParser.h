
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
    
    virtual void parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent);
    
protected:
    
    CCPoint getPosition(const yhge::Json::Value& properties,CCNode* parent);
    
    CCSize getSize(const yhge::Json::Value& properties,CCNode* parent);
    
    CCPoint getAnchor(const yhge::Json::Value& properties,CCNode* parent);
    
    float getScaleX(const yhge::Json::Value& properties,CCNode* parent);
    
    float getScaleY(const yhge::Json::Value& properties,CCNode* parent);
    
    float getRotation(const yhge::Json::Value& properties,CCNode* parent);
    
    bool getVisible(const yhge::Json::Value& properties,CCNode* parent);
    
    int getZOrder(const yhge::Json::Value& properties,CCNode* parent);
    
    int getTag(const yhge::Json::Value& properties,CCNode* parent);
    
};

class IntegrativeSpritePropertyParser:public IntegrativeNodeParser
{
public:
    
    virtual void parse(CCSprite* sprite,const yhge::Json::Value& properties,CCNode* parent);
    
};

class IntegrativeComponentPropertyParser:public IntegrativeNodeParser
{
public:
    
    virtual void parse(yhgui::Component* component,const yhge::Json::Value& properties,yhgui::Component* parent);
    
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PARSERS_NODEPROPERTYPARSER_H_
