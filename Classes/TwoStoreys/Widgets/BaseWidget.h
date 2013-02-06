#ifndef WIDGETS_BASEWIDGET_H_
#define WIDGETS_BASEWIDGET_H_

#include "cocos2d.h"
#include "GameMacros.h"

USING_NS_CC;

NS_YH_BEGIN

class BaseWidget : public CCNode
{
public:
    virtual bool init();  

};

NS_YH_END

#endif // WIDGETS_BASEWIDGET_H_
