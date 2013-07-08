#ifndef COCOS_YHMVC_YHLAYERCONTROLLER_H_
#define COCOS_YHMVC_YHLAYERCONTROLLER_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

typedef struct {
    
    unsigned int appearState:2;
    unsigned int loadFromDefineData:1;
    unsigned int isLoaded:1;
    
    unsigned int revert:4;//just for 8 int times
    
    
} LayerControllerFlag;

class YHLayerController : public CCObject
{

public:
    
    YHLayerController();
    
    ~YHLayerController();
    
    virtual bool init();
     
    //默认从描述文件中加载
    virtual void loadLayer();
    
    //layer.已经加载。如果是从配置文件中加载。此处提供而外操作
    //比如绑定事件，修改文体内容
    virtual void layerDidLoad();    
    
    virtual void layerWillAppear();

    virtual void layerDidAppear();

    virtual void layerWillDisappear();

    virtual void layerDidDisappear();
    
    bool isLayerLoaded();
       
    void setLayer(CCLayer* layer);
    
    CCLayer* getLayer();

    //==================child layer controller=================//
    void addChildLayerController(YHLayerController* layerController);

    void removeChildLayerController(YHLayerController* layerController);
    
    void removeFromParentLayerController();

    void willMoveToParentViewController(YHLayerController* parent);

    void didMoveToParentViewController(YHLayerController* parent);

protected:
    
    LayerControllerFlag m_tState;
    
    std::string m_sDefineDataName;
    
    CCLayer* m_pLayer;

    CCArray* m_childLayerControllers;
};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHLAYERCONTROLLER_H_
