#include "Event.h"

NS_CC_YHLIB_BEGIN

Event::Event()
:m_sType("")
,m_pTarget(NULL)
,m_pCurrentTarget(NULL)
{

}

Event::~Event()
{
    CC_SAFE_RELEASE(m_pTarget);
    CC_SAFE_RELEASE(m_pCurrentTarget);
}

bool Event::initEvent(const std::string &eventType, bool canBubble, bool cancelable)
{
    m_sType=eventType;
    m_bBubbles=canBubble;
    m_bCancelable=cancelable;
    
    m_nTimeStamp=0;

    m_bDispatchStopped=false;
    m_bNoDefault=false;

    return true;
}


NS_CC_YHLIB_END