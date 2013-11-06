//
//  UIBuilderSimple.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_UIBUILDERSIMPLE_H_
#define COCOS_YHGUI_BUILDER_UIBUILDERSIMPLE_H_

#include "cocos2d.h"
#include "json/json.h"
#include "YHGUIMacros.h"

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

class UIBuilderSimple:public CCObject
{
public:
    
    UIBuilderSimple();
    
    CCNode* buildWithJSONFile(const char* jsonFile);
    
    CCNode* buildWithJSONData(const char* jsonString);
    
    CCNode* buildUI(Json::Value& json);
    
    CCNode* createElement(Json::Value& defineData);
    
    CCNode* createElement(Json::Value& defineData,CCNode* parent);
    
    void createChildren(Json::Value& children,CCNode* parent);
    
    CCNode* createNode(Json::Value& defineData);
    
    CCSprite* createSprite(Json::Value& defineData);
    
    CCLabelTTF* createLabel(Json::Value& defineData);
    
    CCLabelAtlas* createLabelAtlas(Json::Value& defineData);
    
    CCLabelBMFont* createLabelBMFont(Json::Value& defineData);
    
    unsigned int getDataFormat(Json::Value root);
    
    unsigned int getDataVersion(Json::Value root);

protected:
    
    unsigned int typeToInteger(const std::string& typeString);
    
    void setNodeAttributes(CCNode* node,Json::Value& attributes);
    
    void setSpriteAttributes(CCSprite* sprite,Json::Value& attributes);
    
    void setLabelAttributes(CCLabelTTF* label,Json::Value& attributes);

private:
    
    
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_UIBUILDERSIMPLE_H_
