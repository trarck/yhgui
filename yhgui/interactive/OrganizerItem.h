#ifndef COCOS_YHGUI_INTERACTIVE_ORGANIZERITEM_H_
#define COCOS_YHGUI_INTERACTIVE_ORGANIZERITEM_H_

#include "cocos2d.h"
#include "../YHGUIMacros.h"
#include "Range.h"

NS_CC_YHGUI_BEGIN

class OrganizerItem:public CCObject
{
public:
    OrganizerItem()
    :m_range(Range())
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

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_ORGANIZERITEM_H_
