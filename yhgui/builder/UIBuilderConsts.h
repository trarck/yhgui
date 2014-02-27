#ifndef COCOS_YHGUI_BUILDER_UIBUILDERCONSTS_H_
#define COCOS_YHGUI_BUILDER_UIBUILDERCONSTS_H_

#include "../YHGUIMacros.h"

NS_CC_YHGUI_BEGIN

extern const char* kPropertyNameType;
extern const char* kPropertyNameProperties;
extern const char* kPropertyNameChildren;
extern const char* kPropertyNameVersion;
extern const char* kPropertyNameGraphData;

//unknow
extern const char* kPropertyNamePosition;
extern const char* kPropertyNameSize;
extern const char* kPropertyNameAnchor;
extern const char* kPropertyNameScale;
extern const char* kPropertyNameFlip;

//node
extern const char* kPropertyNameX; //also for Point
extern const char* kPropertyNameY; //also for Point
extern const char* kPropertyNameWidth; //also for Size
extern const char* kPropertyNameHeight; //also for Size
extern const char* kPropertyNameAnchorX;
extern const char* kPropertyNameAnchorY;
extern const char* kPropertyNameScaleX;
extern const char* kPropertyNameScaleY;
extern const char* kPropertyNameRotation;
extern const char* kPropertyNameVisible;
extern const char* kPropertyNameZOrder;
extern const char* kPropertyNameTag;

extern const char* kPropertyNameColor;
extern const char* kPropertyNameFlipX;
extern const char* kPropertyNameFlipY;
extern const char* kPropertyNameAsset;

extern const char* kPropertyNameText;
extern const char* kPropertyNameFontFamily;
extern const char* kPropertyNameFontSize;
extern const char* kPropertyNameHorizontalAlignment;
extern const char* kPropertyNameVerticalAlignment;
extern const char* kPropertyNameFntFile;
extern const char* kPropertyNameAutomaticWidth;
extern const char* kPropertyNameAlignment;

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_BUILDER_UIBUILDERCONSTS_H_
