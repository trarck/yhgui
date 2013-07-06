#include "YHLayerController.h"

NS_CC_YHGUI_BEGIN

YHLayerController::YHLayerController()
:m_sDefineDataName("")
,m_pLayer(NULL)
{
    
}

YHLayerController::~YHLayerController()
{
    CC_SAFE_RELEASE_NULL(m_pLayer);
}

// on "init" you need to initialize your instance
bool YHLayerController::init()
{
    return true;
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


void YHLayerController::layerDidLoad()
{
    
}

void YHLayerController::viewWillAppear()
{

}

void YHLayerController::viewDidAppear()
{

}

void YHLayerController::viewWillDisappear()
{

}

void YHLayerController::viewDidDisappear()
{

}

bool YHLayerController::isLayerLoaded()
{
    return m_tState.isLoaded;
}

void YHLayerController::setLayer(CCScene* layer)
{
    CC_SAFE_RETAIN(layer);
    CC_SAFE_RELEASE(m_pLayer);
    m_pLayer = layer;
}

NS_CC_YHGUI_END