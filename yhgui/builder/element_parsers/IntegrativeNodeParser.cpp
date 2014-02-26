#include "IntegrativeNodeParser.h"
#include "../UIBuilderConsts.h"

NS_CC_YHGUI_BEGIN

void IntegrativeNodeParser::parse(CCNode* node,const yhge::Json::Value& defineData,CCNode* parent)
{
    //parse position
    
    node->setPosition(getPosition(defineData, parent));

    //parse size
    node->setContentSize(getSize(defineData, parent));
    
    //parse anchor
    node->setAnchorPoint(getAnchor(defineData, parent));
    
    //parse scale
    node->setScaleX(getScaleX(defineData, parent));
    node->setScaleY(getScaleY(defineData, parent));
    
    //parse rotation
    node->setRotation(getRotation(defineData, parent));
    
    //parse visible
    node->setVisible(getVisible(defineData, parent));
    
    //parse zorder
    node->setZOrder(getZOrder(defineData, parent));
    
    //parse tag
    node->setTag(getTag(defineData, parent));
}

CCPoint IntegrativeNodeParser::getPosition(const yhge::Json::Value& defineData,CCNode* parent)
{
    float x=0.0f,y=0.0f;
    
    yhge::Json::Value xValue=defineData[kPropertyNameX];
    if(!xValue.isNull()){
        x=xValue.asDouble();
    }
    
    yhge::Json::Value yValue=defineData[kPropertyNameY];
    if(!yValue.isNull()){
        y=yValue.asDouble();
    }
    
    return ccp(x,y);
}

CCSize IntegrativeNodeParser::getSize(const yhge::Json::Value& defineData,CCNode* parent)
{
    float width=0.0f,height=0.0f;
    
    yhge::Json::Value widthValue=defineData[kPropertyNameWidth];
    if(!widthValue.isNull()){
        width=widthValue.asDouble();
    }
    
    yhge::Json::Value heightValue=defineData[kPropertyNameHeight];
    if(!heightValue.isNull()){
        height=heightValue.asDouble();
    }

    return CCSizeMake(width, height);
}

CCPoint IntegrativeNodeParser::getAnchor(const yhge::Json::Value& defineData,CCNode* parent)
{
    float anchorX=0.0f,anchorY=0.0f;
    
    yhge::Json::Value anchorXValue=defineData[kPropertyNameAnchorX];
    if(!anchorXValue.isNull()){
        anchorX=anchorXValue.asDouble();
    }
    
    yhge::Json::Value anchorYValue=defineData[kPropertyNameAnchorY];
    if(!anchorYValue.isNull()){
        anchorY=anchorYValue.asDouble();
    }
    
    return ccp(anchorX, anchorY);
}

float IntegrativeNodeParser::getScaleX(const yhge::Json::Value& defineData,CCNode* parent)
{
    float scaleX=1.0f;
    
    yhge::Json::Value scaleXValue=defineData[kPropertyNameScaleX];
    if(!scaleXValue.isNull()){
        scaleX=scaleXValue.asDouble();
    }
    
    return scaleX;
}

float IntegrativeNodeParser::getScaleY(const yhge::Json::Value& defineData,CCNode* parent)
{
    float scaleY=1.0f;
    yhge::Json::Value scaleYValue=defineData[kPropertyNameScaleY];
    if(!scaleYValue.isNull()){
        scaleY=scaleYValue.asDouble();
    }
    
    return scaleY;
}

float IntegrativeNodeParser::getRotation(const yhge::Json::Value& defineData,CCNode* parent)
{
    float rotation=0.0f;
    
    yhge::Json::Value rotationValue=defineData[kPropertyNameRotation];
    if(!rotationValue.isNull()){
        rotation=rotationValue.asDouble();
    }
    return rotation;
}

bool IntegrativeNodeParser::getVisible(const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value visibleValue=defineData[kPropertyNameVisible];
    if(!visibleValue.isNull()){
        return visibleValue.asInt();
    }
    
    return true;
}

int IntegrativeNodeParser::getZOrder(const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value zOrderValue=defineData[kPropertyNameZOrder];
    if(!zOrderValue.isNull()){
        return zOrderValue.asInt();
    }
    return 0;
}

int IntegrativeNodeParser::getTag(const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value tagValue=defineData[kPropertyNameTag];
    if(!tagValue.isNull()){
        return tagValue.asInt();
    }
    
    return 0;
}

NS_CC_YHGUI_END