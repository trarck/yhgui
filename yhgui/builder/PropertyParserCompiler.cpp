#include "PropertyParserCompiler.h"
#include "ElementParser.h"
#include "UIBuilderConsts.h"
#include "property_parsers/NodePropertyParser.h"
#include "property_parsers/LabelPropertyParser.h"
#include "property_parsers/ComponentPropertyParser.h"

NS_CC_YHGUI_BEGIN

void PropertyParserCompiler::compileNodeParser(ComponentialElementParser* elementParser)
{
    elementParser->registerPropertyParser(kPropertyNamePosition,PositionPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameSize,SizePropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameAnchor,AnchorPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameScale,ScalePropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameRotation,RotationPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameVisible,VisiblePropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameZOrder,ZOrderPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameTag,TagPropertyParser::create());
}

void PropertyParserCompiler::compileSpriteParser(ComponentialElementParser* elementParser)
{
    elementParser->registerPropertyParser(kPropertyNameColor,ColorPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameFlip,SpriteColorPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameAsset,TexutrePropertyParser::create());
}

void PropertyParserCompiler::compileLabelTTFParser(ComponentialElementParser* elementParser)
{
    elementParser->registerPropertyParser(kPropertyNameFontFamily,FontFamilyPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameFontSize,FontSizePropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameColor,TTFColorPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameHorizontalAlignment,HorizontalAlignmentPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameVerticalAlignment,VerticalAlignmentPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameText,TTFTextPropertyParser::create());
}

void PropertyParserCompiler::compileLabelBMFontParser(ComponentialElementParser* elementParser)
{
    elementParser->registerPropertyParser(kPropertyNameAutomaticWidth,AutomaticWidthPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameAlignment,BMFontAlignmentPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameColor,BMFontColorPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameFntFile,FntFilePropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameText,BMFontTextPropertyParser::create());
}

void PropertyParserCompiler::compileLabelAtlasParser(ComponentialElementParser* elementParser)
{
    elementParser->registerPropertyParser(kPropertyNameColor,LabelAtlasColorPropertyParser::create());
}

void PropertyParserCompiler::compileComponentParser(ComponentialElementParser* elementParser)
{
    elementParser->registerPropertyParser(kPropertyNameName,ComponentNamePropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameEnable,ComponentEnablePropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameBounds,ComponentInteractiveBoundsPropertyParser::create());
}

void PropertyParserCompiler::compileNormalButtonParser(ComponentialElementParser* elementParser)
{
    elementParser->registerPropertyParser(kPropertyNameLabel,NormalButtonLabelPropertyParser::create());
    elementParser->registerPropertyParser(kPropertyNameStates,NormalButtonStatesPropertyParser::create());
}

ElementParser* PropertyParserCompiler::getNodeParser()
{
    ComponentialElementParser* elementParser=ComponentialElementParser::create();
    
    compileNodeParser(elementParser);
    
    return elementParser;
}

ElementParser* PropertyParserCompiler::getSpriteParser()
{
    ComponentialElementParser* elementParser=ComponentialElementParser::create();
    
    compileNodeParser(elementParser);
    compileSpriteParser(elementParser);
    
    return elementParser;
}

ElementParser* PropertyParserCompiler::getComponentParser()
{
    ComponentialElementParser* elementParser=ComponentialElementParser::create();
    
    compileNodeParser(elementParser);
    compileComponentParser(elementParser);
    
    return elementParser;
}

NS_CC_YHGUI_END