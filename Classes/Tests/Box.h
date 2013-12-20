//
//  Box.h
//  CCUI
//
//  Created by duanhouhai on 13-12-18.
//
//

#ifndef __CCUI__Box__
#define __CCUI__Box__

#include "yhgui/yhgui.h"

class Box:public cocos2d::yhgui::Component
{
public:
    
    void draw()
    {
        cocos2d::ccDrawColor4B(color.r, color.g, color.b, color.a);
        cocos2d::ccDrawRect(ccp(0,0),ccp(m_obContentSize.width, m_obContentSize.height));
    }
    
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
    {
        CCLOG("touch:%d,%d",x,y);
        return Component::ccTouchBegan(pTouch, pEvent);
    }
    
    CREATE_FUNC(Box);
    
    cocos2d::ccColor4B color;
    
    int x;
    int y;
};

class SolidBox:public cocos2d::yhgui::Component
{
public:
    
    void draw()
    {
        cocos2d::ccDrawSolidRect(ccp(0,0),ccp(m_obContentSize.width, m_obContentSize.height),ccc4FFromccc4B(color));
    }
    
    bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
    {
        CCLOG("touch:%d,%d",x,y);
        return Component::ccTouchBegan(pTouch, pEvent);
    }
    
    CREATE_FUNC(SolidBox);
    
    cocos2d::ccColor4B color;
    
    int x;
    int y;
};

#endif /* defined(__CCUI__Box__) */
