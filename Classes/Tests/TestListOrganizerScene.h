#ifndef __TestListOrganizer_SCENE_H__
#define __TestListOrganizer_SCENE_H__

#include "cocos2d.h"
#include "Event/Event.h"

class TestListOrganizer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    void testPerformanceCallback(CCObject* pSender);
    void testZOrderCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(TestListOrganizer);
};

#endif // __TestListOrganizer_SCENE_H__
