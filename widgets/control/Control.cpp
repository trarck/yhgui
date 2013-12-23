#include "Control.h"

NS_CC_YHGUI_BEGIN
	
Control::Control()
:m_state(kIdle)
{
	
}
	
Control::~Control()
{
	
}

void Control::changeState(State newState)
{
    setState(newState);
}

NS_CC_YHGUI_END