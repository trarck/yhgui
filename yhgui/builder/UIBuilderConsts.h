#ifndef COCOS_YHGUI_BUILDER_UIBUILDERCONSTS_H_
#define COCOS_YHGUI_BUILDER_UIBUILDERCONSTS_H_

#include "../YHGUIMacros.h"

NS_CC_YHGUI_BEGIN
//==================element type==================//
extern const char* kElementTypeNode;
extern const char* kElementTypeSprite;
extern const char* kElementTypeCCLabelTTF;
extern const char* kElementTypeCCLabelBMFont;
extern const char* kElementTypeCCLableAtlas;
extern const char* kElementTypeComponent;
extern const char* kElementTypeContainer;
extern const char* kElementTypeButton;
extern const char* kElementTypeNormalButton;
extern const char* kElementTypeScaleButton;
extern const char* kElementTypeComplexButton;
extern const char* kElementTypeLabelAtlas;
extern const char* kElementTypeLabelBMFont;
extern const char* kElementTypeLabelTTF;
extern const char* kElementTypePanel;
extern const char* kElementTypeList;
extern const char* kElementTypeScrollPanel;



//==================element property==================//

//common
extern const char* kPropertyNameType;
extern const char* kPropertyNameProperties;
extern const char* kPropertyNameChildren;
extern const char* kPropertyNameVersion;
extern const char* kPropertyNameGraphData;

//struct point
extern const char* kPropertyNameX; //also for Point
extern const char* kPropertyNameY; //also for Point

//struct size
extern const char* kPropertyNameWidth; //also for Size
extern const char* kPropertyNameHeight; //also for Size

//struct color
extern const char* kPropertyNameR;
extern const char* kPropertyNameG;
extern const char* kPropertyNameB;

//unknow
extern const char* kPropertyNamePosition;
extern const char* kPropertyNameSize;
extern const char* kPropertyNameAnchor;
extern const char* kPropertyNameScale;
extern const char* kPropertyNameFlip;

extern const char* kPropertyNameBackground;

//color
extern const char* kPropertyNameColor;

//node
extern const char* kPropertyNameAnchorX;
extern const char* kPropertyNameAnchorY;
extern const char* kPropertyNameScaleX;
extern const char* kPropertyNameScaleY;
extern const char* kPropertyNameRotation;
extern const char* kPropertyNameVisible;
extern const char* kPropertyNameZOrder;
extern const char* kPropertyNameTag;

//sprite
extern const char* kPropertyNameFlipX;
extern const char* kPropertyNameFlipY;
extern const char* kPropertyNameAsset;

//label
extern const char* kPropertyNameText;
extern const char* kPropertyNameFontFamily;
extern const char* kPropertyNameFontSize;
extern const char* kPropertyNameHorizontalAlignment;
extern const char* kPropertyNameVerticalAlignment;
extern const char* kPropertyNameFntFile;
extern const char* kPropertyNameAutomaticWidth;
extern const char* kPropertyNameAlignment;

//component
extern const char* kPropertyNameName;
extern const char* kPropertyNameEnable;
extern const char* kPropertyNameBounds;

//button
extern const char* kPropertyNamePreferredSize;
extern const char* kPropertyNamePreferredWidth;
extern const char* kPropertyNamePreferredHeight;

extern const char* kPropertyNameStates;
extern const char* kPropertyNameNormal;
extern const char* kPropertyNamePressed;
extern const char* kPropertyNameSelected;
extern const char* kPropertyNameDisabled;

//normal button
extern const char* kPropertyNameLabelOffset;
extern const char* kPropertyNameLabel;

//==================element events==================//
extern const char* kPropertyNameEvents;
extern const char* kPropertyNameSegment;
extern const char* kPropertyNameHandle;
extern const char* kPropertyNameEventName;

//==================others==================//
extern const char* kDefaultSegmentName;

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_UIBUILDERCONSTS_H_
