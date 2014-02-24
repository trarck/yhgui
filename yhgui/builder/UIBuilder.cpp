//
//  UIBuilder.cpp
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#include "UIBuilder.h"

NS_CC_YHGUI_BEGIN

UIBuilder::UIBuilder()
:m_elementCreaters(NULL)
{
    
}

UIBuilder::~UIBuilder()
{
    CC_SAFE_RELEASE_NULL(m_elementCreaters);
}

bool UIBuilder::init()
{
    m_elementCreaters=new CCDictionary();
    return true;
}

CCNode* UIBuilder::buildWithJSONFile(const char* jsonFile)
{
    unsigned long size = 0;
    unsigned char * pBytes=CCFileUtils::sharedFileUtils()->getFileData(jsonFile, "rb", &size);
    
    CCNode* root=buildWithJSONData((char*)pBytes);
    
    CC_SAFE_DELETE_ARRAY(pBytes);
    
    return  root;
}

CCNode* UIBuilder::buildWithJSONData(const char* jsonString)
{
    yhge::Json::Reader reader;
    yhge::Json::Value root;
    
    bool parsingSuccessful=reader.parse(jsonString, root,false);
    if (parsingSuccessful) {
        return buildUI(root);
    }
    
    return NULL;
}

CCNode* UIBuilder::buildUI(const yhge::Json::Value& json)
{
    unsigned int dataVersion=this->getDataVersion(json);
    
    CCNode* root=this->createElement(json);
    
    
    return root;
}

CCNode* UIBuilder::createElement(const yhge::Json::Value& defineData)
{
    CCNode* element=NULL;
    
    yhge::Json::Value type=defineData["type"];
    
    //create element
    ElementCreator* elementCreator=getElementCreator(type);
    
    CCNode* elem=elementCreator->create(defineData);
    
    //set property
    
    
    
    //create children
    this->createChildren(defineData["children"], element);
    
    return element;
}

CCNode* UIBuilder::createElement(const yhge::Json::Value& defineData,CCNode* parent)
{
    CCNode* element=this->createElement(defineData);
    
    parent->addChild(element);
    return element;
}

void UIBuilder::createChildren(const yhge::Json::Value& children,CCNode* parent)
{
    if (!children.isNull() && parent) {
        CCNode* child=NULL;
        for (int i=0; i<children.size(); ++i) {
            child=this->createElement(children[i]);
            parent->addChild(child);
        }
    }
}

CCNode* UIBuilder::createNode(const yhge::Json::Value& defineData)
{
    CCNode* node=CCNode::create();

    this->setNodeAttributes(node, defineData["attributes"]);
    
    return node;
}

CCSprite* UIBuilder::createSprite(const yhge::Json::Value& defineData)
{
    std::string asset=defineData["attributes"]["asset"].asString();
    
    CCSprite* sprite=CCSprite::create(asset.c_str());
    this->setSpriteAttributes(sprite, defineData["attributes"]);
    return sprite;
}

CCLabelTTF* UIBuilder::createLabel(const yhge::Json::Value& defineData)
{
    CCLabelTTF* label=CCLabelTTF::create();
    this->setLabelAttributes(label, defineData["attributes"]);
    return label;
}

CCLabelAtlas* UIBuilder::createLabelAtlas(const yhge::Json::Value& defineData)
{
    return NULL;
}

CCLabelBMFont* UIBuilder::createLabelBMFont(const yhge::Json::Value& defineData)
{
    return NULL;
}

