#include "BaseScene.h"

USING_NS_CC;

NS_YH_BEGIN

BaseScene::BaseScene()
{
    
    
}

BaseScene::~BaseScene()
{

}


bool BaseScene::init()
{

    if ( !CCScene::init() )
    {
        return false;
    }
        
    return true;
}


void BaseScene::onEnter()
{
    
}

void BaseScene::onExit()
{

}

NS_YH_END