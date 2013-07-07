#include "YHSceneDirector.h"

NS_CC_YHMVC_BEGIN

YHSceneDirector::YHSceneDirector()
:m_sDefineDataName("")
{
    
    
}

YHSceneDirector::~YHSceneDirector()
{

}

CCLayer* YHSceneDirector::getLayer(int nLayerTag)
{
    return (CCLayer*) this->getChildByTag(nLayerTag);
}


//默认从描述文件中加载
void YHSceneDirector::loadLayer()
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


void YHSceneDirector::layerDidLoad()
{
    
}

void YHSceneDirector::layerWillUnload()
{
    
}

void YHSceneDirector::layerDidUnload()
{
    
}

bool YHSceneDirector::isLayerLoaded()
{
    return m_tState.isLoaded;
}

void YHSceneDirector::onEnter()
{
    this->loadLayer();
    m_tState.isLoaded=true;
    this->layerDidLoad();
}

void YHSceneDirector::onExit()
{
    this->layerWillUnload();
    this->removeAllChildrenWithCleanup(true);
    m_tState.isLoaded=false;
    this->layerDidUnload();
}

void YHSceneDirector::addLayer(CCLayer* pLayer,int nLayerTag)
{
    this->addChild(pLayer,0,nLayerTag);
}

NS_CC_YHMVC_END