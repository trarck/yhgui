//
//  UIBuilderSimple.cpp
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#include "UIBuilderSimple.h"

NS_CC_YHGUI_BEGIN

UIBuilderSimple::UIBuilderSimple()
{
    
}

CCNode* UIBuilderSimple::buildWithJSONFile(const char* jsonFile)
{
    unsigned long size = 0;
    unsigned char * pBytes=CCFileUtils::sharedFileUtils()->getFileData(jsonFile, "rb", &size);
    
    CCNode* root=buildWithJSONData((char*)pBytes);
    
    CC_SAFE_DELETE_ARRAY(pBytes);
    
    return  root;
}

CCNode* UIBuilderSimple::buildWithJSONData(const char* jsonString)
{
    Json::Reader reader;
    Json::Value root;
    
    bool parsingSuccessful=reader.parse(jsonString, root,false);
    if (parsingSuccessful) {
        return buildUI(root);
    }
    
    return NULL;
}

CCNode* UIBuilderSimple::buildUI(Json::Value& json)
{
    unsigned int dataVersion=this->getDataVersion(json);
    
    CCNode* root=this->createElement(json);
    
    
    return root;
}

CCNode* UIBuilderSimple::createElement(Json::Value& defineData)
{
    CCNode* element=NULL;
    
    Json::Value type=defineData["type"];
    
    unsigned int nType=type.isIntegral() ? type.asUInt():this->typeToInteger(type.asString());
    
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
            CCLOG("UIBuilderSimple::createElemen unknow element type.");
            break;
    }
    
    //create children
    this->createChildren(defineData["children"], element);
    
    return element;
}

CCNode* UIBuilderSimple::createElement(Json::Value& defineData,CCNode* parent)
{
    CCNode* element=this->createElement(defineData);
    
    parent->addChild(element);
    return element;
}

void UIBuilderSimple::createChildren(Json::Value& children,CCNode* parent)
{
    if (!children.isNull() && parent) {
        CCNode* child=NULL;
        for (int i=0; i<children.size(); ++i) {
            child=this->createElement(children[i]);
            parent->addChild(child);
        }
    }
}

CCNode* UIBuilderSimple::createNode(Json::Value& defineData)
{
    CCNode* node=CCNode::create();

    this->setNodeAttributes(node, defineData["attributes"]);
    
    return node;
}

CCSprite* UIBuilderSimple::createSprite(Json::Value& defineData)
{
    std::string asset=defineData["attributes"]["asset"].asString();
    
    CCSprite* sprite=CCSprite::create(asset.c_str());
    this->setSpriteAttributes(sprite, defineData["attributes"]);
    return sprite;
}

CCLabelTTF* UIBuilderSimple::createLabel(Json::Value& defineData)
{
    CCLabelTTF* label=CCLabelTTF::create();
    this->setLabelAttributes(label, defineData["attributes"]);
    return label;
}

CCLabelAtlas* UIBuilderSimple::createLabelAtlas(Json::Value& defineData)
{
    return NULL;
}

CCLabelBMFont* UIBuilderSimple::createLabelBMFont(Json::Value& defineData)
{
    return NULL;
}

void UIBuilderSimple::setNodeAttributes(CCNode* node,Json::Value& attributes)
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
   
    Json::Value zOrderValue=attributes["zOrder"];
    if(!zOrderValue.isNull()){
        node->setZOrder(zOrderValue.asInt());
    }
    
    Json::Value tagValue=attributes["tag"];
    if(!tagValue.isNull()){
        node->setTag(tagValue.asInt());
    }
    
}

void UIBuilderSimple::setSpriteAttributes(CCSprite* sprite,Json::Value& attributes)
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

void UIBuilderSimple::setLabelAttributes(CCLabelTTF* label,Json::Value& attributes)
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

unsigned int UIBuilderSimple::getDataFormat(Json::Value root)
{
    return kUIDataFormatSimple;
}

unsigned int UIBuilderSimple::getDataVersion(Json::Value root)
{
    return root["version"].asUInt();
}


unsigned int UIBuilderSimple::typeToInteger(const std::string& typeString)
{
    if (strcmp(typeString.c_str(), "Node")==0) {
        return kElementTypeNode;
    }else if (strcmp(typeString.c_str(), "Sprite")==0){
        return kElementTypeSprite;
    }
    
    return 0;
}

NS_CC_YHGUI_END