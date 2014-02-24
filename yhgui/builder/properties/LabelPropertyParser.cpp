#include "LabelPropertyParser.h"

NS_CC_YHGUI_BEGIN

//=======================label 相关=======================//

void TextProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    
    yhge::Json::Value textValue=propertyValue["text"];
    if(!textValue.isNull()){
        CCLabelProtocol* label=dynamic_cast<CCLabelProtocol*>(node);
        if (label) {
            label->setString(textValue.asCString());
        }
    }
}

void LabelColorProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value colorValue=propertyValue["color"];
    if(!colorValue.isNull()){
        
        CCNodeRGBA* nodeRgba=static_cast<CCNodeRGBA*>(node);
        
        ccColor3B color=ccc3(colorValue[0u].asUInt(), colorValue[1u].asUInt(), colorValue[2u].asUInt());
        nodeRgba->setColor(color);
    }
}

//===========CCLabelTTF 相关===========//

void TTFTextProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    
    yhge::Json::Value textValue=propertyValue["text"];
    if(!textValue.isNull()){
        CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
        label->setString(textValue.asCString());
    }
}

void FontFamilyProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value fontFamilyValue=propertyValue["fontFamily"];
    if(!fontFamilyValue.isNull()){
        CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
        label->setFontName(fontFamilyValue.asCString());
    }
}

void FontSizeProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value fontSizeValue=propertyValue["fontSize"];
    if(!fontSizeValue.isNull()){
        CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
        label->setFontSize(fontSizeValue.asDouble());
    }
}

void HorizontalAlignmentProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
    
    yhge::Json::Value alignmentValue=propertyValue["horizontalAlignment"];
    if(!alignmentValue.isNull()){
        
        switch (alignmentValue.asInt()) {
            case kCCTextAlignmentLeft:
                label->setHorizontalAlignment(kCCTextAlignmentLeft);
                break;
            case kCCTextAlignmentCenter:
                label->setHorizontalAlignment(kCCTextAlignmentCenter);
                break;
            case kCCTextAlignmentRight:
                label->setHorizontalAlignment(kCCTextAlignmentRight);
                break;
            default:
                break;
        }
    }
}

void VerticalAlignmentProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
    
    yhge::Json::Value alignmentValue=propertyValue["verticalAlignment"];
    if(!alignmentValue.isNull()){
        
        switch (alignmentValue.asInt()) {
            case kCCVerticalTextAlignmentTop:
                label->setVerticalAlignment(kCCVerticalTextAlignmentTop);
                break;
            case kCCVerticalTextAlignmentCenter:
                label->setVerticalAlignment(kCCVerticalTextAlignmentCenter);
                break;
            case kCCVerticalTextAlignmentBottom:
                label->setVerticalAlignment(kCCVerticalTextAlignmentBottom);
                break;
            default:
                break;
        }
    }
}

//===========CCLabelBMFont 相关===========//

void BMFontTextProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value textValue=propertyValue["text"];
    if(!textValue.isNull()){
        CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
        label->setString(textValue.asCString());
    }
}

void FntFileProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value fntFileValue=propertyValue["fntFile"];
    if(!fntFileValue.isNull()){
        CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
        label->setFntFile(fntFileValue.asCString());
    }
}

void AutomaticWidthProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value automaticWidthValue=propertyValue["automaticWidth"];
    if(!automaticWidthValue.isNull()){
        CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
        label->setWidth(automaticWidthValue.asDouble());
    }
}

void BMFontAlignmentProperty::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
    
    yhge::Json::Value alignmentValue=propertyValue["alignment"];
    if(!alignmentValue.isNull()){

        switch (alignmentValue.asInt()) {
            case kCCTextAlignmentLeft:
                label->setAlignment(kCCTextAlignmentLeft);
                break;
            case kCCTextAlignmentCenter:
                label->setAlignment(kCCTextAlignmentCenter);
                break;
            case kCCTextAlignmentRight:
                label->setAlignment(kCCTextAlignmentRight);
                break;
            default:
                break;
        }
    }
}

NS_CC_YHGUI_END