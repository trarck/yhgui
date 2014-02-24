//
//  ElementCreator.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_ELEMENTCREATOR_H_
#define COCOS_YHGUI_BUILDER_ELEMENTCREATOR_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include <yhgui/Component.h>
#include "../YHGUIMacros.h"
#include "UIBuilderMacros.h"

NS_CC_YHGUI_BEGIN

class ElementCreator:public CCObject
{
public:
    
    YHGUI_PURE_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(CCNode);
    
};

/**
 * Node 结点创建
 */
class NodeCreator:public ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(CCNode);
    
};

class SpriteCreator:public ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(CCSprite);
    
};

class ComponentCreator:public ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(yhgui::Component);
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_ELEMENTCREATOR_H_
