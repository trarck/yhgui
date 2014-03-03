#include "LabelPropertyParser.h"
#include "../UIBuilderConsts.h"

NS_CC_YHGUI_BEGIN

//=======================label 相关=======================//

void TextPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    
    yhge::Json::Value textValue=properties[kPropertyNameText];
    if(!textValue.isNull()){
        CCLabelProtocol* label=dynamic_cast<CCLabelProtocol*>(node);
        if (label) {
            label->setString(textValue.asCString());
        }
    }
}

void LabelColorPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value colorValue=properties[kPropertyNameColor];
    if(!colorValue.isNull()){
        
        CCNodeRGBA* nodeRgba=static_cast<CCNodeRGBA*>(node);
        
        ccColor3B color=getColor(colorValue);
        nodeRgba->setColor(color);
    }
}

//===========CCLabelTTF 相关===========//

void TTFTextPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    
    yhge::Json::Value textValue=properties[kPropertyNameText];
    if(!textValue.isNull()){
        CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
        label->setString(textValue.asCString());
    }
}

void TTFColorPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value colorValue=properties[kPropertyNameColor];
    if(!colorValue.isNull()){
        
        CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
        
        ccColor3B color=getColor(colorValue);
        label->setColor(color);
    }
}

void FontFamilyPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value fontFamilyValue=properties[kPropertyNameFontFamily];
    if(!fontFamilyValue.isNull()){
        CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
        label->setFontName(fontFamilyValue.asCString());
    }
}

void FontSizePropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value fontSizeValue=properties[kPropertyNameFontSize];
    if(!fontSizeValue.isNull()){
        CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
        label->setFontSize(fontSizeValue.asDouble());
    }
}

void HorizontalAlignmentPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
    
    yhge::Json::Value alignmentValue=properties[kPropertyNameHorizontalAlignment];
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

void VerticalAlignmentPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    CCLabelTTF* label=static_cast<CCLabelTTF*>(node);
    
    yhge::Json::Value alignmentValue=properties[kPropertyNameVerticalAlignment];
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

void BMFontTextPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value textValue=properties[kPropertyNameText];
    if(!textValue.isNull()){
        CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
        label->setString(textValue.asCString());
    }
}

void FntFilePropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value fntFileValue=properties[kPropertyNameFntFile];
    if(!fntFileValue.isNull()){
        CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
        label->setFntFile(fntFileValue.asCString());
    }
}

void BMFontColorPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value colorValue=properties[kPropertyNameColor];
    if(!colorValue.isNull()){
        
        CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
        
        ccColor3B color=getColor(colorValue);
        label->setColor(color);
    }
}

void AutomaticWidthPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value automaticWidthValue=properties[kPropertyNameAutomaticWidth];
    if(!automaticWidthValue.isNull()){
        CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
        label->setWidth(automaticWidthValue.asDouble());
    }
}

void BMFontAlignmentPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    CCLabelBMFont* label=static_cast<CCLabelBMFont*>(node);
    
    yhge::Json::Value alignmentValue=properties[kPropertyNameAlignment];
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

//===========CCLabelAtlas 相关===========//
void LabelAtlasTextPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value textValue=properties[kPropertyNameText];
    if(!textValue.isNull()){
        CCLabelAtlas* label=static_cast<CCLabelAtlas*>(node);
        label->setString(textValue.asCString());
    }
}

void LabelAtlasColorPropertyParser::parse(CCNode* node,const yhge::Json::Value& properties,CCNode* parent,UIBuilder* builder)
{
    yhge::Json::Value colorValue=properties[kPropertyNameColor];
    if(!colorValue.isNull()){
        
        CCLabelAtlas* label=static_cast<CCLabelAtlas*>(node);
        
        ccColor3B color=getColor(colorValue);
        label->setColor(color);
    }
}

NS_CC_YHGUI_END