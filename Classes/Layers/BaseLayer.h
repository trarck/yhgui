#ifndef LAYERS_BASELAYER_H_
#define LAYERS_BASELAYER_H_

#include "cocos2d.h"

USING_NS_CC;

namespace yhge {

class BaseLayer : public CCLayer
{
public:
    virtual bool init();  

    CREATE_FUNC(BaseLayer);
};

}

#endif // LAYERS_BASELAYER_H_
