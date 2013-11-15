#include "Organizer.h"

NS_CC_YHGUI_BEGIN

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
    if (m_dynamic) {
        CCRect localRect=CCRectApplyAffineTransform(rect, m_node->worldToNodeTransform());
        CCRect bBox=m_node->boundingBox();
        return localRect.getMinX()<=bBox.getMinX() && bBox.getMaxX()<=localRect.getMaxX()
                && localRect.getMinY()<=bBox.getMinY() && bBox.getMaxY()<=localRect.getMaxY();
    }else{
        return rect.getMinX()<=m_range.minX && m_range.maxX<=rect.getMaxX()
               && rect.getMinY()<=m_range.minY && m_range.maxY<=rect.getMaxY();
    }
}

Organizer::Organizer()
{
	
}

Organizer::~Organizer()
{
	
}

NS_CC_YHGUI_END