#include "PropertyParserCompiler.h"
#include "ElementParser.h"
#include "UIBuilderConsts.h"
#include "property_parsers/NodePropertyParser.h"

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

void PropertyParserCompiler::compileComponentParser(ComponentialElementParser* elementParser)
{
    
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