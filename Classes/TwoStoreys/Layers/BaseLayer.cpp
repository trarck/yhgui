#include "BaseLayer.h"

USING_NS_CC;

NS_YH_BEGIN

bool BaseLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

        
    return true;
}

NS_YH_END