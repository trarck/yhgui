#include "IntegrativeNodeParser.h"
#include "../UIBuilderConsts.h"

NS_CC_YHGUI_BEGIN

void IntegrativeNodeParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    //parse position
    
    node->setPosition(getPosition(properties, parent, builder));

    //parse size
    node->setContentSize(getSize(properties, parent, builder));
    
    //parse anchor
    node->setAnchorPoint(getAnchor(properties, parent, builder));
    
    //parse scale
    node->setScaleX(getScaleX(properties, parent, builder));
    node->setScaleY(getScaleY(properties, parent, builder));
    
    //parse rotation
    node->setRotation(getRotation(properties, parent, builder));
    
    //parse visible
    node->setVisible(getVisible(properties, parent, builder));
    
    //parse zorder
    node->setZOrder(getZOrder(properties, parent, builder));
    
    //parse tag
    node->setTag(getTag(properties, parent, builder));
}

CCPoint IntegrativeNodeParser::getPosition(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    float x=0.0f,y=0.0f;
    
    yhge::Json::Value xValue=properties[kPropertyNameX];
    if(!xValue.isNull()){
        x=xValue.asDouble();
    }
    
    yhge::Json::Value yValue=properties[kPropertyNameY];
    if(!yValue.isNull()){
        y=yValue.asDouble();
    }
    
    return ccp(x,y);
}

CCSize IntegrativeNodeParser::getSize(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    float width=0.0f,height=0.0f;
    
    yhge::Json::Value widthValue=properties[kPropertyNameWidth];
    if(!widthValue.isNull()){
        width=widthValue.asDouble();
    }
    
    yhge::Json::Value heightValue=properties[kPropertyNameHeight];
    if(!heightValue.isNull()){
        height=heightValue.asDouble();
    }

    return CCSizeMake(width, height);
}

CCPoint IntegrativeNodeParser::getAnchor(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    float anchorX=0.0f,anchorY=0.0f;
    
    yhge::Json::Value anchorXValue=properties[kPropertyNamePosition][kPropertyNameX];
    if(!anchorXValue.isNull()){
        anchorX=anchorXValue.asDouble();
    }
    
    yhge::Json::Value anchorYValue=properties[kPropertyNamePosition][kPropertyNameY];
    if(!anchorYValue.isNull()){
        anchorY=anchorYValue.asDouble();
    }
    
    return ccp(anchorX, anchorY);
}

float IntegrativeNodeParser::getScaleX(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    float scaleX=1.0f;
    
    yhge::Json::Value scaleXValue=properties[kPropertyNameScale][kPropertyNameX];
    if(!scaleXValue.isNull()){
        scaleX=scaleXValue.asDouble();
    }
    
    return scaleX;
}

float IntegrativeNodeParser::getScaleY(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    float scaleY=1.0f;
    yhge::Json::Value scaleYValue=properties[kPropertyNameScale][kPropertyNameY];
    if(!scaleYValue.isNull()){
        scaleY=scaleYValue.asDouble();
    }
    
    return scaleY;
}

float IntegrativeNodeParser::getRotation(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    float rotation=0.0f;
    
    yhge::Json::Value rotationValue=properties[kPropertyNameRotation];
    if(!rotationValue.isNull()){
        rotation=rotationValue.asDouble();
    }
    return rotation;
}

bool IntegrativeNodeParser::getVisible(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value visibleValue=properties[kPropertyNameVisible];
    if(!visibleValue.isNull()){
        return visibleValue.asInt()!=0;
    }
    
    return true;
}

int IntegrativeNodeParser::getZOrder(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value zOrderValue=properties[kPropertyNameZOrder];
    if(!zOrderValue.isNull()){
        return zOrderValue.asInt();
    }
    return 0;
}

int IntegrativeNodeParser::getTag(const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value tagValue=properties[kPropertyNameTag];
    if(!tagValue.isNull()){
        return tagValue.asInt();
    }
    
    return 0;
}

NS_CC_YHGUI_END