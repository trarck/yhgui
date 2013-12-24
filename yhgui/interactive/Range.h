#ifndef COCOS_YHGUI_INTERACTIVE_RANGE_H_
#define COCOS_YHGUI_INTERACTIVE_RANGE_H_

#include "cocos2d.h"
#include "../YHGUIMacros.h"

NS_CC_YHGUI_BEGIN

class Range
{
public:
    inline Range()
    :tl(CCPointZero)
    ,tr(CCPointZero)
    ,bl(CCPointZero)
    ,br(CCPointZero)
    {
        
    };
    
    inline Range(const CCPoint& _tl,const CCPoint& _tr,const CCPoint& _bl,const CCPoint& _br)
    :tl(_tl)
    ,tr(_tr)
    ,bl(_bl)
    ,br(_br)
    {
        
    }
    
    inline Range(const Range& range)
    :tl(range.tl)
    ,tr(range.tr)
    ,bl(range.bl)
    ,br(range.br)
    {
        
    }
    
    inline void setRange(const CCPoint& _tl,const CCPoint& _tr,const CCPoint& _bl,const CCPoint& _br)
    {
        tl=_tl;
        tr=_tr;
        bl=_bl;
        br=_br;
    }
    
    bool equals(const Range& range) const;
    bool containsPoint(const CCPoint& point) const;
    bool collideRange(const Range& range) const;
    
public:
    
    /**
     * 规定x正方向为右，负方向为左;y正方向为上，负方向为下.
     */
    CCPoint tl;
    CCPoint tr;
    CCPoint bl;
    CCPoint br;
    
};

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_RANGE_H_
