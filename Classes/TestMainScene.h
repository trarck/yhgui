#ifndef __TestMain_SCENE_H__
#define __TestMain_SCENE_H__

#include "cocos2d.h"

class TestMain : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    void testButtonCallback(CCObject* pSender);
    
    void testOrganizerCallback(CCObject* pSender);
    
    void testCallback(CCObject* pSender);
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(TestMain);
};

#endif // __TestMain_SCENE_H__
