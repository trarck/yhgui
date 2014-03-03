#include "ComponentPropertyParser.h"
#include <yhgui/Component.h>
#include <yhgui/control/Button.h>
#include <yhgui/control/NormalButton.h>
#include "../UIBuilderConsts.h"
#include "../UIBuilder.h"

NS_CC_YHGUI_BEGIN

//=======================component 相关=======================//

void ComponentNamePropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value nameValue=properties[kPropertyNameName];
    if(!nameValue.isNull()){
        
        Component* component=static_cast<Component*>(node);
        
        component->setName(nameValue.asString());
    }
}

void ComponentEnablePropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value enableValue=properties[kPropertyNameEnable];
    if(!enableValue.isNull()){
        
        Component* component=static_cast<Component*>(node);
        
        component->setEnabled(enableValue.asBool());
    }
}

void ComponentInteractiveBoundsPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value boundsValue=properties[kPropertyNameBounds];
    if(!boundsValue.isNull()){
        
        Component* component=static_cast<Component*>(node);
        
        component->setInteractiveBounds(getRect(boundsValue));
    }
}

void PreferredSizePropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    
    float width=0.0f,height=0.0f;
    
    yhge::Json::Value preferredWidthValue=properties[kPropertyNamePreferredWidth];
    if(!preferredWidthValue.isNull()){
        width=preferredWidthValue.asDouble();
    }
    
    yhge::Json::Value preferredHeightValue=properties[kPropertyNamePreferredHeight];
    if(!preferredHeightValue.isNull()){
        height=preferredHeightValue.asDouble();
    }
    
    
    Button* button=static_cast<Button*>(node);
    button->setPreferredSize(CCSizeMake(width, height));
    
}

void NormalButtonStatesPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value statesValue=properties[kPropertyNameStates];
    
    if (!statesValue.isNull()) {
        
        Component::State state;
        
        yhge::Json::Value stateValue;
        yhge::Json::Value colorValue;
        yhge::Json::Value backgroundValue;
        
        yhge::Json::Value::Members members=statesValue.getMemberNames();
        
        NormalButton* button=static_cast<NormalButton*>(node);
        
        for (yhge::Json::Value::Members::iterator iter=members.begin(); iter!=members.end(); ++iter) {
            
            stateValue=statesValue[*iter];
            if (!stateValue.isNull()) {
                
                state=getStateEnum(*iter);
                
                //set state color
                colorValue=stateValue[kPropertyNameColor];
                if (!colorValue.isNull()) {
                    button->setStateLabelColor(state, getColor(colorValue));
                }
                
                //set state background
                backgroundValue=stateValue[kPropertyNameBackground];
                if (!backgroundValue.isNull()) {
                    button->setStateBackground(state, backgroundValue.asString());
                }
            }
        }
    }
}

Component::State NormalButtonStatesPropertyParser::getStateEnum(const std::string& stateString)
{
    if (stateString==kPropertyNameNormal) {
        return Component::kNormal;
    }else if (stateString==kPropertyNamePressed){
        return Component::kPressed;
    }else if (stateString==kPropertyNameSelected){
        return Component::kSelected;
    }else if (stateString==kPropertyNameDisabled){
        return Component::kDisabled;
    }
    
    return Component::kNormal;
}

void NormalButtonLabelPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    NormalButton* button=static_cast<NormalButton*>(node);
    
    yhge::Json::Value labelValue=properties[kPropertyNameLabel];
    if (labelValue.isNull()) {
        //create defualt label
        button->setLabel(CCLabelTTF::create());
    }else{
        
        yhge::Json::Value typeValue=labelValue[kPropertyNameType];
        //直接使用label type
        if (typeValue.isIntegral()) {
            switch (typeValue.asUInt()) {
                    
                case NormalButton::kLabelTypeTTF:
                    button->setLabelTTF(
                                     labelValue[kPropertyNameText].asString(),
                                     labelValue[kPropertyNameFontFamily].asString(),
                                     (float)labelValue[kPropertyNameFontSize].asDouble()
                                    );
                    break;
                case NormalButton::kLabelTypeBMFont:
                    button->setLabelBMFont(
                                        labelValue[kPropertyNameText].asString(),
                                        labelValue[kPropertyNameFntFile].asString()
                                        );
                    break;
                case NormalButton::kLabelTypeAtlas:{
                    //TODO
                    break;
                }
                default:
                    break;
            }
        }else{
            //TODO support string type
        }
    }
}

NS_CC_YHGUI_END