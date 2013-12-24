#include "OrganizerItem.h"

NS_CC_YHGUI_BEGIN

/**
 * 把rect转成Range
 */
Range convertCCRectToRange(const CCRect& rect)
{
    return Range(
          ccp(rect.origin.x,rect.origin.y+rect.size.height),
          ccp(rect.origin.x+rect.size.width,rect.origin.y+rect.size.height),
          rect.origin,
          ccp(rect.origin.x+rect.size.width,rect.origin.y));
}

/**
 * 是否包含某个点
 */
bool OrganizerItem::containPoint(CCPoint point)
{
    if (m_dynamic) {
        CCPoint localPoint=m_node->convertToNodeSpace(point);
        CCRect bBox=m_node->boundingBox();
        return bBox.containsPoint(localPoint);
    }else{
        return m_range.containsPoint(point);
    }
}

/**
 * 是否在某个区域内
 */
bool OrganizerItem::inRange(CCRect rect)
{
    Range destRange=convertCCRectToRange(rect);
    
    if (m_dynamic) {
        CCRect bBox=m_node->boundingBox();
        Range srcRange=convertCCRectToRange(bBox);
        return srcRange.collideRange(destRange);
    }else{
        Range destRange=Range(
                              ccp(rect.origin.x,rect.origin.y+rect.size.height),
                              ccp(rect.origin.x+rect.size.width,rect.origin.y+rect.size.height),
                              rect.origin,
                              ccp(rect.origin.x+rect.size.width,rect.origin.y));
        
        return m_range.collideRange(destRange);
    }
}

NS_CC_YHGUI_END