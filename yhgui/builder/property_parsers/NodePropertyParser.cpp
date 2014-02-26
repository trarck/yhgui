#include "NodePropertyParser.h"
#include "../UIBuilderConsts.h"

NS_CC_YHGUI_BEGIN

//=======================node 相关=======================//

void PositionPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    float x=0.0f,y=0.0f;
    
    yhge::Json::Value xValue=propertyValue[kPropertyNameX];
    if(!xValue.isNull()){
        x=xValue.asDouble();
    }
    
    yhge::Json::Value yValue=propertyValue[kPropertyNameY];
    if(!yValue.isNull()){
        y=yValue.asDouble();
    }
    
    node->setPosition(ccp(x,y));
}

void SizePropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    //parse size
    float width=0.0f,height=0.0f;
    
    yhge::Json::Value widthValue=propertyValue[kPropertyNameWidth];
    if(!widthValue.isNull()){
        width=widthValue.asDouble();
    }
    
    yhge::Json::Value heightValue=propertyValue[kPropertyNameHeight];
    if(!heightValue.isNull()){
        height=heightValue.asDouble();
    }
    
    node->setContentSize(CCSizeMake(width, height));
}

void AnchorPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    float anchorX=0.0f,anchorY=0.0f;
    
    yhge::Json::Value anchorXValue=propertyValue[kPropertyNameX];
    if(!anchorXValue.isNull()){
        anchorX=anchorXValue.asDouble();
    }
    
    yhge::Json::Value anchorYValue=propertyValue[kPropertyNameY];
    if(!anchorYValue.isNull()){
        anchorY=anchorYValue.asDouble();
    }
    
    node->setAnchorPoint(ccp(anchorX, anchorY));
}

void ScalePropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value scaleXValue=propertyValue[kPropertyNameX];
    if(!scaleXValue.isNull()){
        float scaleX=scaleXValue.asDouble();
        node->setScaleX(scaleX);
    }
    
    yhge::Json::Value scaleYValue=propertyValue[kPropertyNameY];
    if(!scaleYValue.isNull()){
        float scaleY=scaleYValue.asDouble();
        node->setScaleY(scaleY);
    }
}

void RotationPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    //parse rotation
    yhge::Json::Value rotationValue=propertyValue[kPropertyNameRotation];
    if(!rotationValue.isNull()){
        float rotation=rotationValue.asDouble();
        node->setRotation(rotation);
    }
}

void VisiblePropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    //parse visible
    yhge::Json::Value visibleValue=propertyValue[kPropertyNameVisible];
    if(!visibleValue.isNull()){
        bool visible=visibleValue.asBool();
        node->setVisible(visible);
    }
}

void ZOrderPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value zOrderValue=propertyValue[kPropertyNameZOrder];
    if(!zOrderValue.isNull()){
        node->setZOrder(zOrderValue.asInt());
    }
}

void TagPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value tagValue=propertyValue[kPropertyNameTag];
    if(!tagValue.isNull()){
        node->setTag(tagValue.asInt());
    }
}

//=======================color 相关=======================//
void ColorPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value colorValue=propertyValue[kPropertyNameColor];
    if(!colorValue.isNull()){
        
        CCRGBAProtocol* rgbaNode=dynamic_cast<CCRGBAProtocol*>(node);
        if (rgbaNode) {
            ccColor3B color=ccc3(colorValue[0u].asUInt(), colorValue[1u].asUInt(), colorValue[2u].asUInt());
            rgbaNode->setColor(color);
        }
    }
}


//=======================sprite 相关=======================//

    
void FlipPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    CCSprite* sprite=static_cast<CCSprite*>(node);
    
    yhge::Json::Value flipXValue=propertyValue[kPropertyNameX];
    if(!flipXValue.isNull()){
        float flipX=flipXValue.asDouble();
        sprite->setFlipX(flipX);
    }
    
    yhge::Json::Value flipYValue=propertyValue[kPropertyNameY];
    if(!flipYValue.isNull()){
        float flipY=flipYValue.asDouble();
        sprite->setFlipY(flipY);
    }
    
}

void SpriteColorPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value colorValue=propertyValue[kPropertyNameColor];
    if(!colorValue.isNull()){
        
        CCSprite* sprite=static_cast<CCSprite*>(node);
        
        ccColor3B color=ccc3(colorValue[0u].asUInt(), colorValue[1u].asUInt(), colorValue[2u].asUInt());
        sprite->setColor(color);
    }
    
}

void TexutrePropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value textureValue=propertyValue[kPropertyNameAsset];
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