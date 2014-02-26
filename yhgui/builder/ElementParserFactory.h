
#ifndef COCOS_YHGUI_BUILDER_ELEMENTPARSERFACTORY_H_
#define COCOS_YHGUI_BUILDER_ELEMENTPARSERFACTORY_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include "ElementParser.h"

NS_CC_YHGUI_BEGIN

/**
 * @brief 对象属性处理工场
 */
class ElementParserFactory:public CCObject
{
public:
    
    ElementParserFactory();
    
    ~ElementParserFactory();
    
    /**
     * @brief 初始化
     */
    virtual bool init();
    
    /**
     * @brief 初始化
     *
     * @param keyType 键的类型
     */
    bool init(int keyType);
    
    /**
     * @brief 设置默认处理器
     */
    void setupDefaultParser();
    
    /**
     * @brief 设置默认处理器,使用字符串key
     */
    void setupStringKeyDefaultParser();
    
    /**
     * @brief 设置默认处理器,使用数字key
     */
    void setupIntKeyDefaultParser();
    
    /**
     * @brief 注册一个属性处理器
     * 
     * @param elementType 元素类型
     * @param elementParser 元素属性处理器
     */
    void registerElementParser(const std::string& elementType,ElementParser* elementParser);
    
    /**
     * @brief 注册一个属性处理器
     *
     * @param elementType 元素类型
     * @param elementParser 元素属性处理器
     */
    void registerElementParser(int elementType,ElementParser* elementParser);
    
    /**
     * @brief 移除一个属性处理器
     *
     * @param elementType 元素类型
     */
    void removeElementParser(const std::string& elementType);
    
    /**
     * @brief 移除一个属性处理器
     *
     * @param elementType 元素类型
     */
    void removeElementParser(int elementType);
    
    /**
     * @brief 取得属性处理器
     *
     * @param elementType 元素类型
     */
    ElementParser* getElementParser(const std::string& elementType);
    
    /**
     * @brief 取得属性处理器
     *
     * @param elementType 元素类型
     */
    ElementParser* getElementParser(int elementType);
    
    /**
     * @brief 取得属性处理器
     *
     * @param elementType 元素类型
     */
    ElementParser* getElementParser(const yhge::Json::Value& elementType);
    
public:
    
    enum{
        kStringKey=1,
        kIntKey=2,
    };
    
    inline void setElementParserMap(CCDictionary* elementParserMap)
    {
        CC_SAFE_RETAIN(elementParserMap);
        CC_SAFE_RELEASE(m_elementParserMap);
        m_elementParserMap = elementParserMap;
    }
    
    inline CCDictionary* getElementParserMap()
    {
        return m_elementParserMap;
    }
    
    inline void setKeyType(int keyType)
    {
        m_keyType = keyType;
    }
    
    inline int getKeyType()
    {
        return m_keyType;
    }
protected:
    
    CCDictionary* m_elementParserMap;
    
    //键的类型
    int m_keyType;
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_ELEMENTPARSERFACTORY_H_
