#include "ElementCreator.h"
#include <yhge/yhge.h>
#include "UIBuilderConsts.h"


USING_NS_CC_YHGE;
NS_CC_YHGUI_BEGIN


CCLabelAtlas * LabelAtlasCreator::createElement(const yhge::Json::Value& defineData){
    yhge::Json::Value properties=defineData[kPropertyNameProperties];
    yhge::Json::Value textValue=properties[kPropertyNameText];
    yhge::Json::Value fonFileValue=properties[kPropertyNameFntFile];
    return CCLabelAtlas::create(textValue.asCString(), fonFileValue.asCString());
}

NS_CC_YHGUI_END