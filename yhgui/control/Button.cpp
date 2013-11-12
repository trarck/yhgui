#include "Button.h"

NS_CC_YHGUI_BEGIN
	
Button::Button()
:m_states(NULL)
{
	
}
	
Button::~Button()
{
	CC_SAFE_RELEASE_NULL(m_states);
}

bool Button::init()
{
    if (Control::init()) {
        
        m_states=new CCDictionary();
        
    }
    return false;
}

NS_CC_YHGUI_END