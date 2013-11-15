#include "Range.h"

NS_CC_YHGUI_BEGIN
	
bool Range::equals(const Range& range) const
{
    return minX==range.minX && maxX==range.maxX && maxY==range.maxY && minY==range.minY;
}

bool Range::containsPoint(const CCPoint& point) const
{
    return point.x >= minX && point.x <= maxX
            && point.y >= minY && point.y <= maxY;
}

bool Range::intersectsRange(const Range& range) const
{
    return !(     maxX < range.minX ||
             range.maxX <      minX ||
             maxY < range.minY ||
             range.maxY <      minY);
}

NS_CC_YHGUI_END