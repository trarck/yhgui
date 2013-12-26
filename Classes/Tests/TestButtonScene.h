#ifndef __TestButton_SCENE_H__
#define __TestButton_SCENE_H__

#include "cocos2d.h"
#include "Event/Event.h"

class TestButton : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    void onTouchDown(cocos2d::yhlib::Event* event);
    void onTouchMove(cocos2d::yhlib::Event* event);
    void onTouchMoveEnter(cocos2d::yhlib::Event* event);
    void onTouchMoveExit(cocos2d::yhlib::Event* event);
    void onTouchUpInside(cocos2d::yhlib::Event* event);
    void onTouchUpOutside(cocos2d::yhlib::Event* event);
    
    void onBack(cocos2d::yhlib::Event* event);
    
    // implement the "static node()" method manually
    CREATE_FUNC(TestButton);
};

#endif // __TestButton_SCENE_H__
