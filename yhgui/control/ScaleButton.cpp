#include "ScaleButton.h"
#include "../utils/Utils.h"

USING_NS_CC_EXT;

NS_CC_YHGUI_BEGIN

static const int kLabelZOrder=10;
static const int kBackgroundZOrder=1;
	
ScaleButton::ScaleButton()
:m_currentBackground(NULL)
{
	
}
	
ScaleButton::~ScaleButton()
{

}

/**
 * 文字不会超过背景,所以button的大小是背景的大小
 */
void ScaleButton::updateStateComponent(State newState)
{    
    if (!m_stateDirty) {
        return;
    }
    m_stateDirty=false;
    
    if (m_label) {
        //set label color
        if (m_stateColors.find(newState)!=m_stateColors.end()) {
            switch (m_labelType) {
                case kLabelTypeTTF:{
                    
                    CCLabelTTF* labelTTF=static_cast<CCLabelTTF*>(m_label);
                    
                    labelTTF->setColor(m_stateColors[newState]);
                    
                    break;
                }
                case kLabelTypeBMFont:{
                    CCLabelBMFont* labelBMFont=static_cast<CCLabelBMFont*>(m_label);
                    labelBMFont->setColor(m_stateColors[newState]);
                    break;
                }
                default:
                    break;
            }
        }
    }
    
    //set background
    
    CCScale9Sprite* newBackground=static_cast<CCScale9Sprite*>(m_states->objectForKey(newState));
    
    //no new component do nothing
    if (newBackground && newBackground!=m_currentBackground) {
        
        
        if (m_currentBackground){
            //remove current state component
            m_currentBackground->removeFromParentAndCleanup(false);
        }
        
        //add new state component
        this->addChild(newBackground,kBackgroundZOrder);
        
        m_currentBackground=newBackground;
    }
    
    CCSize contentSize;
    
    if (m_preferredSize.width>0 || m_preferredSize.height>0) {
        //fixed size
        contentSize=m_preferredSize;
    }else{
        
        if (newBackground) {
            contentSize=newBackground->boundingBox().size;
        }else if (m_label){
            contentSize=m_label->boundingBox().size;
        }
        
        //auto content size
        setContentSize(contentSize);
    }

    //fix label and background position to center
    if (m_label) {
        //修正之前的位置
        m_label->setPosition(ccp(contentSize.width/2+m_labelOffset.x, contentSize.height/2+m_labelOffset.y));
    }
    
    if (newBackground) {
        newBackground->setPosition(ccp(contentSize.width/2, contentSize.height/2));
    }
}

/**
 * 设置状态对应的background
 */
void ScaleButton::setStateBackgroundScale9(State state,extension::CCScale9Sprite* background)
{
    m_states->setObject(background, state);
    updateCurrentStateComponent(state);
}

/**
 * 设置状态对应的background
 */
void ScaleButton::setStateBackgroundScale9(State state,const std::string& imageFile)
{
    CCScale9Sprite* background=CCScale9Sprite::create(imageFile.c_str());
    
    setStateBackground(state, background);
}

NS_CC_YHGUI_END