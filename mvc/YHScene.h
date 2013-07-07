#ifndef COCOS_YHMVC_YHSCENE_H_
#define COCOS_YHMVC_YHSCENE_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

typedef struct {
    
    unsigned int appearState:2;
    unsigned int layerLoadFromDefineData:1;
    unsigned int isLoaded:1;
    
    unsigned int revert:4;//just for 8 int times
    
    
} SceneFlag;

enum LayerTag{
    kDefaultLayerTag=0
};

class YHScene : public CCScene
{
    
public:
    
    YHScene();
    
    ~YHScene();
      
    CREATE_FUNC(YHScene);
    
    virtual void onEnter();
    
    virtual void onExit();
    
    //默认从描述文件中加载.
	//也可以覆盖，手动创建
    void loadLayer();
    
    void layerDidLoad();    
    
    void layerWillUnload();
    
    void layerDidUnload();
    
    bool isLayerLoaded();
    
public:    
    
    CCLayer* getLayer(int nLayerTag);
    
    inline CCArray* getLayers(){
        return m_pChildren;
    };
    
protected:
    
    void addLayer(CCLayer* pLayer,int layerTag);
	   
protected:
    
    SceneFlag m_tState={0};
    
    std::string m_sDefineDataName;  
    
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHSCENE_H_
