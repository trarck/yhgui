//
//  UIBuilder.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_UIBUILDER_H_
#define COCOS_YHGUI_BUILDER_UIBUILDER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include "../YHGUIMacros.h"
#include "ElementCreator.h"

NS_CC_YHGUI_BEGIN

enum{
    kUIDataFormatSimple=1,
    kUIDataFormatHaveScene
};

enum{
    kElementTypeNode=1,
    kElementTypeSprite,
    kElementTypeLabel,//CCLableTTF
    kElementTypeLabelAtlas,
    kElementTypeLabelBMFont,
    kElementTypeButton
};

class UIBuilder:public CCObject
{
public:
    
    UIBuilder();
    
    ~UIBuilder();
    
    bool init();
    
    CCNode* buildWithJSONFile(const char* jsonFile);
    
    CCNode* buildWithJSONData(const char* jsonString);
    
    CCNode* buildUI(const yhge::Json::Value& json);
    
    CCNode* createElement(const yhge::Json::Value& defineData);
    
    CCNode* createElement(const yhge::Json::Value& defineData,CCNode* parent);
    
    void createChildren(const yhge::Json::Value& children,CCNode* parent);
    
    CCNode* createNode(const yhge::Json::Value& defineData);
    
    CCSprite* createSprite(const yhge::Json::Value& defineData);
    
    CCLabelTTF* createLabel(const yhge::Json::Value& defineData);
    
    CCLabelAtlas* createLabelAtlas(const yhge::Json::Value& defineData);
    
    CCLabelBMFont* createLabelBMFont(const yhge::Json::Value& defineData);
    
    unsigned int getDataFormat(yhge::Json::Value root);
    
    unsigned int getDataVersion(yhge::Json::Value root);

protected:
    
    
    ElementCreator* getElementCreator(const yhge::Json::Value& elementType);
    ElementCreator* getElementCreator(int elementType);
    ElementCreator* getElementCreator(const std::string& elementType);
    
    unsigned int typeToInteger(const std::string& typeString);
    
    void setNodeAttributes(CCNode* node,const yhge::Json::Value& attributes);
    
    void setSpriteAttributes(CCSprite* sprite,const yhge::Json::Value& attributes);
    
    void setLabelAttributes(CCLabelTTF* label,const yhge::Json::Value& attributes);

protected:
    
    CCDictionary* m_elementCreaters;
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_UIBUILDER_H_
