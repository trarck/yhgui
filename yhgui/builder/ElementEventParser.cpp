#include "ElementEventParser.h"
#include "element_parsers/NodeParser.h"
#include "UIBuilderConsts.h"

NS_CC_YHGUI_BEGIN


ElementEventParser::ElementEventParser()
:m_elementParserMap(NULL)
,m_keyType(kStringKey)
{
    
}

ElementEventParser::~ElementEventParser()
{
    CC_SAFE_RELEASE_NULL(m_elementParserMap);
}

bool ElementEventParser::init()
{
    m_elementParserMap=new CCDictionary();
    setupDefaultParser();
    return true;
}

bool ElementEventParser::init(int keyType)
{
    m_elementParserMap=new CCDictionary();
    m_keyType=keyType;
    setupDefaultParser();
    return true;
}

void ElementEventParser::setupDefaultParser()
{
    switch (m_keyType) {
        case kIntKey:
            setupIntKeyDefaultParser();
            break;
        case kStringKey:
            setupStringKeyDefaultParser();
            break;
        default:
            break;
    }
}

void ElementEventParser::setupStringKeyDefaultParser()
{
    registerElementParser(kElementTypeNode, NodeParser::create());
    registerElementParser(kElementTypeSprite, SpriteParser::create());
    registerElementParser(kElementTypeCCLabelTTF, LabelTTFParser::create());
    registerElementParser(kElementTypeCCLabelBMFont, LabelBMFontParser::create());
    registerElementParser(kElementTypeCCLableAtlas, LabelAtlasParser::create());
    registerElementParser(kElementTypeComponent, ComponentParser::create());
}

void ElementEventParser::setupIntKeyDefaultParser()
{
    
}

void ElementEventParser::registerElementParser(const std::string& elementType,ElementParser* elementParser)
{
    m_elementParserMap->setObject(elementParser,elementType);
}

void ElementEventParser::registerElementParser(int elementType,ElementParser* elementParser)
{
    m_elementParserMap->setObject(elementParser,elementType);
}

void ElementEventParser::removeElementParser(const std::string& elementType)
{
    m_elementParserMap->removeObjectForKey(elementType);
}

void ElementEventParser::removeElementParser(int elementType)
{
    m_elementParserMap->removeObjectForKey(elementType);
}

ElementParser* ElementEventParser::getElementParser(const std::string& elementType)
{
    return static_cast<ElementParser*>(m_elementParserMap->objectForKey(elementType));
}

ElementParser* ElementEventParser::getElementParser(int elementType)
{
    return static_cast<ElementParser*>(m_elementParserMap->objectForKey(elementType));
}

ElementParser* ElementEventParser::getElementParser(const yhge::Json::Value& elementType)
{
    if (elementType.isIntegral()) {
        return static_cast<ElementParser*>(m_elementParserMap->objectForKey(elementType.asInt()));
    }else if (elementType.isString()){
        return static_cast<ElementParser*>(m_elementParserMap->objectForKey(elementType.asString()));
    }
    
    return NULL;
}

NS_CC_YHGUI_END