#include "LabelPropertyParser.h"
#include "../UIBuilderConsts.h"

NS_CC_YHGUI_BEGIN

//=======================label 相关=======================//

void TextPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    
    yhge::Json::Value textValue=propertyValue[kPropertyNameText];
    if(!textValue.isNull()){
        CCLabelProtocol* label=dynamic_cast<CCLabelProtocol*>(node);
        if (label) {
            label->setString(textValue.asCString());
        }
    }
}

void LabelColorPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value colorValue=propertyValue[kPropertyNameColor];
    if(!colorValue.isNull()){
        
        CCNodeRGBA* nodeRgba=static_cast<CCNodeRGBA*>(node);
        
        ccColor3B color=ccc3(colorValue[0u].asUInt(), colorValue[1u].asUInt(), colorValue[2u].asUInt());
        nodeRgba->setColor(color);
    }
}

//===========CCLabelTTF 相关===========//

void TTFTextPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    
    yhge::Json::Value textValue=propertyValue[kPropertyNameText];
    if(!textValue.isNull()){
        CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
        label->setString(textValue.asCString());
    }
}

void FontFamilyPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value fontFamilyValue=propertyValue[kPropertyNameFontFamily];
    if(!fontFamilyValue.isNull()){
        CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
        label->setFontName(fontFamilyValue.asCString());
    }
}

void FontSizePropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value fontSizeValue=propertyValue[kPropertyNameFontSize];
    if(!fontSizeValue.isNull()){
        CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
        label->setFontSize(fontSizeValue.asDouble());
    }
}

void HorizontalAlignmentPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
    
    yhge::Json::Value alignmentValue=propertyValue[kPropertyNameHorizontalAlignment];
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

void VerticalAlignmentPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
    
    yhge::Json::Value alignmentValue=propertyValue[kPropertyNameVerticalAlignment];
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

void BMFontTextPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value textValue=propertyValue[kPropertyNameText];
    if(!textValue.isNull()){
        CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
        label->setString(textValue.asCString());
    }
}

void FntFilePropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value fntFileValue=propertyValue[kPropertyNameFntFile];
    if(!fntFileValue.isNull()){
        CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
        label->setFntFile(fntFileValue.asCString());
    }
}

void AutomaticWidthPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    yhge::Json::Value automaticWidthValue=propertyValue[kPropertyNameAutomaticWidth];
    if(!automaticWidthValue.isNull()){
        CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
        label->setWidth(automaticWidthValue.asDouble());
    }
}

void BMFontAlignmentPropertyParser::parse(CCNode* node,const yhge::Json::Value& propertyValue,CCNode* parent)
{
    CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
    
    yhge::Json::Value alignmentValue=propertyValue[kPropertyNameAlignment];
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