#include "Utils.h"

NS_CC_YHGUI_BEGIN

/**
 * 合并二个rect
 */
CCRect Utils::CCRectUnion(const CCRect& src1, const CCRect& src2)
{
    CCRect result;
    
    float x1 = MIN(src1.getMinX(), src2.getMinX());
    float y1 = MIN(src1.getMinY(), src2.getMinY());
    float x2 = MAX(src1.getMaxX(), src2.getMaxX());
    float y2 = MAX(src1.getMaxY(), src2.getMaxY());
    
    result.origin=ccp(x1,y1);
    result.size=CCSizeMake(x2-x1, y2-y1);
    return result;
}

/**
 * touch是否在target内
 */
bool Utils::isTouchInside(CCTouch* touch,CCNode* target)
{
    CCPoint touchLocation = touch->getLocation(); // Get the touch position
    touchLocation = target->getParent()->convertToNodeSpace(touchLocation);
    CCRect bBox=target->boundingBox();
    return bBox.containsPoint(touchLocation);
}

NS_CC_YHGUI_END