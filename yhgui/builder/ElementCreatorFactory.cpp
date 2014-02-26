#include "ElementCreatorFactory.h"

NS_CC_YHGUI_BEGIN

ElementCreatorFactory::ElementCreatorFactory()
:m_elementCreaters(NULL)
,m_keyType(kStringKey)
{
    
}

ElementCreatorFactory::~ElementCreatorFactory()
{
    CC_SAFE_RELEASE_NULL(m_elementCreaters);
}

bool ElementCreatorFactory::init()
{
    m_elementCreaters=new CCDictionary();
    setupDefaultCreator();
    return true;
}

/**
 * @brief 初始化
 */
bool ElementCreatorFactory::init(int keyType)
{
    m_elementCreaters=new CCDictionary();
    m_keyType=keyType;
    setupDefaultCreator();
    return true;
}

/**
 * @brief 设置默认创建器
 */
void ElementCreatorFactory::setupDefaultCreator()
{
    switch (m_keyType) {
        case kIntKey:
            setupIntKeyDefaultCreator();
            break;
        case kStringKey:
            setupStringKeyDefaultCreator();
            break;
        default:
            break;
    }
}

/**
 * @brief 设置默认创建器,使用字符串key
 */
void ElementCreatorFactory::setupStringKeyDefaultCreator()
{
    registerElementCreator("Node", NodeCreator::creator());
    registerElementCreator("Sprite", SpriteCreator::creator());
    registerElementCreator("Component", ComponentCreator::creator());
}

/**
 * @brief 设置默认创建器,使用数字key
 */
void ElementCreatorFactory::setupIntKeyDefaultCreator()
{
    
}

//注册一个元素的创建器
void ElementCreatorFactory::registerElementCreator(const std::string& elementType,ElementCreator* elementCreator)
{
    m_elementCreaters->setObject(elementCreator, elementType);
}

//注册一个元素的创建器
void ElementCreatorFactory::registerElementCreator(int elementType,ElementCreator* elementCreator)
{
    m_elementCreaters->setObject(elementCreator, elementType);
}

//移除一个元素的创建器
void ElementCreatorFactory::removeElementCreator(const std::string& elementType)
{
    m_elementCreaters->removeObjectForKey(elementType);
}

//移除一个元素的创建器
void ElementCreatorFactory::removeElementCreator(int elementType)
{
    m_elementCreaters->removeObjectForKey(elementType);
}

ElementCreator* ElementCreatorFactory::getElementCreator(const yhge::Json::Value& elementType)
{
    if (elementType.isIntegral()) {
        return static_cast<ElementCreator*>(m_elementCreaters->objectForKey(elementType.asInt()));
    }else if(elementType.isString()){
        return static_cast<ElementCreator*>(m_elementCreaters->objectForKey(elementType.asString()));
    }else{
        CCAssert(false, "ElementCreatorFactory::getElementCreator unkonw elementType");
    }
}

ElementCreator* ElementCreatorFactory::getElementCreator(int elementType)
{
    return static_cast<ElementCreator*>(m_elementCreaters->objectForKey(elementType));
}

ElementCreator* ElementCreatorFactory::getElementCreator(const std::string& elementType)
{
    return static_cast<ElementCreator*>(m_elementCreaters->objectForKey(elementType));
}
NS_CC_YHGUI_END