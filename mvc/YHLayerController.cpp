#include "YHLayerController.h"
#include "YHLayer.h"

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
    m_childLayerControllers=new CCArray();
    m_childLayerControllers->init();
    return true;
}

//默认从描述文件中加载
void YHLayerController::loadLayer()
{
    if(m_sDefineDataName==""){
        //create a empty layer
        YHLayer* layer=new YHLayer();
        layer->init();
        setLayer(layer);
		layer->release();
    }else{
        //TODO load from define file

    }
}


//layer.已经加载。如果是从配置文件中加载。此处提供而外操作
//比如绑定事件，修改文体内容
void YHLayerController::layerDidLoad()
{
    
}

/**
 * 当layer的onEnter事件执行时调用
 */
void YHLayerController::onLayerEnter()
{

}

/**
 * 当layer的onExit事件执行时调用
 */
void YHLayerController::onLayerExit()
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

void YHLayerController::setLayer(YHLayer* layer)
{
    CC_SAFE_RETAIN(layer);
	if(m_pLayer) m_pLayer->setLayerController(NULL);
    CC_SAFE_RELEASE(m_pLayer);
    m_pLayer = layer;
	if(m_pLayer) m_pLayer->setLayerController(this);
}


YHLayer* YHLayerController::getLayer()
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
    layerController->willAddToParentLayerController(this);
    m_childLayerControllers->addObject(layerController);
    layerController->setParent(this);
    layerController->didAddToParentLayerController(this);
}

void YHLayerController::removeChildLayerController(YHLayerController* layerController)
{
    layerController->willRemoveFromParentLayerController();
    m_childLayerControllers->removeObject(layerController);
    layerController->setParent(NULL);
    layerController->didRemoveFromParentLayerController();
}

void YHLayerController::removeFromParentLayerController()
{
    if (m_parent!=NULL){
        m_parent->removeChildLayerController(this);
    }
}

YHLayerController* YHLayerController::getLayerControllerByName(const std::string& name)
{
    CCObject* pObj=NULL;
    YHLayerController* layerController=NULL;
    CCARRAY_FOREACH(m_childLayerControllers, pObj){
        layerController=static_cast<YHLayerController*>(pObj);
        if (name.compare(layerController->getName())==0) {
            return layerController;
        }
    }
    return NULL;
}

void YHLayerController::willAddToParentLayerController(YHLayerController* parent)
{
    
}

void YHLayerController::didAddToParentLayerController(YHLayerController* parent)
{
    
}

void YHLayerController::willRemoveFromParentLayerController()
{
    
}

void YHLayerController::didRemoveFromParentLayerController()
{
    
}

NS_CC_YHMVC_END