//
//  PropertyParser.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_PARSERS_NODEPROPERTYPARSER_H_
#define COCOS_YHGUI_BUILDER_PARSERS_NODEPROPERTYPARSER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/Component.h>
#include "ComponentialElementParser.h"

NS_CC_YHGUI_BEGIN


class NodeParser:public ComponentialElementParser
{
public:
    
    virtual bool init();
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(NodeParser,create);
    
};

class SpriteParser:public NodeParser
{
public:
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(SpriteParser,create);
};

class LabelTTFParser:public NodeParser
{
public:
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LabelTTFParser,create);
};

class LabelBMFontParser:public NodeParser
{
public:
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LabelBMFontParser,create);
};

class LabelAtlasParser:public NodeParser
{
public:
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(LabelAtlasParser,create);
};

class ComponentParser:public NodeParser
{
public:
        
    virtual void setupPropertyParser();
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(ComponentParser,create);
};

class NormalButtonParser:public ComponentParser
{
public:
    
    virtual void setupPropertyParser();
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_WITH_INIT_METHOD(NormalButtonParser,create);
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PARSERS_NODEPROPERTYPARSER_H_
