//
//  UIBuilder.cpp
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#include "UIBuilder.h"
#include "SceneFactory.h"

NS_CC_BEGIN

UIBuilder::UIBuilder()
{
    
}

void UIBuilder::buildWithJSONData(const char* jsonString)
{
    unsigned int dataFormat=this->getDataFormat();
    
    switch (dataFormat) {
        case kUIDataFormatSimple:
            CCScene* scene=new scene();
            
            break;
        case kUIDataFormatHaveScene:
            CCScene* scene=SceneFactory.createScene("Scene Class");
            
            break;
        default:
            break;
    }
}

CCNode* UIBuilder::buildUI(Json::Value& json)
{
    return NULL;
}

CCNode* UIBuilder::createElement(Json::Value& defineData)
{
    CCNode* element=NULL;
    
    Json::Value type=defineData["type"];
    
    unsigned int nType=type.isIntegral() ? type.asUInt():this->typeToInteger(type.asString().c_str());
    
    switch (nType) {
        case kElementTypeNode:
            element=this->createNode(defineData);
            break;
        case kElementTypeSprite:
            element=this->createSprite(defineData);
            break;
        case kElementTypeLabel:
            element=this->createLabel(defineData);
            break;
        case kElementTypeLabelAtlas:
            element=this->createLabelAtlas(defineData);
            break;
        case kElementTypeLabelBMFont:
            element=this->createLabelBMFont(defineData);
            break;
        default:
            CCLOG("UIBuilder::createElemen unknow element type.");
            break;
    }
    return element;
    
//    Json::Value::Members members(json.getMemberNames());
//    for(Json::Value::Members::iterator it=members.begin();it!=members.end();++it){
//        const std::string &name=*it;
//        Json::Value value=json[name];
//    }
}

CCNode* UIBuilder::createElement(Json::Value& defineData,CCNode* parent)
{
    CCNode* element=this->createElement(defineData);
    
    Json::Value zOrderValue=defineData["zOrder"];
    int zOrder=0;
    if(!zOrderValue.isIntegral()){
        zOrder=zOrderValue.asInt();
    }
    
    Json::Value tagValue=defineData["tag"];
    int tag=0;
    if(tagValue.isIntegral()){
        tag=tagValue.asInt();
    }
    
    parent->addChild(element, zOrder, tag);
    return element;
}

CCNode* UIBuilder::createNode(Json::Value& defineData)
{
    CCNode* node=CCNode::create();

    this->setNodeAttributes(node, defineData["attributes"]);
    
    return node;
}

CCSprite* UIBuilder::createSprite(Json::Value& defineData)
{
    std::string asset=defineData["attributes"]["asset"].asString();
    
    CCSprite* sprite=CCSprite::create(asset.c_str());
    this->setSpriteAttributes(sprite, defineData["attributes"]);
    return sprite;
}

CCLabelTTF* UIBuilder::createLabel(Json::Value& defineData)
{
    CCLabelTTF* label=CCLabelTTF::create();
    this->setLabelAttributes(label, defineData["attributes"]);
    return label;
}

CCLabelAtlas* UIBuilder::createLabelAtlas(Json::Value& defineData)
{
    return NULL;
}

CCLabelBMFont* UIBuilder::createLabelBMFont(Json::Value& defineData)
{
    return NULL;
}

void UIBuilder::setNodeAttributes(CCNode* node,Json::Value& attributes)
{
 
    //parse position
    float x=0.0f,y=0.0f;
    
    Json::Value xValue=attributes["x"];
    if(!xValue.isNull()){
        x=xValue.asDouble();
    }
    
    Json::Value yValue=attributes["y"];
    if(!yValue.isNull()){
        y=yValue.asDouble();
    }
    
    node->setPosition(ccp(x,y));

    //parse size
    float width=0.0f,height=0.0f;
    
    Json::Value widthValue=attributes["width"];
    if(!widthValue.isNull()){
        width=widthValue.asDouble();
    }
    
    Json::Value heightValue=attributes["width"];
    if(!heightValue.isNull()){
        height=heightValue.asDouble();
    }

    node->setContentSize(CCSizeMake(width, height));
    
    //parse anchor
    float anchorX=0.0f,anchorY=0.0f;
    
    Json::Value anchorXValue=attributes["anchorX"];
    if(!anchorXValue.isNull()){
        anchorX=anchorXValue.asDouble();
    }
    
    Json::Value anchorYValue=attributes["anchorY"];
    if(!anchorYValue.isNull()){
        anchorY=anchorYValue.asDouble();
    }
    
    node->setAnchorPoint(ccp(anchorX, anchorY));
    
    //parse scale
    
    Json::Value scaleXValue=attributes["scaleX"];
    if(!scaleXValue.isNull()){
        float scaleX=scaleXValue.asDouble();
        node->setScaleX(scaleX);
    }
    
    Json::Value scaleYValue=attributes["scaleY"];
    if(!scaleYValue.isNull()){
        float scaleY=scaleYValue.asDouble();
        node->setScaleY(scaleY);
    }
    
    //parse rotation
    Json::Value rotationValue=attributes["rotation"];
    if(!rotationValue.isNull()){
        float rotation=rotationValue.asDouble();
        node->setRotation(rotation);
    }
    
    //parse visible
    Json::Value visibleValue=attributes["visible"];
    if(!visibleValue.isNull()){
        bool visible=visibleValue.asBool();
        node->setVisible(visible);
    }
   
}

void UIBuilder::setSpriteAttributes(CCSprite* sprite,Json::Value& attributes)
{
    this->setNodeAttributes(sprite,attributes);
    
    //parse flip
    Json::Value flipXValue=attributes["flipX"];
    if(!flipXValue.isNull()){
        float flipX=flipXValue.asDouble();
        sprite->setFlipX(flipX);
    }
    
    Json::Value flipYValue=attributes["flipY"];
    if(!flipYValue.isNull()){
        float flipY=flipYValue.asDouble();
        sprite->setFlipY(flipY);
    }
    
    //parse color
    Json::Value colorValue=attributes["color"];
    if(!colorValue.isNull()){
        ccColor3B color=ccc3(colorValue[0u].asUInt(), colorValue[1u].asUInt(), colorValue[2u].asUInt());
        sprite->setColor(color);
    }
}

void UIBuilder::setLabelAttributes(CCLabelTTF* label,Json::Value& attributes)
{
    this->setSpriteAttributes(label,attributes);
    //parse string
    std::string text=attributes["text"].asString();
    label->setString(text.c_str());
    
    //parse font
    Json::Value fontFamilyValue=attributes["fontFamily"];
    if(!fontFamilyValue.isNull()){
        std::string fontFamily=fontFamilyValue.asString();
        label->setFontName(fontFamily.c_str());
    }
    
    //parse font size
    Json::Value fontSizeValue=attributes["fontSize"];
    if(!fontSizeValue.isNull()){
        float fontSize=fontSizeValue.asDouble();
        label->setFontSize(fontSize);
    }  
   
}

unsigned int UIBuilder::getDataFormat()
{
    return kUIDataFormatSimple;
}

unsigned int UIBuilder::getDataVersion()
{
    
}


unsigned int UIBuilder::typeToInteger(const char* typeString)
{
    
}

NS_CC_END