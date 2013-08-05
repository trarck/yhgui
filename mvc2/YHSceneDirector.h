#ifndef COCOS_YHMVC_YHSCENEDIRECTOR_H_
#define COCOS_YHMVC_YHSCENEDIRECTOR_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class YHScene;

class YHSceneDirector : public CCObject
{
    
public:
    
    YHSceneDirector();
    
    ~YHSceneDirector();
      
    static YHSceneDirector* getInstance();
   
    void runWithScene(YHScene *pScene);
    void pushScene(YHScene* scene);
    void popScene();
    void popToRootScene();
	void popToSceneStackLevel(int level);
    void replaceScene(YHScene *pScene);
protected:
    
    CCArray* m_scenesStack;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHSCENEDIRECTOR_H_
