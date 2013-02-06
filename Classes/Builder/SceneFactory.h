#ifndef SCENE_FACTORY_H_
#define SCENE_FACTORY_H_

#include "cocos2d.h"
#include "GameMacros.h"

USING_NS_CC;

NS_YH_BEGIN

typedef CCScene* (CCObject::*SEL_SceneCreater)();
#define sceneCreater_selector(_SELECTOR) (SEL_SceneCreater)(&_SELECTOR)

class SceneFactory : public CCObject
{
public:
    
    virtual bool init();
    
    static SceneFactory* defaultSceneFactory();
    
    CCScene* createScene(const char* sceneType);
    
    void registerSceneCreater(const char* sceneType,SEL_SceneCreater sceneCreater);
    
};

NS_YH_END

#endif // SCENE_FACTORY_H_
