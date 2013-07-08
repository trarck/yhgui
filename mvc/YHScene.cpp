#include "YHScene.h"

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
    if (!CCScene::init()){
        return false;
    }
    m_layerControllers=new CCArray();
    m_layerControllers->init();
    return true;
}

void YHScene::onEnter()
{
    loadContents();
}

void YHScene::onExit()
{

}

 void YHScene::loadContents()
 {

 }

void YHScene::addLayerController(YHLayerController* layerController)
{
    layerController->layerWillAppear();
    addChild(layerWillAppear->getLayer());
    layerWillAppear->layerDidAppear();
    m_layerControllers->addObject(layerController);
}

void YHScene::removeLayerController(YHLayerController* layerController)
{
    layerController->layerWillDisappear();
    removeChild(layerWillAppear->getLayer());
    layerWillAppear->layerDidDisappear();
    m_layerControllers->removeObject(layerController);
}

NS_CC_YHMVC_END