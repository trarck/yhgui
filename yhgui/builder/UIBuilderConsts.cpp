#include "UIBuilderConsts.h"

NS_CC_YHGUI_BEGIN

//==================element type==================//
const char* kElementTypeNode ="Node";
const char* kElementTypeSprite ="Sprite";
const char* kElementTypeCCLabelTTF ="CCLabelTTF";
const char* kElementTypeCCLabelBMFont ="CCLabelBMFont";
const char* kElementTypeCCLableAtlas ="CCLableAtlas";
const char* kElementTypeComponent ="Component";
const char* kElementTypeContainer ="Container";
const char* kElementTypeButton ="Button";
const char* kElementTypeNormalButton ="NormalButton";
const char* kElementTypeScaleButton ="ScaleButton";
const char* kElementTypeComplexButton ="ComplexButton";
const char* kElementTypeLabelAtlas ="LabelAtlas";
const char* kElementTypeLabelBMFont ="LabelBMFont";
const char* kElementTypeLabelTTF ="LabelTTF";
const char* kElementTypePanel ="Panel";
const char* kElementTypeList ="List";
const char* kElementTypeScrollPanel ="ScrollPanel";


//==================element property==================//
//common
const char* kPropertyNameType="type";
const char* kPropertyNameProperties="properties";
const char* kPropertyNameChildren="children";
const char* kPropertyNameVersion="version";
const char* kPropertyNameGraphData ="graphData";

const char* kPropertyNamePosition ="position";
const char* kPropertyNameSize ="size";
const char* kPropertyNameAnchor ="anchor";
const char* kPropertyNameScale ="scale";
const char* kPropertyNameFlip ="flip";

//node
const char* kPropertyNameX ="x";
const char* kPropertyNameY ="y";
const char* kPropertyNameWidth ="width";
const char* kPropertyNameHeight ="height";
const char* kPropertyNameAnchorX ="anchorX";
const char* kPropertyNameAnchorY ="anchorY";
const char* kPropertyNameScaleX ="scaleX";
const char* kPropertyNameScaleY ="scaleY";
const char* kPropertyNameRotation ="rotation";
const char* kPropertyNameVisible ="visible";
const char* kPropertyNameZOrder ="zOrder";
const char* kPropertyNameTag ="tag";

//color
const char* kPropertyNameColor ="color";

//sprite
const char* kPropertyNameFlipX ="flipX";
const char* kPropertyNameFlipY ="flipY";
const char* kPropertyNameAsset ="asset";

//label
const char* kPropertyNameText ="text";
const char* kPropertyNameFontFamily ="fontFamily";
const char* kPropertyNameFontSize ="fontSize";
const char* kPropertyNameHorizontalAlignment ="horizontalAlignment";
const char* kPropertyNameVerticalAlignment ="verticalAlignment";
const char* kPropertyNameFntFile ="fntFile";
const char* kPropertyNameAutomaticWidth ="automaticWidth";
const char* kPropertyNameAlignment ="alignment";

//==================element events==================//
const char* kPropertyNameEvents="events";
const char* kPropertyNameSegment="segment";
const char* kPropertyNameHandle="handle";
const char* kPropertyNameEventName="eventName";
//==================others==================//
const char* kDefaultSegmentName="default";
NS_CC_YHGUI_END