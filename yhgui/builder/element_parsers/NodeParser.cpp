#include "NodeParser.h"
#include "../UIBuilderConsts.h"
#include "../PropertyParserCompiler.h"

NS_CC_YHGUI_BEGIN

bool NodeParser::init()
{
    if (!ComponentialElementParser::init()) {
        return false;
    }
    setupPropertyParser();
    return true;
}

void NodeParser::setupPropertyParser()
{
    PropertyParserCompiler::compileNodeParser(this);
}

void SpriteParser::setupPropertyParser()
{
    NodeParser::setupPropertyParser();
    
    PropertyParserCompiler::compileSpriteParser(this);
    
//    CCArray* keys=m_propertyParserMap->allKeys();
//    CCObject* pObj=NULL;
//    CCLOG("----------key{----------");
//    CCARRAY_FOREACH(keys, pObj){
//        CCLOG("%s",static_cast<CCString*>(pObj)->getCString());
//    }
//    CCLOG("----------}----------");
}

void LabelTTFParser::setupPropertyParser()
{
    NodeParser::setupPropertyParser();

    PropertyParserCompiler::compileLabelTTFParser(this);
}

void LabelBMFontParser::setupPropertyParser()
{
    NodeParser::setupPropertyParser();
    PropertyParserCompiler::compileLabelBMFontParser(this);
}

void LabelAtlasParser::setupPropertyParser()
{
    NodeParser::setupPropertyParser();
    PropertyParserCompiler::compileLabelAtlasParser(this);
}

void ComponentParser::setupPropertyParser()
{
    NodeParser::setupPropertyParser();
    PropertyParserCompiler::compileComponentParser(this);
}

NS_CC_YHGUI_END