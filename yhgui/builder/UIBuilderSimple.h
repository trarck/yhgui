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
#include <yhge/Jsoncpp/json.h>
#include "../YHGUIMacros.h"

NS_CC_YHGUI_BEGIN


class UIBuilderSimple:public CCObject
{
public:
    
    UIBuilderSimple();
    
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
    
    unsigned int typeToInteger(const std::string& typeString);
    
    void setNodeAttributes(CCNode* node,const yhge::Json::Value& attributes);
    
    void setSpriteAttributes(CCSprite* sprite,const yhge::Json::Value& attributes);
    
    void setLabelAttributes(CCLabelTTF* label,const yhge::Json::Value& attributes);
    
public:
    
    enum DataFormate{
        kUIDataFormatSimple=1,
        kUIDataFormatHaveScene
    };
    
    enum ElementType{
        kElementTypeNode=1,
        kElementTypeSprite,
        kElementTypeLabel,//CCLableTTF
        kElementTypeLabelAtlas,
        kElementTypeLabelBMFont,
        kElementTypeButton
    };
    
private:
    
    
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_UIBUILDERSIMPLE_H_
