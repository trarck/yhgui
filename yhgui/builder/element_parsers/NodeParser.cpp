#include "NodeParser.h"
#include "../UIBuilderConsts.h"
#include "../property_parsers/NodePropertyParser.h"

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
    registerPropertyParser(kPropertyNamePosition,PositionPropertyParser::create());
    registerPropertyParser(kPropertyNameSize,SizePropertyParser::create());
    registerPropertyParser(kPropertyNameAnchor,AnchorPropertyParser::create());
    registerPropertyParser(kPropertyNameScale,ScalePropertyParser::create());
    registerPropertyParser(kPropertyNameRotation,RotationPropertyParser::create());
    registerPropertyParser(kPropertyNameVisible,VisiblePropertyParser::create());
    registerPropertyParser(kPropertyNameZOrder,ZOrderPropertyParser::create());
    registerPropertyParser(kPropertyNameTag,TagPropertyParser::create());
}

void SpriteParser::setupPropertyParser()
{
    NodeParser::setupPropertyParser();
    
    registerPropertyParser(kPropertyNameColor,ColorPropertyParser::create());
    registerPropertyParser(kPropertyNameFlip,SpriteColorPropertyParser::create());
    registerPropertyParser(kPropertyNameAsset,TexutrePropertyParser::create());
    
//    CCArray* keys=m_propertyParserMap->allKeys();
//    CCObject* pObj=NULL;
//    CCLOG("----------key{----------");
//    CCARRAY_FOREACH(keys, pObj){
//        CCLOG("%s",static_cast<CCString*>(pObj)->getCString());
//    }
//    CCLOG("----------}----------");
}

void ComponentParser::setupPropertyParser()
{
    NodeParser::setupPropertyParser();
}

NS_CC_YHGUI_END