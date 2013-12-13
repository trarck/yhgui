#include "TestButtonScene.h"
#include "yhgui/yhgui.h"
#include "yhgui/interactive/DocumentTreeOrganizer.h"
#include "Event/EventHandle.h"
#include "../TestMainScene.h"

USING_NS_CC;
USING_NS_CC_YHGUI;

CCScene* TestButton::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    TestButton *layer = TestButton::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TestButton::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    
    DocumentTreeOrganizer* treeOrganizer=new DocumentTreeOrganizer();
    treeOrganizer->init();
    treeOrganizer->registerWithTouchDispatcher();
    
    Component* document=Component::create();
    addChild(document);
    
    treeOrganizer->setDocument(document);
    
    
    NormalButton* button=new NormalButton();
    button->init();
    button->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
    
    CCLabelTTF* labelTTF=CCLabelTTF::create("click me", "Arial", 24);
    
    button->setLabel(labelTTF);
    
    ccColor3B pressColor=ccc3(255, 0, 0);
    button->setStateLabelColor(NormalButton::kPressed, pressColor);
    
    button->addEventListener("touchDown", this, YH_EVENT_SELECTOR(TestButton::onTouchDown));
    button->addEventListener("touchMove", this, YH_EVENT_SELECTOR(TestButton::onTouchMove));
    button->addEventListener("touchMoveEndter", this, YH_EVENT_SELECTOR(TestButton::onTouchMoveEnter));
    button->addEventListener("touchMoveExit", this, YH_EVENT_SELECTOR(TestButton::onTouchMoveExit));
    button->addEventListener("touchUpInside", this, YH_EVENT_SELECTOR(TestButton::onTouchUpInside));
    button->addEventListener("touchUpOutside", this, YH_EVENT_SELECTOR(TestButton::onTouchUpOutside));
    
    button->changeState(NormalButton::kNormal);
    
    document->addChild(button);
    button->release();
    
    NormalButton* backBtn=new NormalButton();
    backBtn->init();
    backBtn->setPosition(ccp(visibleSize.width/2,visibleSize.height/2-100));
    
    CCLabelTTF* backLabel=CCLabelTTF::create("back", "Arial", 24);
    
    backBtn->setLabel(backLabel);
    
    backBtn->addEventListener("touchUpInside", this, YH_EVENT_SELECTOR(TestButton::onBack));
    backBtn->changeState(NormalButton::kNormal);
    document->addChild(backBtn);
    backBtn->release();
    
//    CCLOG("button:%d",button->retainCount());
    
    return true;
}

void TestButton::onTouchDown(cocos2d::yhlib::Event* event)
{
    CCLOG("onTouchDown");
}

void TestButton::onTouchMove(cocos2d::yhlib::Event* event)
{
    CCLOG("onTouchMove,is inside:%d",static_cast<CCBool*>(event->getData())->getValue());
}

void TestButton::onTouchMoveEnter(cocos2d::yhlib::Event* event)
{
     CCLOG("onTouchMoveEnter");
}

void TestButton::onTouchMoveExit(cocos2d::yhlib::Event* event)
{
    CCLOG("onTouchMoveExit");
}

void TestButton::onTouchUpInside(cocos2d::yhlib::Event* event)
{
    CCLOG("onTouchUpInside");
}

void TestButton::onTouchUpOutside(cocos2d::yhlib::Event* event)
{
    CCLOG("onTouchUpOutside");
}

void TestButton::onBack(cocos2d::yhlib::Event *event)
{
    CCDirector::sharedDirector()->replaceScene(TestMain::scene());
}