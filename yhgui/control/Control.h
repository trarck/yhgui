#ifndef COCOS_YHGUI_CONTROL_CONTROL_H_
#define COCOS_YHGUI_CONTROL_CONTROL_H_

#include "../Component.h"

NS_CC_YHGUI_BEGIN
	
class Control:public Component
{
public:
    
    Control();
    
    ~Control();

	void setState(State state)
	{
		m_state = state;
	}

	int getState()
	{
		return m_state;
	}

protected:
    State m_state;
    
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_CONTROL_CONTROL_H_
