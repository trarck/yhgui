#ifndef COCOS_YHGUI_MVC_YHLAYER_H_
#define COCOS_YHGUI_MVC_YHLAYER_H_

#include "cocos2d.h"
#include "../YHGUIMacros.h"

NS_CC_YHGUI_BEGIN

class YHLayer : public CCLayer
{
public:
    virtual bool init();  

    CREATE_FUNC(YHLayer);
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_MVC_YHLAYER_H_
