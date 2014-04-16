#ifndef YHGUI_WIDGETS_LIST_H_
#define YHGUI_WIDGETS_LIST_H_

#include "../Container.h"

NS_CC_YHGUI_BEGIN

class ListItem:public Component
{
public:
    ListItem();
    ~ListItem();

};

class List:public Container
{
public:
    
    List();
    
    ~List();

    //==================交互事件=====================//
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);

    enum ListDirection
    {
        kVerticalList=1,
        kHorizontalList=2
    };
    
    inline void setDirection(int direction)
    {
        m_direction = direction;
    }
    
    inline int getDirection()
    {
        return m_direction;
    }
    
protected:
    
    /**
     * 更新元素的位置
     */
    void updateLayout();
    
protected:
    
    int m_direction;
    
    CCArray* m_items;
    
    bool m_layoutDirty;
};


NS_CC_YHGUI_END

#endif // YHGUI_WIDGETS_LIST_H_
