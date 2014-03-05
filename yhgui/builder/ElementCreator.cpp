#include "ElementCreator.h"
#include <yhge/yhge.h>
#include "UIBuilderConsts.h"
#include "UIBuilder.h"


USING_NS_CC_YHGE;
NS_CC_YHGUI_BEGIN

CCSprite * SpriteCreator::createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder) {
    return yhge::CCAdaptSprite::createWithTexture(yhge::CCDefaultTexture::getInstance()->getTexture());
}

CCLabelAtlas * LabelAtlasCreator::createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder){
    yhge::Json::Value properties=defineData[kPropertyNameProperties];
    yhge::Json::Value textValue=properties[kPropertyNameText];
    yhge::Json::Value fonFileValue=properties[kPropertyNameFntFile];
    return CCLabelAtlas::create(textValue.asCString(), fonFileValue.asCString());
}

CCNode * IncludeCreator::createElement(const yhge::Json::Value& defineData,yhgui::UIBuilder* builder)
{
    yhge::Json::Value fileValue=defineData[kPropertyNameFile];
    if (!fileValue.isNull()) {
        return builder->buildWithJSONFile(fileValue.asCString());
    }
    
    return NULL;
}

NS_CC_YHGUI_END