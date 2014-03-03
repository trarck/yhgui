
#ifndef COCOS_YHGUI_BUILDER_PROPERTYPARSERCOMPILER_H_
#define COCOS_YHGUI_BUILDER_PROPERTYPARSERCOMPILER_H_

#include "cocos2d.h"
#include "element_parsers/ComponentialElementParser.h"

NS_CC_YHGUI_BEGIN

/**
 * @brief 对象属性处理工场
 */
class PropertyParserCompiler:public CCObject
{
public:
    
    static void compileNodeParser(ComponentialElementParser* elementParser);
    
    static void compileSpriteParser(ComponentialElementParser* elementParser);
    
    static void compileLabelTTFParser(ComponentialElementParser* elementParser);
    
    static void compileLabelBMFontParser(ComponentialElementParser* elementParser);
    
    static void compileLabelAtlasParser(ComponentialElementParser* elementParser);
    
    static void compileComponentParser(ComponentialElementParser* elementParser);
    
    static void compileNormalButtonParser(ComponentialElementParser* elementParser);
    
    
    static ElementParser* getNodeParser();
    
    static ElementParser* getSpriteParser();
    
    static ElementParser* getComponentParser();
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_PROPERTYPARSERCOMPILER_H_
