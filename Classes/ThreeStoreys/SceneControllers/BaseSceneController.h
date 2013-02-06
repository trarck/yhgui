#ifndef BASESCENECONTROLLER_H_
#define BASESCENECONTROLLER_H_

#include "cocos2d.h"
#include "GameMacros.h"

USING_NS_CC;

NS_YH_BEGIN

typedef struct {
    
    unsigned int appearState:2;
    unsigned int sceneLoadFromDefineData:1;
    unsigned int isSceneLoaded:1;
    
    unsigned int revert:4;//just for 8 int times
    
    
} SceneControllerFlag;

class BaseSceneController : public CCObject
{

public:
    
    BaseSceneController();
    
    ~BaseSceneController();
    
    virtual bool init();
     
    //默认从描述文件中加载
    void loadScene();
    
    void sceneDidLoad();
    
    bool isSceneLoaded();
    
    void sceneWillUnload();
    
    void sceneDidUnload();
	
	void onEnter();
	
	void onExit();
    
public:
    
    void setScene(CCScene* pScene);
    
    CCScene* getScene();
    
protected:
    
    SceneControllerFlag m_tState={0};
    
    std::string m_sDefineDataName;
    
    CCScene* m_pScene;
    
    
    
};

NS_YH_END

#endif // BASESCENECONTROLLER_H_
