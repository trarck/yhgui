#include "ListOrganizer.h"

NS_CC_YHGUI_BEGIN
	
ListOrganizer::ListOrganizer()
:m_elements(NULL)
{
	
}
	
ListOrganizer::~ListOrganizer()
{
	CC_SAFE_RELEASE_NULL(m_elements);
}

bool ListOrganizer::init()
{
    if (Organizer::init()) {
        m_elements=new CCArray();
        m_elements->init();
        return true;
    }
    
    return false;
}

/**
 * 添加一个组件
 */
void ListOrganizer::addComponent(Component* component)
{
    m_elements->addObject(component);
}

/**
 * 删除一个组件
 */
void ListOrganizer::removeComponent(Component* component)
{
    m_elements->removeObject(component);
}

//==================交互事件=====================//
bool ListOrganizer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    CCPoint touchLocation = pTouch->getLocation();
    struct timeval start;
    struct timeval end;
    
    gettimeofday(&start, NULL);
    Component* target=getTargetContainPoint(touchLocation);
    
    gettimeofday(&end, NULL);
    
    CCLOG("use:%ld",(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec));

    if (target && target->isEnabled()) {
        //只有可用组件才可以处理事件
        setTarget(target);
        //trigger elem events
        return target->ccTouchBegan(pTouch, pEvent);
    }
    
    return false;
}

void ListOrganizer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    //只有有了target才会到此步，所以不需要判断target在不在
    m_target->ccTouchMoved(pTouch, pEvent);
}

void ListOrganizer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
    m_target->ccTouchEnded(pTouch, pEvent);
    //处理完成，把目录设置为空
    setTarget(NULL);
}

void ListOrganizer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{
    if (m_target) {
        m_target->ccTouchCancelled(pTouch, pEvent);
        setTarget(NULL);
    }
}

/**
 * 取得最上层元素包含要触摸点
 * 一直比较到最上层的元素
 * 二种方式：
 * 1.先处理是否在点击范围内，再进行排序处理。
 * 2.先进行排序，再测试是否在点击范围内。
 */
Component* ListOrganizer::getTargetContainPoint(const CCPoint& point)
{
    //先处理点击是否在元素范围内
    
    Component* elem=NULL;
    
    CCObject* pObj=NULL;
    
    CCArray* contains=CCArray::create();
    
    //包含
    std::vector<std::vector<CCNode*> > list;
    
    CCARRAY_FOREACH(m_elements, pObj){
        
        elem=dynamic_cast<Component*>(pObj);
        //检查是否可见。不可见则不接收事件
        if (elem && elem->isVisible()) {
            //如果组件不可用，则接收事件,但不处理。
            if (elem->isPointInside(point)){
                contains->addObject(elem);
                
                list.push_back(this->createAncestorList(elem));
            }
        }
    }
    
    if (list.size()) {
        //不用排序，直接取得最上面一个元素
        return  static_cast<Component*>(this->getTopElementWithAncestor(list));
    }

    return NULL;
}

/**
 * 创建从元素到最顶层元素的的列表
 */
std::vector<CCNode*> ListOrganizer::createAncestorList(CCNode* element)
{
    std::vector<CCNode*> list;
    list.push_back(element);
    
    CCNode* parent=element->getParent();
    
    while (parent!=NULL) {
        
        list.insert(list.begin(), element);
        
        parent=parent->getParent();
    }
    
    return list;
}

/**
 * 按祖先的关系获取是上面的元素
 */
CCNode* ListOrganizer::getTopElementWithAncestor(std::vector<std::vector<CCNode*> >& elementList)
{
    std::vector<std::vector<CCNode*> >::iterator maxIter=elementList.begin();
    
    std::vector<std::vector<CCNode*> >::iterator iter=maxIter+1;
    
    //取得最大的一个
    for (; iter!=elementList.end(); ++iter) {
        
        if (this->compareElementZOrderWithAncestor(*maxIter, *iter)<0){
            maxIter=iter;
        }
    }
    
    //最后一个元素是本来的元素，其它的都是先祖元素。
    return (*maxIter).back();
}

/**
 * 按祖先的关系排序元素
 */
void ListOrganizer::sortElementsWithAncestor(std::vector<std::vector<CCNode*> >& elementList)
{
    int listSize=elementList.size();
    for (int i=0; i<listSize; ++i) {
        for (int j=1; j<listSize-i; ++j) {
            if (this->compareElementZOrderWithAncestor(elementList[j-1], elementList[j])>0){
                std::vector<CCNode*> temp=elementList[j];
                elementList[j]=elementList[j-1];
                elementList[j-1]=temp;
            }
        }
    }
}

/**
 * 比较二个元素的层级大小
 * src-dest
 */
int ListOrganizer::compareElementZOrderWithAncestor(const std::vector<CCNode*>& src,const std::vector<CCNode*>& dest)
{
    int srcSize=src.size();
    int destSize=dest.size();
    int srcZOrder=0;
    int destZOrder=0;
    
    //src和dest的祖先是同一个元素
    for (int i=0; i<srcSize && i<destSize; ++i) {
        if (src[i]!=dest[i]) {
            srcZOrder=src[i]->getZOrder();
            destZOrder=dest[i]->getZOrder();
            
            return srcZOrder == destZOrder? (src[i]->getOrderOfArrival()-dest[i]->getOrderOfArrival()):(srcZOrder-destZOrder);
        }
    }
    
    //src和dest在同一个树的路径上.谁的路径长，谁就是子元素。子元素在上面。
    return srcSize-destSize;
}

/**
 * 比较二个元素的层级大小
 */
int ListOrganizer::compareElementZOrder(CCNode* src,CCNode* dest)
{
    std::vector<CCNode*> srcList=createAncestorList(src);
    std::vector<CCNode*> destList=createAncestorList(dest);
    
    CCAssert(srcList[0]==destList[0],"ListOrganizer::compareElementZOrder:the two objs nust in the same scene");
    
    return this->compareElementZOrderWithAncestor(srcList, destList);
}


NS_CC_YHGUI_END