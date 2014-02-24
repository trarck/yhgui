#include "NodePropertyParser.h"

NS_CC_YHGUI_BEGIN

//=======================node 相关=======================//

void PositionProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    float x=0.0f,y=0.0f;
    
    yhge::Json::Value xValue=propertyValue["x"];
    if(!xValue.isNull()){
        x=xValue.asDouble();
    }
    
    yhge::Json::Value yValue=propertyValue["y"];
    if(!yValue.isNull()){
        y=yValue.asDouble();
    }
    
    node->setPosition(ccp(x,y));
}

void SizeProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    //parse size
    float width=0.0f,height=0.0f;
    
    yhge::Json::Value widthValue=propertyValue["width"];
    if(!widthValue.isNull()){
        width=widthValue.asDouble();
    }
    
    yhge::Json::Value heightValue=propertyValue["width"];
    if(!heightValue.isNull()){
        height=heightValue.asDouble();
    }
    
    node->setContentSize(CCSizeMake(width, height));
}

void AnchorProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    float anchorX=0.0f,anchorY=0.0f;
    
    yhge::Json::Value anchorXValue=propertyValue["anchorX"];
    if(!anchorXValue.isNull()){
        anchorX=anchorXValue.asDouble();
    }
    
    yhge::Json::Value anchorYValue=propertyValue["anchorY"];
    if(!anchorYValue.isNull()){
        anchorY=anchorYValue.asDouble();
    }
    
    node->setAnchorPoint(ccp(anchorX, anchorY));
}

void ScaleProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value scaleXValue=propertyValue["scaleX"];
    if(!scaleXValue.isNull()){
        float scaleX=scaleXValue.asDouble();
        node->setScaleX(scaleX);
    }
    
    yhge::Json::Value scaleYValue=propertyValue["scaleY"];
    if(!scaleYValue.isNull()){
        float scaleY=scaleYValue.asDouble();
        node->setScaleY(scaleY);
    }
}

void RotationProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    //parse rotation
    yhge::Json::Value rotationValue=propertyValue["rotation"];
    if(!rotationValue.isNull()){
        float rotation=rotationValue.asDouble();
        node->setRotation(rotation);
    }
}

void VisibleProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    //parse visible
    yhge::Json::Value visibleValue=propertyValue["visible"];
    if(!visibleValue.isNull()){
        bool visible=visibleValue.asBool();
        node->setVisible(visible);
    }
}

void ZOrderProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value zOrderValue=propertyValue["zOrder"];
    if(!zOrderValue.isNull()){
        node->setZOrder(zOrderValue.asInt());
    }
}

void TagProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value tagValue=propertyValue["tag"];
    if(!tagValue.isNull()){
        node->setTag(tagValue.asInt());
    }
}

//=======================color 相关=======================//
void ColorProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value colorValue=propertyValue["color"];
    if(!colorValue.isNull()){
        
        CCRGBAProtocol* rgbaNode=dynamic_cast<CCRGBAProtocol*>(node);
        if (rgbaNode) {
            ccColor3B color=ccc3(colorValue[0u].asUInt(), colorValue[1u].asUInt(), colorValue[2u].asUInt());
            rgbaNode->setColor(color);
        }
    }
}


//=======================sprite 相关=======================//

    
void FlipProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    CCSprite* sprite=static_cast<CCSprite*>(node);
    
    yhge::Json::Value flipXValue=propertyValue["flipX"];
    if(!flipXValue.isNull()){
        float flipX=flipXValue.asDouble();
        sprite->setFlipX(flipX);
    }
    
    yhge::Json::Value flipYValue=propertyValue["flipY"];
    if(!flipYValue.isNull()){
        float flipY=flipYValue.asDouble();
        sprite->setFlipY(flipY);
    }
    
}

void SpriteColorProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value colorValue=propertyValue["color"];
    if(!colorValue.isNull()){
        
        CCSprite* sprite=static_cast<CCSprite*>(node);
        
        ccColor3B color=ccc3(colorValue[0u].asUInt(), colorValue[1u].asUInt(), colorValue[2u].asUInt());
        sprite->setColor(color);
    }
    
}

void TexutreProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value textureValue=propertyValue["texture"];
    if(!textureValue.isNull()){
        
        CCSprite* sprite=static_cast<CCSprite*>(node);
        
        CCTexture2D* texture=CCTextureCache::sharedTextureCache()->addImage(textureValue.asCString());
        if (texture)
        {
            CCRect rect = CCRectZero;
            rect.size = texture->getContentSize();
            sprite->setTexture(texture);
            sprite->setTextureRect(rect);
        }
    }
}

NS_CC_YHGUI_END