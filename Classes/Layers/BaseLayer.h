#ifndef LAYERS_BASELAYER_H_
#define LAYERS_BASELAYER_H_

#include "cocos2d.h"
#include "CCUIMacros.h"

USING_NS_CC;

NS_YH_BEGIN

class BaseLayer : public CCLayer
{
public:
    virtual bool init();  

    CREATE_FUNC(BaseLayer);
};

NS_YH_END

#endif // LAYERS_BASELAYER_H_
