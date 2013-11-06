#include "HelloWorldScene.h"
#include "yhgui/yhgui.h"

USING_NS_CC;
USING_NS_CC_YHGUI;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    CCLabelTTF* pLabel = CCLabelTTF::create("test", "Arial", 24);
    
    CCMenuItemLabel* pTest=CCMenuItemLabel::create(pLabel, this,menu_selector(HelloWorld::testCallback));
    pTest->setPosition(ccp(200,30));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem,pTest, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    return true;
}

void HelloWorld::testCallback(CCObject* pSender)
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

void HelloWorld::menuCloseCallback(CCObject* pSender)
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
