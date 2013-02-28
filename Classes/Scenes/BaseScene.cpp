#include "BaseScene.h"

USING_NS_CC;

NS_YH_BEGIN

BaseScene::BaseScene()
:m_sDefineDataName("")
{
    
    
}

BaseScene::~BaseScene()
{

}

CCLayer* BaseScene::getLayer(int nLayerTag)
{
    return (CCLayer*) this->getChildByTag(nLayerTag);
}


//默认从描述文件中加载
void BaseScene::loadLayer()
{
    if(m_sDefineDataName==""){
        //create a empty layer,named ui
        CCLayer* defaultLayer=new CCLayer();
        defaultLayer->setTag(kDefaultLayerTag);
        this->addChild(defaultLayer, 0, kDefaultLayerTag);
        
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

void BaseScene::onEnter()
{
    this->loadLayer();
    m_tState.isLoaded=true;
    this->layerDidLoad();
}

void BaseScene::onExit()
{
    this->layerWillUnload();
    this->removeAllChildrenWithCleanup(true);
    m_tState.isLoaded=false;
    this->layerDidUnload();
}

void BaseScene::addLayer(CCLayer* pLayer,int nLayerTag)
{
    this->addChild(pLayer,0,nLayerTag);
}

NS_YH_END