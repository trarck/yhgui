//
//  Handle.h
//  CCUI
//
//  Created by duanhouhai on 13-11-5.
//
//

#ifndef COCOS_YHGUI_BUILDER_BUILDERHANDLE_H_
#define COCOS_YHGUI_BUILDER_BUILDERHANDLE_H_

#include "cocos2d.h"
#include "../YHGUIMacros.h"
#include <yhge/Jsoncpp/json.h>

NS_CC_YHGUI_BEGIN

typedef CCNode* (*SEL_ElementCreateHandle)();
typedef void (*SEL_PropertySetHandle)(CCNode* element,yhge::Json::Value& value);

#define BUILDER_ELEMENT_CREATE_SELECTOR(_SELECTOR) (SEL_ElementCreateHandle)(&_SELECTOR)
#define BUILDER_PROPERTY_SET_SELECTOR(_SELECTOR) (SEL_PropertySetHandle)(&_SELECTOR)

class ElementCreate:public CCObject
{
public:
    
    static CCNode* createNode();
    static CCSprite* createSprite();
    static CCLabelTTF* createLabel();
    static CCLabelBMFont* createLabelBMFont();
    static CCLabelAtlas* createLabelAtlas();
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_BUILDERHANDLE_H_
