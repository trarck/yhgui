#include "YHScene.h"
#include "YHLayerController.h"

NS_CC_YHMVC_BEGIN

YHScene::YHScene()
:m_layerControllers(NULL)
{
    
}

YHScene::~YHScene()
{
    CC_SAFE_RELEASE_NULL(m_layerControllers);
}

bool YHScene::init()
{
    if (!CCLayer::init()){
        return false;
    }
    m_layerControllers=new CCArray();
    m_layerControllers->init();
    return true;
}

void YHScene::onEnter()
{
	CCLayer::onEnter();
    loadContents();
}

void YHScene::onExit()
{
	CCLayer::onExit();
}

void YHScene::loadContents()
{

}

void YHScene::addLayerController(YHLayerController* layerController)
{
    layerController->layerWillAppear();
    addChild(layerController->getLayer());
    m_layerControllers->addObject(layerController);
    layerController->layerDidAppear();
}

void YHScene::removeLayerController(YHLayerController* layerController)
{
    layerController->layerWillDisappear();
    removeChild(layerController->getLayer());
    m_layerControllers->removeObject(layerController);
    layerController->layerDidDisappear();
}

NS_CC_YHMVC_END