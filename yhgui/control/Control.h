#ifndef COCOS_YHGUI_CONTROL_CONTROL_H_
#define COCOS_YHGUI_CONTROL_CONTROL_H_

#include "../Component.h"

NS_CC_YHGUI_BEGIN
	
class Control:public Component
{
public:
    
    Control();
    
    ~Control();
    
    virtual void changeState(State newState);
    
	void setState(State state)
	{
		m_state = state;
	}

	int getState()
	{
		return m_state;
	}

public:
    
    enum{
        kControlEventTouchDown           = 1 << 0,    // A touch-down event in the control.
        kControlEventTouchMoveInside     = 1 << 1,    // An event where a finger is dragged inside the bounds of the control.
        kControlEventTouchMoveOutside    = 1 << 2,    // An event where a finger is dragged just outside the bounds of the control.
        kControlEventTouchMoveEnter      = 1 << 3,    // An event where a finger is dragged into the bounds of the control.
        kControlEventTouchMoveExit       = 1 << 4,    // An event where a finger is dragged from within a control to outside its bounds.
        kControlEventTouchUpInside       = 1 << 5,    // A touch-up event in the control where the finger is inside the bounds of the control.
        kControlEventTouchUpOutside      = 1 << 6,    // A touch-up event in the control where the finger is outside the bounds of the control.
        kControlEventTouchCancel         = 1 << 7,    // A system event canceling the current touches for the control.
        kControlEventValueChanged        = 1 << 8      // A touch dragging or otherwise manipulating a control, causing it to emit a series of different values.
    };
    
    typedef unsigned int ControlEvent;
    
protected:
    
    //状态
    State m_state;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_CONTROL_CONTROL_H_
