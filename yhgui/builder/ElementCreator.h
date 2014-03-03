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
#include <yhge/CocosExt/CCDefaultTexture.h>
#include <yhge/CocosExt/CCAdaptSprite.h>
#include <yhgui/Component.h>
#include <yhgui/control/NormalButton.h>
#include "../YHGUIMacros.h"
#include "UIBuilderMacros.h"

NS_CC_YHGUI_BEGIN

class ElementCreator:public CCObject
{
public:
    
    YHGUI_PURE_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(CCNode);
    
};

/**
 * @brief node 结点创建
 */
class NodeCreator:public ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(CCNode);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(NodeCreator,creator);
};

/**
 * @brief sprite 结点创建
 */
class SpriteCreator:public ElementCreator
{
public:
    
//    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(CCSprite);
    virtual CCSprite * createElement(const yhge::Json::Value& defineData) {
        return yhge::CCAdaptSprite::createWithTexture(yhge::CCDefaultTexture::getInstance()->getTexture());
    }
    
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(SpriteCreator,creator);
};

/**
 * @brief labelTTF 结点创建
 */
class LabelTTFCreator:public ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(CCLabelTTF);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LabelTTFCreator,creator);
};

/**
 * @brief labelBMFont 结点创建
 */
class LabelBMFontCreator:public ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(CCLabelBMFont);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LabelBMFontCreator,creator);
};

/**
 * @brief labelAtlas 结点创建
 */
class LabelAtlasCreator:public ElementCreator
{
public:
    
    virtual CCLabelAtlas * createElement(const yhge::Json::Value& defineData);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(LabelAtlasCreator,creator);
};

class ComponentCreator:public ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(yhgui::Component);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(ComponentCreator,creator);
};

class NormalButtonCreator:public ElementCreator
{
public:
    
    YHGUI_VIRTUAL_NEW_AUTORELEASE_CREATE_ELEMENT_METHOD(yhgui::NormalButton);
    YHGUI_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(NormalButtonCreator,creator);
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_ELEMENTCREATOR_H_
