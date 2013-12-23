#include "Range.h"



USING_NS_CC;

NS_CC_YHGUI_BEGIN

bool Range::equals(const Range& range) const
{
    return tl.equals(range.tl)
        && tr.equals(range.tr)
        && bl.equals(range.bl)
        && br.equals(range.br);
}

/**
 * 检查每个边的向量和边的起始点和检查点组成的向量的叉积是否同向。
 */
bool Range::containsPoint(const CCPoint& point) const
{

    //矩形方向.取第一条边的检查点的方向。
    int rangeDirection=0;

    int sideDirection=0;
    
    //检查Top和点的关系
    CCPoint checkVector=ccp(point.x-tl.x,point.y-tl.y);
    CCPoint topVector=ccp(tr.x-tl.x, tr.y-tr.x);
    
    rangeDirection=topVector.cross(checkVector);
    
    
    //检查right和点的关系
    checkVector=ccp(point.x-tr.x,point.y-tr.y);
    CCPoint rightVector=ccp(br.x-tr.x,br.y-tr.y);
    
    sideDirection=rightVector.cross(checkVector);
    
    if (rangeDirection*sideDirection<0) {
        return false;
    }
    
    //检查bottom和点的关系
    checkVector=ccp(point.x-br.x,point.y-br.y);
    CCPoint bottomVector=ccp(bl.x-br.x,bl.y-br.y);
    
    sideDirection=bottomVector.cross(checkVector);
    
    if (rangeDirection*sideDirection<0) {
        return false;
    }
    
    //检查left和点的关系
    checkVector=ccp(point.x-br.x,point.y-br.y);
    CCPoint leftVector=ccp(tl.x-bl.x,tl.y-bl.y);
    
    sideDirection=leftVector.cross(checkVector);
    
    if (rangeDirection*sideDirection<0) {
        return false;
    }
    
    return true;
}


static void projectRange(const CCPoint& axis,const Range& range,float* min,float* max)
{
    float project=axis.dot(range.tl);
    
    *min=project;
    *max=project;
    
    project=axis.dot(range.tr);
    if (project<(*min)) {
        *min=project;
    }else if(project>(*max)){
        *max=project;
    }
    
    project=axis.dot(range.br);
    if (project<(*min)) {
        *min=project;
    }else if(project>(*max)){
        *max=project;
    }
    
    project=axis.dot(range.bl);
    if (project<(*min)) {
        *min=project;
    }else if(project>(*max)){
        *max=project;
    }
}

static inline bool isOverlap(float minA,float maxA,float minB,float maxB)
{
    return minA<=maxB && minB<=maxA;
}

static bool checkEdge(const CCPoint& edgePointA,const CCPoint& edgePointB,const Range& one,const Range& other)
{
    //check top
    CCPoint edge = ccp(edgePointB.x-edgePointA.x,edgePointB.y-edgePointA.y);
    
    CCPoint prep=edge.getPerp();
    
    float selfMin=0,selfMax=0,otherMin=0,otherMax=0;
    
    projectRange(prep, one, &selfMin, &selfMax);
    projectRange(prep, other, &otherMin, &otherMax);

    return isOverlap(selfMin,selfMax,otherMin,otherMax);
}

/**
 * 使用分离轴法检查矩形是否相交
 */
bool Range::collideRange(const Range& range) const
{
    CCPoint one[4]={CCPointZero};
    
    one[0].x=tr.x-tl.x;
    one[0].y=tr.y-tl.y;
    one[1].x=br.x-tr.x;
    one[1].y=br.y-tr.y;
    one[2].x=bl.x-br.x;
    one[2].y=bl.y-br.y;
    one[3].x=tl.x-bl.x;
    one[3].y=tl.y-bl.y;
    
    CCPoint other[4]={CCPointZero};
    other[0].x=range.tr.x-range.tl.x;
    other[0].y=range.tr.y-range.tl.y;
    other[1].x=range.br.x-range.tr.x;
    other[1].y=range.br.y-range.tr.y;
    other[2].x=range.bl.x-range.br.x;
    other[2].y=range.bl.y-range.br.y;
    other[3].x=range.tl.x-range.bl.x;
    other[3].y=range.tl.y-range.bl.y;
    
    //检查以自己的边的轴的投影是否重合
    
    if (!checkEdge(tl,tr,*this,range)) {
        return false;
    }
    
    if (!checkEdge(tr,br,*this,range)) {
        return false;
    }
    
    if (!checkEdge(br,bl,*this,range)) {
        return false;
    }
    if (!checkEdge(bl,tl,*this,range)) {
        return false;
    }
    
    //检查以对方的边的轴的投影是否重合
    
    if (!checkEdge(range.tl,range.tr,*this,range)) {
        return false;
    }
    
    if (!checkEdge(range.tr,range.br,*this,range)) {
        return false;
    }
    
    if (!checkEdge(range.br,range.bl,*this,range)) {
        return false;
    }
    if (!checkEdge(range.bl,range.tl,*this,range)) {
        return false;
    }
    
    return true;
}

NS_CC_YHGUI_END