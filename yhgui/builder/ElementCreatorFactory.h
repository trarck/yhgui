#ifndef COCOS_YHGUI_ELEMENTCREATORFACTORY_H_
#define COCOS_YHGUI_ELEMENTCREATORFACTORY_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include "../YHGUIMacros.h"
#include "ElementCreator.h"

NS_CC_YHGUI_BEGIN

class ElementCreatorFactory:public CCObject
{
public:
    
    ElementCreatorFactory();
    
    ~ElementCreatorFactory();
    
    /**
     * @brief 初始化
     */
    bool init();
    
    /**
     * @brief 初始化
     */
    bool init(int keyType);
    
    /**
     * @brief 设置默认创建器
     */
    void setupDefaultCreator();
    
    /**
     * @brief 设置默认创建器,使用字符串key
     */
    void setupStringKeyDefaultCreator();
    
    /**
     * @brief 设置默认创建器,使用数字key
     */
    void setupIntKeyDefaultCreator();

    /**
     * @brief 注册一个元素的创建器
     *
     * @param elementType 元素类型
     * @return 元素创建器
     */
    void registerElementCreator(const std::string& elementType,ElementCreator* elementCreator);
    
    /**
     * @brief 注册一个元素的创建器
     *
     * @param elementType 元素类型
     * @return 元素创建器
     */
    void registerElementCreator(int elementType,ElementCreator* elementCreator);
    
    /**
     * @brief 移除一个元素的创建器
     *
     * @param elementType 元素类型
     */
    void removeElementCreator(const std::string& elementType);
    
    /**
     * @brief 移除一个元素的创建器
     *
     * @param elementType 元素类型
     */
    void removeElementCreator(int elementType);
    
    /**
     * @brief 获取一个元素的创建器
     *
     * @param elementType 一个json值，表示元素类型
     * @return 元素创建器
     */
    ElementCreator* getElementCreator(const yhge::Json::Value& elementType);
    
    /**
     * @brief 获取一个元素的创建器
     *
     * @param elementType 一个int值，表示元素类型
     * @return 元素创建器
     */
    ElementCreator* getElementCreator(int elementType);
    
    /**
     * @brief 获取一个元素的创建器
     *
     * @param elementType 一个string值，表示元素类型
     * @return 元素创建器
     */
    ElementCreator* getElementCreator(const std::string& elementType);

public:
    
    enum{
        kStringKey=1,
        kIntKey=2,
    };
    
    inline void setElementCreaters(CCDictionary* elementCreaters)
    {
        CC_SAFE_RETAIN(elementCreaters);
        CC_SAFE_RELEASE(m_elementCreaters);
        m_elementCreaters = elementCreaters;
    }
    
    inline CCDictionary* getElementCreaters()
    {
        return m_elementCreaters;
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
    
    //元素创建器
    CCDictionary* m_elementCreaters;

    //键的类型
    int m_keyType;
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_ELEMENTCREATORFACTORY_H_
