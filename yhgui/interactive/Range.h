#ifndef COCOS_YHGUI_INTERACTIVE_RANGE_H_
#define COCOS_YHGUI_INTERACTIVE_RANGE_H_

#include "cocos2d.h"
#include "../YHGUIMacros.h"

NS_CC_YHGUI_BEGIN

class Range
{
public:
    inline Range()
    :minX(0.0f)
    ,maxX(0.0f)
    ,minY(0.0f)
    ,maxY(0.0f)
    {
        
    };
    
    inline Range(float _minX,float _minY,float _maxX,float _maxY)
    :minX(_minX)
    ,maxX(_maxX)
    ,minY(_minY)
    ,maxY(_maxY)
    {
        
    }
    
    inline Range(const CCRect& rect)
    :minX(rect.origin.x)
    ,maxX(rect.origin.x+rect.size.width)
    ,minY(rect.origin.y)
    ,maxY(rect.origin.y+rect.size.height)
    {
        
    }
    
    inline Range(const Range& range)
    :minX(range.minX)
    ,maxX(range.maxX)
    ,minY(range.minY)
    ,maxY(range.maxY)
    {
        
    }
    
    inline void setRange(float _minX,float _minY,float _maxX,float _maxY)
    {
        minX=_minX;
        maxX=_maxX;
        minY=_minY;
        maxY=_maxY;
        
    }
    
    bool equals(const Range& range) const;
    bool containsPoint(const CCPoint& point) const;
    bool intersectsRange(const Range& range) const;
    
public:
    /**
     * 使用min max 比left,top,right,bottom更适应不同坐标系。
     */
    float minX;
    float maxX;
    float minY;
    float maxY;
    
};

const Range RangeZero=Range(0, 0, 0, 0);

NS_CC_YHGUI_END

#endif // COCOS_YHGUI_INTERACTIVE_RANGE_H_
