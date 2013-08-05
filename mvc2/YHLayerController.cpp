#include "YHLayerController.h"

NS_CC_YHMVC_BEGIN

YHLayerController::YHLayerController()
:m_sDefineDataName("")
,m_pLayer(NULL)
,m_childLayerControllers(NULL)
,m_parent(NULL)
{
    
}

YHLayerController::~YHLayerController()
{
    CC_SAFE_RELEASE_NULL(m_pLayer);
    CC_SAFE_RELEASE_NULL(m_childLayerControllers);
    m_parent=NULL;
}

// on "init" you need to initialize your instance
bool YHLayerController::init()
{
    return true;
}

//默认从描述文件中加载
void YHLayerController::loadLayer()
{
    if(m_sDefineDataName==""){
        //create a empty layer
        m_pLayer=new CCLayer();
        m_pLayer->init();
        
    }else{
        //TODO load from define file

    }
}


//layer.已经加载。如果是从配置文件中加载。此处提供而外操作
//比如绑定事件，修改文体内容
void YHLayerController::layerDidLoad()
{
    
}

void YHLayerController::layerWillAppear()
{
    
}

void YHLayerController::layerDidAppear()
{
    
}

void YHLayerController::layerWillDisappear()
{
    
}

void YHLayerController::layerDidDisappear()
{
    
}

bool YHLayerController::isLayerLoaded()
{
    return m_tState.isLoaded;
}

void YHLayerController::setLayer(CCLayer* layer)
{
    CC_SAFE_RETAIN(layer);
    CC_SAFE_RELEASE(m_pLayer);
    m_pLayer = layer;
}


CCLayer* YHLayerController::getLayer()
{
    if (!m_pLayer) {
        this->loadLayer();
        m_tState.isLoaded=true;
        this->layerDidLoad();
    }
    return m_pLayer;
}

//==================child layer controller=================//

void YHLayerController::addChildLayerController(YHLayerController* layerController)
{
    layerController->layerWillAppear();
    m_pLayer->addChild(layerController->getLayer());
    m_childLayerControllers->addObject(layerController);
    layerController->setParent(this);
    layerController->layerDidAppear();
}

void YHLayerController::removeChildLayerController(YHLayerController* layerController)
{
    layerController->layerWillDisappear();
    layerController->setParent(NULL);
    m_childLayerControllers->removeObject(layerController);
    m_pLayer->removeChild(layerController->getLayer());
    layerController->layerDidDisappear();
}

void YHLayerController::removeFromParentLayerController()
{
    if (m_parent!=NULL){
        m_parent->removeChildLayerController(this);
    }
}

void YHLayerController::willMoveToParentViewController(YHLayerController* parent)
{
    
}

void YHLayerController::didMoveToParentViewController(YHLayerController* parent)
{
    
}

NS_CC_YHMVC_END