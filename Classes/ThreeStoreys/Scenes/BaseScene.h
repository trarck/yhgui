#ifndef SCENES_BASESCENE_H_
#define SCENES_BASESCENE_H_

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
    
    virtual void onEnter();
    
    virtual void onExit();
    
public:
    
    
protected:
    
    SceneFlag m_tState={0};
   
};

NS_YH_END

#endif // SCENES_BASESCENE_H_
