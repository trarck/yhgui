#ifndef COCOS_YHMVC_YHSCENEDIRECTOR_H_
#define COCOS_YHMVC_YHSCENEDIRECTOR_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class YHSceneDirector : public CCScene
{
    
public:
    
    YHSceneDirector();
    
    ~YHSceneDirector();
      
    CREATE_FUNC(YHSceneDirector);
    
    
    
public:    
    void runWithScene(CCScene *pScene)
    void pushScene(CCScene* scene);
    void popScene();
    void popToRootScene();
	void popToSceneStackLevel(int level);
    void replaceScene(CCScene *pScene);
protected:
    
    CCArray* m_sceneStack;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHSCENEDIRECTOR_H_