void UIBuilder::setNodeAttributes(CCNode* node,const yhge::Json::Value& attributes)
{
 
    //parse position
    float x=0.0f,y=0.0f;
    
    yhge::Json::Value xValue=attributes["x"];
    if(!xValue.isNull()){
        x=xValue.asDouble();
    }
    
    yhge::Json::Value yValue=attributes["y"];
    if(!yValue.isNull()){
        y=yValue.asDouble();
    }
    
    node->setPosition(ccp(x,y));

    //parse size
    float width=0.0f,height=0.0f;
    
    yhge::Json::Value widthValue=attributes["width"];
    if(!widthValue.isNull()){
        width=widthValue.asDouble();
    }
    
    yhge::Json::Value heightValue=attributes["width"];
    if(!heightValue.isNull()){
        height=heightValue.asDouble();
    }

    node->setContentSize(CCSizeMake(width, height));
    
    //parse anchor
    float anchorX=0.0f,anchorY=0.0f;
    
    yhge::Json::Value anchorXValue=attributes["anchorX"];
    if(!anchorXValue.isNull()){
        anchorX=anchorXValue.asDouble();
    }
    
    yhge::Json::Value anchorYValue=attributes["anchorY"];
    if(!anchorYValue.isNull()){
        anchorY=anchorYValue.asDouble();
    }
    
    node->setAnchorPoint(ccp(anchorX, anchorY));
    
    //parse scale
    
    yhge::Json::Value scaleXValue=attributes["scaleX"];
    if(!scaleXValue.isNull()){
        float scaleX=scaleXValue.asDouble();
        node->setScaleX(scaleX);
    }
    
    yhge::Json::Value scaleYValue=attributes["scaleY"];
    if(!scaleYValue.isNull()){
        float scaleY=scaleYValue.asDouble();
        node->setScaleY(scaleY);
    }
    
    //parse rotation
    yhge::Json::Value rotationValue=attributes["rotation"];
    if(!rotationValue.isNull()){
        float rotation=rotationValue.asDouble();
        node->setRotation(rotation);
    }
    
    //parse visible
    yhge::Json::Value visibleValue=attributes["visible"];
    if(!visibleValue.isNull()){
        bool visible=visibleValue.asBool();
        node->setVisible(visible);
    }
   
    yhge::Json::Value zOrderValue=attributes["zOrder"];
    if(!zOrderValue.isNull()){
        node->setZOrder(zOrderValue.asInt());
    }
    
    yhge::Json::Value tagValue=attributes["tag"];
    if(!tagValue.isNull()){
        node->setTag(tagValue.asInt());
    }
    
}

void UIBuilder::setSpriteAttributes(CCSprite* sprite,const yhge::Json::Value& attributes)
{
    this->setNodeAttributes(sprite,attributes);
    
    //parse flip
    yhge::Json::Value flipXValue=attributes["flipX"];
    if(!flipXValue.isNull()){
        float flipX=flipXValue.asDouble();
        sprite->setFlipX(flipX);
    }
    
    yhge::Json::Value flipYValue=attributes["flipY"];
    if(!flipYValue.isNull()){
        float flipY=flipYValue.asDouble();
        sprite->setFlipY(flipY);
    }
    
    //parse color
    yhge::Json::Value colorValue=attributes["color"];
    if(!colorValue.isNull()){
        ccColor3B color=ccc3(colorValue[0u].asUInt(), colorValue[1u].asUInt(), colorValue[2u].asUInt());
        sprite->setColor(color);
    }
}

void UIBuilder::setLabelAttributes(CCLabelTTF* label,const yhge::Json::Value& attributes)
{
    this->setSpriteAttributes(label,attributes);
    //parse string
    std::string text=attributes["text"].asString();
    label->setString(text.c_str());
    
    //parse font
    yhge::Json::Value fontFamilyValue=attributes["fontFamily"];
    if(!fontFamilyValue.isNull()){
        std::string fontFamily=fontFamilyValue.asString();
        label->setFontName(fontFamily.c_str());
    }
    
    //parse font size
    yhge::Json::Value fontSizeValue=attributes["fontSize"];
    if(!fontSizeValue.isNull()){
        float fontSize=fontSizeValue.asDouble();
        label->setFontSize(fontSize);
    }  
   
}

unsigned int UIBuilder::getDataFormat(yhge::Json::Value root)
{
    return kUIDataFormatSimple;
}

unsigned int UIBuilder::getDataVersion(yhge::Json::Value root)
{
    return root["version"].asUInt();
}


ElementCreator* UIBuilder::getElementCreator(const yhge::Json::Value& elementType)
{
    if (elementType.isIntegral()) {
        return static_cast<ElementCreator*>(m_elementCreaters->objectForKey(elementType.asInt()));
    }else if(elementType.isString()){
        return static_cast<ElementCreator*>(m_elementCreaters->objectForKey(elementType.asString()));
    }else{
        CCAssert(false, "UIBuilder::getElementCreator unkonw elementType");
    }
}

ElementCreator* UIBuilder::getElementCreator(int elementType)
{
    return static_cast<ElementCreator*>(m_elementCreaters->objectForKey(elementType));
}

ElementCreator* UIBuilder::getElementCreator(const std::string& elementType)
{
    return static_cast<ElementCreator*>(m_elementCreaters->objectForKey(elementType));
}

unsigned int UIBuilder::typeToInteger(const std::string& typeString)
{
    if (strcmp(typeString.c_str(), "Node")==0) {
        return kElementTypeNode;
    }else if (strcmp(typeString.c_str(), "Sprite")==0){
        return kElementTypeSprite;
    }
    
    return 0;
}

NS_CC_YHGUI_END