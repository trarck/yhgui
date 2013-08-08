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
    if (!CCScene::init()){
        return false;
    }
    m_layerControllers=new CCDictionary();
    return true;
}

void YHScene::onEnter()
{
	CCScene::onEnter();
    loadContents();
}

void YHScene::onExit()
{
	CCScene::onExit();
}

void YHScene::loadContents()
{

}

void YHScene::addLayerController(YHLayerController* layerController)
{
//	addLayerController(layerController,layerController->getName().c_str());
	m_layerControllers->setObject(layerController,layerController->getName());
//    addChild(layerController->getLayer());
//    m_layerControllers->addObject(layerController);
//	layerController->layerWillAppear();
//    layerController->layerDidAppear();
}

void YHScene::addLayerController(YHLayerController* layerController,const std::string& name)
{
	layerController->setName(name);
	addLayerController(layerController);
}

void YHScene::removeLayerController(YHLayerController* layerController)
{
	removeLayerControllerByName(layerController->getName());
//	layerController->layerWillDisappear();
//    removeChild(layerController->getLayer());
//    m_layerControllers->removeObject(layerController);
//    layerController->layerDidDisappear();
}

void YHScene::removeLayerControllerByName(const std::string& name)
{
	m_layerControllers->removeObjectForKey(name);
}

YHLayerController* YHScene::getLayerControllerByName(const std::string& name)
{
    return static_cast<YHLayerController*>(m_layerControllers->objectForKey(name));
}

NS_CC_YHMVC_END