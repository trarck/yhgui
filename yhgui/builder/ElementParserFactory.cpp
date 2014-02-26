#include "ElementParserFactory.h"
#include "element_parsers/NodeParser.h"
#include "ElementParser.h"

NS_CC_YHGUI_BEGIN


ElementParserFactory::ElementParserFactory()
:m_elementParserMap(NULL)
,m_keyType(kStringKey)
{
    
}

ElementParserFactory::~ElementParserFactory()
{
    CC_SAFE_RELEASE_NULL(m_elementParserMap);
}

bool ElementParserFactory::init()
{
    m_elementParserMap=new CCDictionary();
    setupDefaultParser();
    return true;
}

bool ElementParserFactory::init(int keyType)
{
    m_elementParserMap=new CCDictionary();
    m_keyType=keyType;
    setupDefaultParser();
    return true;
}

void ElementParserFactory::setupDefaultParser()
{
    switch (m_keyType) {
        case kIntKey:
            setupStringKeyDefaultParser();
            break;
        case kStringKey:
            setupIntKeyDefaultParser();
            break;
        default:
            break;
    }
}

void ElementParserFactory::setupStringKeyDefaultParser()
{
    registerElementParser("Node", NodeParser::create());
    registerElementParser("Sprite", SpriteParser::create());
    registerElementParser("Component", ComponentParser::create());
}

void ElementParserFactory::setupIntKeyDefaultParser()
{
    
}

void ElementParserFactory::registerElementParser(const std::string& elementType,ElementParser* elementParser)
{
    m_elementParserMap->setObject(elementParser,elementType);
}

void ElementParserFactory::registerElementParser(int elementType,ElementParser* elementParser)
{
    m_elementParserMap->setObject(elementParser,elementType);
}

void ElementParserFactory::removeElementParser(const std::string& elementType)
{
    m_elementParserMap->removeObjectForKey(elementType);
}

void ElementParserFactory::removeElementParser(int elementType)
{
    m_elementParserMap->removeObjectForKey(elementType);
}

ElementParser* ElementParserFactory::getElementParser(const std::string& elementType)
{
    return static_cast<ElementParser*>(m_elementParserMap->objectForKey(elementType));
}

ElementParser* ElementParserFactory::getElementParser(int elementType)
{
    return static_cast<ElementParser*>(m_elementParserMap->objectForKey(elementType));
}

ElementParser* ElementParserFactory::getElementParser(const yhge::Json::Value& elementType)
{
    if (elementType.isIntegral()) {
        return static_cast<ElementParser*>(m_elementParserMap->objectForKey(elementType.asInt()));
    }else if (elementType.isString()){
        return static_cast<ElementParser*>(m_elementParserMap->objectForKey(elementType.asString()));
    }
    
    return NULL;
}

NS_CC_YHGUI_END