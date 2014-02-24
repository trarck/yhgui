#include "NodePropertyParser.h"

NS_CC_YHGUI_BEGIN

void NodePropertyParser::parse(CCNode* node,const yhge::Json::Value& defineData,CCNode* parent)
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

CCPoint NodePropertyParser::getPosition(const yhge::Json::Value& defineData,CCNode* parent)
{
    float x=0.0f,y=0.0f;
    
    yhge::Json::Value xValue=defineData["x"];
    if(!xValue.isNull()){
        x=xValue.asDouble();
    }
    
    yhge::Json::Value yValue=defineData["y"];
    if(!yValue.isNull()){
        y=yValue.asDouble();
    }
    
    return ccp(x,y);
}

CCSize NodePropertyParser::getSize(const yhge::Json::Value& defineData,CCNode* parent)
{
    float width=0.0f,height=0.0f;
    
    yhge::Json::Value widthValue=defineData["width"];
    if(!widthValue.isNull()){
        width=widthValue.asDouble();
    }
    
    yhge::Json::Value heightValue=defineData["width"];
    if(!heightValue.isNull()){
        height=heightValue.asDouble();
    }

    return CCSizeMake(width, height);
}

CCPoint NodePropertyParser::getAnchor(const yhge::Json::Value& defineData,CCNode* parent)
{
    float anchorX=0.0f,anchorY=0.0f;
    
    yhge::Json::Value anchorXValue=defineData["anchorX"];
    if(!anchorXValue.isNull()){
        anchorX=anchorXValue.asDouble();
    }
    
    yhge::Json::Value anchorYValue=defineData["anchorY"];
    if(!anchorYValue.isNull()){
        anchorY=anchorYValue.asDouble();
    }
    
    return ccp(anchorX, anchorY);
}

float NodePropertyParser::getScaleX(const yhge::Json::Value& defineData,CCNode* parent)
{
    float scaleX=1.0f;
    
    yhge::Json::Value scaleXValue=defineData["scaleX"];
    if(!scaleXValue.isNull()){
        scaleX=scaleXValue.asDouble();
    }
    
    return scaleX;
}

float NodePropertyParser::getScaleY(const yhge::Json::Value& defineData,CCNode* parent)
{
    float scaleY=1.0f;
    yhge::Json::Value scaleYValue=defineData["scaleY"];
    if(!scaleYValue.isNull()){
        scaleY=scaleYValue.asDouble();
    }
    
    return scaleY;
}

float NodePropertyParser::getRotation(const yhge::Json::Value& defineData,CCNode* parent)
{
    float rotation=0.0f;
    
    yhge::Json::Value rotationValue=defineData["rotation"];
    if(!rotationValue.isNull()){
        rotation=rotationValue.asDouble();
    }
    return rotation;
}

bool NodePropertyParser::getVisible(const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value zOrderValue=defineData["zOrder"];
    if(!zOrderValue.isNull()){
        return zOrderValue.asInt();
    }
    
    return true;
}

int NodePropertyParser::getZOrder(const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value zOrderValue=defineData["zOrder"];
    if(!zOrderValue.isNull()){
        return zOrderValue.asInt();
    }
    return 0;
}

int NodePropertyParser::getTag(const yhge::Json::Value& defineData,CCNode* parent)
{
    yhge::Json::Value tagValue=defineData["tag"];
    if(!tagValue.isNull()){
        return tagValue.asInt();
    }
    
    return 0;
}

NS_CC_YHGUI_END