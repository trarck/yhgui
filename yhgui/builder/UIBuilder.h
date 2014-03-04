//
//  UIBuilder.h
//  
//
//  Created by duanhouhai on 13-2-1.
//
//

#ifndef COCOS_YHGUI_BUILDER_UIBUILDER_H_
#define COCOS_YHGUI_BUILDER_UIBUILDER_H_

#include "cocos2d.h"
#include <yhge/Jsoncpp/json.h>
#include "../YHGUIMacros.h"
#include "ElementCreatorFactory.h"
#include "ElementParserFactory.h"
#include "ElementEventParser.h"

NS_CC_YHGUI_BEGIN

class UIBuilder:public CCObject
{
public:
    
    UIBuilder();
    
    ~UIBuilder();
    
    bool init();
    
    CCNode* buildWithJSONFile(const char* jsonFile);
    
    CCNode* buildWithJSONData(const char* jsonString);
    
    CCNode* buildUI(const yhge::Json::Value& json);
    
    CCNode* buildUI(const yhge::Json::Value& json,CCNode* parent);
    
    CCNode* buildElement(const yhge::Json::Value& defineData);
    
    CCNode* buildElement(const yhge::Json::Value& defineData,CCNode* parent);
    
    void buildChildren(const yhge::Json::Value& children,CCNode* parent);
    
    unsigned int getDataFormat(yhge::Json::Value root);
    
    unsigned int getDataVersion(yhge::Json::Value root);

protected:
    
    /**
     * @brief 创建一个元素
     *
     * @param defineData 元素的定义数据
     */
    virtual CCNode* createElement(const yhge::Json::Value& defineData);
    
    /**
     * @brief 处理元素
     * 包括处理元素的属性，事件，还有其它属性
     * @param node 需要设置属性的元素
     * @param defineData 元素的属性集。一个json对象
     * @param parent 父结点
     */
    virtual void parseElement(CCNode* node,const yhge::Json::Value& defineData,CCNode* parent);
    
    /**
     * @brief 设置元素的属性
     *
     * @param node 需要设置属性的元素
     * @param type 元素类型
     * @param properties 元素的属性集。一个json对象
     */
    void setElementProperties(CCNode* node,const yhge::Json::Value& type,const yhge::Json::Value& properties);
    
    /**
     * @brief 设置元素的属性
     *
     * @param node 需要设置属性的元素
     * @param properties 元素的属性集。一个json对象
     * @param parent 父结点
     */
    void setElementProperties(CCNode* node,const yhge::Json::Value& type,const yhge::Json::Value& properties,CCNode* parent);
    
    /**
     * @brief set元素的事件
     * 只有可触发事件的元素，才有事件触发。
     *
     * @param node 需要设置属性的元素
     * @param type 元素类型
     * @param events 要处理的的事件。一个json对象
     */
    void registerElementEvents(CCNode* node,const yhge::Json::Value& type,const yhge::Json::Value& events);
    
    /**
     * @brief set元素的事件
     * 只有可触发事件的元素，才可以进行事件触发。
     *
     * @param node 需要设置属性的元素
     * @param type 元素类型
     * @param events 要处理的的事件。一个json对象
     * @param parent 父结点
     */
    void registerElementEvents(CCNode* node,const yhge::Json::Value& type,const yhge::Json::Value& events,CCNode* parent);
    
    unsigned int tanslateElementTypeFromStringToInteger(const std::string& typeString);

public:
    
    enum DataFormate{
        kUIDataFormatSimple=1,
        kUIDataFormatHaveScene
    };
    
    inline void setElementCreatorFactory(ElementCreatorFactory* elementCreatorFactory)
    {
        CC_SAFE_RETAIN(elementCreatorFactory);
        CC_SAFE_RELEASE(m_elementCreatorFactory);
        m_elementCreatorFactory = elementCreatorFactory;
    }
    
    inline ElementCreatorFactory* getElementCreatorFactory()
    {
        return m_elementCreatorFactory;
    }
    
    inline void setElementParserFactory(ElementParserFactory* elementParserFactory)
    {
        CC_SAFE_RETAIN(elementParserFactory);
        CC_SAFE_RELEASE(m_elementParserFactory);
        m_elementParserFactory = elementParserFactory;
    }
    
    inline ElementParserFactory* getElementParserFactory()
    {
        return m_elementParserFactory;
    }
    
    void setElementEventParser(ElementEventParser* elementEventParser)
    {
        CC_SAFE_RETAIN(elementEventParser);
        CC_SAFE_RELEASE(m_elementEventParser);
        m_elementEventParser = elementEventParser;
    }

    ElementEventParser* getElementEventParser()
    {
        return m_elementEventParser;
    }

protected:
    
    //元素创建器
    ElementCreatorFactory* m_elementCreatorFactory;
    
    //元素属性处理器
    ElementParserFactory* m_elementParserFactory;
    
    //事件处理
    ElementEventParser* m_elementEventParser;
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_UIBUILDER_H_
