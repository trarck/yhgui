#ifndef COCOS_YHGUI_CONTROL_BUTTON_H_
#define COCOS_YHGUI_CONTROL_BUTTON_H_

#include "Control.h"

NS_CC_YHGUI_BEGIN
	
class Button:public Control
{
public:
    
    Button();
    
    ~Button();
    
    bool init();

    void setStateComponent(State state,CCNode* component);
    
    inline void setState(State state)
    {
        m_state = state;
    }
    
    inline State getState()
    {
        return m_state;
    }
    
protected:

    CCDictionary* m_states;
  
    State m_state;
};


NS_CC_YHGUI_END

#endif // COCOS_YHGUI_CONTROL_BUTTON_H_
