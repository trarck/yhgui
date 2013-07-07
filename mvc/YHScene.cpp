#include "YHScene.h"

NS_CC_YHMVC_BEGIN

YHScene::YHScene()
:m_sDefineDataName("")
{
    
    
}

YHScene::~YHScene()
{

}

CCLayer* YHScene::getLayer(int nLayerTag)
{
    return (CCLayer*) this->getChildByTag(nLayerTag);
}


//默认从描述文件中加载
void YHScene::loadLayer()
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


void YHScene::layerDidLoad()
{
    
}

void YHScene::layerWillUnload()
{
    
}

void YHScene::layerDidUnload()
{
    
}

bool YHScene::isLayerLoaded()
{
    return m_tState.isLoaded;
}

void YHScene::onEnter()
{
    this->loadLayer();
    m_tState.isLoaded=true;
    this->layerDidLoad();
}

void YHScene::onExit()
{
    this->layerWillUnload();
    this->removeAllChildrenWithCleanup(true);
    m_tState.isLoaded=false;
    this->layerDidUnload();
}

void YHScene::addLayer(CCLayer* pLayer,int nLayerTag)
{
    this->addChild(pLayer,0,nLayerTag);
}

NS_CC_YHMVC_END