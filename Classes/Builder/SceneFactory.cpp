#include "SceneFactory.h"

USING_NS_CC;

NS_YH_BEGIN

bool SceneFactory::init()
{  
    return true;
}

CCScene* SceneFactory::createScene(const char* name)
{
    return CCScene::create();
}


NS_YH_END