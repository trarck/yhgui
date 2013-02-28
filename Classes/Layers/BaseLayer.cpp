#include "BaseLayer.h"

USING_NS_CC;

namespace yhge {

bool BaseLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

        
    return true;
}

}