#include "BaseSceneController.h"

USING_NS_CC;

NS_YH_BEGIN

BaseSceneController::BaseSceneController()
:m_sDefineDataName("")
,m_pScene(NULL)
{
    
    
}

BaseSceneController::~BaseSceneController()
{
    this->onExit();
}

// on "init" you need to initialize your instance
bool BaseSceneController::init()
{
       
    return true;
}

CCScene* BaseSceneController::getScene()
{
    if (!m_pScene) {
        this->loadScene();
        m_tState.isSceneLoaded=true;
        this->sceneDidLoad();
    }
    return m_pScene;
}

//默认从描述文件中加载
void BaseSceneController::loadScene()
{
    if(m_sDefineDataName==""){
        //create a empty scene
        m_pScene=new CCScene();
        
    }else{
        //TODO load from define file

    }
}


void BaseSceneController::sceneDidLoad()
{
    
}

void BaseSceneController::sceneWillUnload()
{
    
}

void BaseSceneController::sceneDidUnload()
{
    
}

bool BaseSceneController::isSceneLoaded()
{
    return m_tState.isSceneLoaded;
}

void BaseSceneController::setScene(CCScene* pScene)
{
    CC_SAFE_RETAIN(pScene);
    CC_SAFE_RELEASE(m_pScene);
    m_pScene = pScene;
}

void BaseSceneController::onEnter()
{
    
}

void BaseSceneController::onExit()
{
    this->sceneWillUnload();
    CC_SAFE_RELEASE(m_pScene);
    m_pScene=NULL;
    this->sceneDidUnload();
}

NS_YH_END