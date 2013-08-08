#include "YHLayer.h"
#include "YHLayerController.h"

NS_CC_YHMVC_BEGIN

YHLayer::YHLayer()
:m_layerController(NULL)
{

}

YHLayer::~YHLayer()
{
	
}

bool YHLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

    return true;
}

void YHLayer::onEnter()
{
	CCLayer::onEnter();
	if(m_layerController){
		m_layerController->onLayerEnter();
	}
}

void YHLayer::onExit()
{
	CCLayer::onExit();
	if(m_layerController){
		m_layerController->onLayerExit();
	}
}

NS_CC_YHMVC_END