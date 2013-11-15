#ifndef COCOS_YHGUI_INTERACTIVE_ORGANIZER_H_
#define COCOS_YHGUI_INTERACTIVE_ORGANIZER_H_

#include "cocos2d.h"
#include "../YHGUIMacros.h"
#include "Range.h"

NS_CC_YHGUI_BEGIN

class OrganizerItem:public CCObject
{
public:
    OrganizerItem()
    :m_range(RangeZero)
    ,m_node(NULL)
    ,m_dynamic(true)
    {
        
    }
    
    /**
     * 是否包含某个点(world point)
     */
    bool containPoint(CCPoint point);
    
    /**
     * 是否在某个区域内(world rect)
     */
    bool inRange(CCRect rect);
    
    /**
     * 把node转成全局的
     */
    void calcRange();
    
    inline void setRange(Range range)
    {
        m_range = range;
    }
    
    inline Range getRange()
    {
        return m_range;
    }
    
    inline void setNode(CCNode* node)
    {
        CC_SAFE_RETAIN(node);
        CC_SAFE_RELEASE(m_node);
        m_node = node;
        if (!m_dynamic) {
            
        }
    }
    
    inline CCNode* getNode()
    {
        return m_node;
    }
    
    inline void setDynamic(bool dynamic)
    {
        m_dynamic = dynamic;
    }
    
    inline bool isDynamic()
    {
        return m_dynamic;
    }
    
protected:
    /**
     * 结点的全局区域。即世界坐标。
     */
     Range m_range;
    
    /**
     * 结点对应的node
     */
    CCNode* m_node;
    
    /**
     * rect 是否是动态的。只要node的matrix改变，rect就要改变。
     */
    bool m_dynamic;
};

/**
 * 处理交互事件
 * 主要接管touch事件
 * SAT
 * 注意:对于点，世界做标和本地坐标没有区别。
       对于矩形区域在转成世界坐标的时候，新的矩形和以前可能不一样。同样世界坐标转成本地坐标也会不一样。
       对于矩形和点的比较，则把点转换成矩形的本地坐标进行比较。
       对于矩形和矩形的比较，首先比较一个矩形的中心，再比较4个顶点是否在另一个矩形内。按矩形与点的比较方法。
 */
class Organizer:public CCObject
{
public:
    
    Organizer();
    
    ~Organizer();

    CCArray* getNodesInRange(CCRect range);
    
    CCArray* getNodesContainPoint(CCPoint point);
    
    
protected:
    

private:
    
    
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_ORGANIZER_H_
