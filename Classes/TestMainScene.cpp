#include "TestMainScene.h"
#include "yhgui/yhgui.h"
#include "Tests/TestButtonScene.h"
#include "Tests/TestOrganizerScene.h"
#include "Tests/TestListOrganizerScene.h"

USING_NS_CC;
USING_NS_CC_YHGUI;

CCScene* TestMain::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    TestMain *layer = TestMain::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TestMain::init()
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
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(TestMain::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    CCLabelTTF* pLabel = CCLabelTTF::create("test", "Arial", 24);
    
    CCMenuItemLabel* pTest=CCMenuItemLabel::create(pLabel, this,menu_selector(TestMain::testCallback));
    pTest->setPosition(ccp(200,30));
    
    CCLabelTTF* pTestButtonLabel = CCLabelTTF::create("test button", "Arial", 24);
    
    CCMenuItemLabel* pTestButtonItem=CCMenuItemLabel::create(pTestButtonLabel, this,menu_selector(TestMain::testButtonCallback));
    pTestButtonItem->setPosition(ccp(200,70));

    
    CCMenuItemLabel* pOrganizerButtonItem=CCMenuItemLabel::create(CCLabelTTF::create("test organizer", "Arial", 24), this,menu_selector(TestMain::testOrganizerCallback));
    pOrganizerButtonItem->setPosition(ccp(200,110));
    
    CCMenuItemLabel* pTestListOrganizerButtonItem=CCMenuItemLabel::create(CCLabelTTF::create("test list organizer", "Arial", 24), this,menu_selector(TestMain::testListOrganizerCallback));
    pTestListOrganizerButtonItem->setPosition(ccp(200,150));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem,pTest,pTestButtonItem,pOrganizerButtonItem,pTestListOrganizerButtonItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    return true;
}

void TestMain::testButtonCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(TestButton::scene());
}

void TestMain::testOrganizerCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(TestOrganizer::scene());
}

void TestMain::testListOrganizerCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene(TestListOrganizer::scene());
}

void TestMain::testCallback(CCObject* pSender)
{
    Container* container=Container::create();
    
    Component* c1=Component::create();
    c1->setName("c1");
    container->addChild(c1);
    
    Component* c2=Component::create();
    c2->setName("c2");
    container->addChild(c2);
    
    Container* c5=Container::create();
    c5->setName("c5");
    container->addChild(c5);
    
    Component* c11=Component::create();
    c11->setName("c11");
    c5->addChild(c11);
    
    Component* c12=Component::create();
    c12->setName("c2");
    c5->addChild(c12);
    
    Component* c3=Component::create();
    c3->setName("c3");
    container->addChild(c3);
    
    Component* c4=Component::create();
    c4->setName("c4");
    container->addChild(c4);
    
    CCNode* cc1=container->getChildByName("c1");
    
    CCArray* cc2=container->getChildrenByName("c2");
    
    CCNode* cc11=container->getDescendantByName("c11");
    
    CCArray* cc12=container->getDescendantsByName("c2");
    
    addChild(container);
    
    printf("%d,%d,%d,%d",cc1,cc2->count(),cc11,cc12->count());
}

void TestMain::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
