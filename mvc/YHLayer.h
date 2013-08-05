#ifndef COCOS_YHMVC_YHLAYER_H_
#define COCOS_YHMVC_YHLAYER_H_

#include "cocos2d.h"
#include "YHMVCMacros.h"

NS_CC_YHMVC_BEGIN

class YHLayerController;

class YHLayer : public CCLayer
{
public:

	YHLayer();
	~YHLayer();
    
	bool init();  
	
	/**
	 * layer将要显示。
	 * 由于cocos2d没有实现显示动画，即onEnterTransitionDidFinish没有实际意义。
	 * 如果要自己实现显示动画，则可以忽略onEnterTransitionDidFinish。
	 */
	void onEnter();

	void onExit();

    CREATE_FUNC(YHLayer);

	inline void setLayerController(YHLayerController* layerController)
	{
		m_layerController = layerController;
	}

	inline YHLayerController* getLayerController()
	{
		return m_layerController;
	}

protected:
	YHLayerController* m_layerController;

};

NS_CC_YHMVC_END

#endif // COCOS_YHMVC_YHLAYER_H_
