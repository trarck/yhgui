#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "GameMacros.h"

USING_NS_CC;

NS_YH_BEGIN

typedef struct {
    
    unsigned int appearState:2;
    unsigned int layerLoadFromDefineData:1;
    unsigned int isLoaded:1;
    
    unsigned int revert:4;//just for 8 int times
    
    
} SceneFlag;

class BaseScene : public CCScene
{
    
public:
    
    BaseScene();
    
    ~BaseScene();
    
    virtual bool init();  
   
    CREATE_FUNC(BaseScene);
    
    virtual void onEnter();
    
    virtual void onExit();
    
    //默认从描述文件中加载
    void loadLayer();
    
    
    void layerDidLoad();
    
    bool isLayerLoaded();
    
    void layerWillUnload();
    
    void layerDidUnload();
    
public:
    
    void setLayer(CCLayer* pLayer);
    
    CCLayer* getLayer();
    
protected:
    
    SceneFlag m_tState={0};
    
    std::string m_sDefineDataName;
    
    CCLayer* m_pLayer;
    
    
    
};

NS_YH_END

#endif // __HELLOWORLD_SCENE_H__
