//
//  UIBuilder.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef UI_Builder_H_
#define UI_Builder_H_

#include "cocos2d.h"
#include "json/json.h"

USING_NS_CC;

NS_YH_BEGIN

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
    
    void buildWithJSONFile(const char* jsonFile);
    
    void buildWithJSONData(const char* jsonString);
    
    unsigned int getDataFormat();
    
    unsigned int getDataVersion();
    
    CCNode* buildUI(Json::Value& json);
    
    CCNode* createElement(Json::Value& defineData);
    
    CCNode* createElement(Json::Value& defineData,CCNode* parent);
    
    CCNode* createNode(Json::Value& defineData);
    
    CCSprite* createSprite(Json::Value& defineData);
    
    CCLabelTTF* createLabel(Json::Value& defineData);
    
    CCLabelAtlas* createLabelAtlas(Json::Value& defineData);
    
    CCLabelBMFont* createLabelBMFont(Json::Value& defineData);

protected:
    
    unsigned int typeToInteger(const char* typeString);
    
    void setNodeAttributes(CCNode* node,Json::Value& attributes);
    
    void setSpriteAttributes(CCSprite* sprite,Json::Value& attributes);
    
    void setLabelAttributes(CCLabelTTF* label,Json::Value& attributes);

private:
    
    
};

NS_YH_END

#endif // UI_Builder_H_
