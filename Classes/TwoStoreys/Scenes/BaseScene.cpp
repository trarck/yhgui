#include "BaseScene.h"
#include "SimpleAudioEngine.h"
#include "json/json.h"

USING_NS_CC;

NS_YH_BEGIN

BaseScene::BaseScene()
:m_sDefineDataName("")
,m_pLayer(NULL)
{
    
    
}

BaseScene::~BaseScene()
{
    CC_SAFE_RELEASE(m_pLayer);
}

// on "init" you need to initialize your instance
bool BaseScene::init()
{

    if ( !CCScene::init() )
    {
        return false;
    }
        
    return true;
}

CCLayer* BaseScene::getLayer()
{
    if (!m_pLayer) {
        this->loadLayer();
        m_tState.isLoaded=true;
        this->layerDidLoad();
    }
    return m_pLayer;
}

//默认从描述文件中加载
void BaseScene::loadLayer()
{
    if(m_sDefineDataName==""){
        //create a empty layer
        m_pLayer=new CCLayer();
        
    }else{
        //TODO load from define file

    }
}


void BaseScene::layerDidLoad()
{
    
}

void BaseScene::layerWillUnload()
{
    
}

void BaseScene::layerDidUnload()
{
    
}

bool BaseScene::isLayerLoaded()
{
    return m_tState.isLoaded;
}

void BaseScene::setLayer(CCLayer* pLayer)
{
    CC_SAFE_RETAIN(pLayer);
    CC_SAFE_RELEASE(m_pLayer);
    m_pLayer = pLayer;
}

void BaseScene::onEnter()
{
    this->loadLayer();
    m_tState.isLoaded=true;
    this->layerDidLoad();
}

void BaseScene::onExit()
{
    this->layerWillUnload();
    CC_SAFE_RELEASE(m_pLayer);
    m_pLayer=NULL;
    this->layerDidUnload();
}

NS_YH_END