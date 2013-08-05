#ifndef COCOS_YHMVC_YHLAYER_H_
#define COCOS_YHMVC_YHLAYER_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class YHLayer : public CCLayer
{
public:
    virtual bool init();  

    CREATE_FUNC(YHLayer);
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHLAYER_H_
