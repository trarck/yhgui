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
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(NodeParser,create);
    
};

class SpriteParser:public NodeParser
{
public:
    
    virtual void setupPropertyParser();
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SpriteParser,create);
};

class ComponentParser:public NodeParser
{
public:
        
    virtual void setupPropertyParser();
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ComponentParser,create);
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PARSERS_NODEPROPERTYPARSER_H_
