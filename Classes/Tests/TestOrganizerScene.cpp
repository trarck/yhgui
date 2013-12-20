#include "TestOrganizerScene.h"
#include "yhgui/yhgui.h"
#include "Event/EventHandle.h"
#include "yhgui/interactive/DocumentTreeOrganizer.h"
#include "yhgui/interactive/IndependentDocumentTreeOrganizer.h"

#include "../TestMainScene.h"
#include "Box.h"

USING_NS_CC;
USING_NS_CC_YHGUI;


CCScene* TestOrganizer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    TestOrganizer *layer = TestOrganizer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool TestOrganizer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCMenuItemLabel* pTestPerformance=CCMenuItemLabel::create(CCLabelTTF::create("test performens", "Arial", 24), this,menu_selector(TestOrganizer::testPerformanceCallback));
    pTestPerformance->setPosition(ccp(110,20));
    
    CCMenuItemLabel* pTestZOrder=CCMenuItemLabel::create(CCLabelTTF::create("test zorder", "Arial", 24), this,menu_selector(TestOrganizer::testZOrderCallback));
    pTestZOrder->setPosition(ccp(300,20));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pTestPerformance,pTestZOrder,NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    return true;
}

void TestOrganizer::testPerformanceCallback(CCObject* pSender)
{
//    DocumentTreeOrganizer* treeOrganizer=new DocumentTreeOrganizer();
    
    IndependentDocumentTreeOrganizer* treeOrganizer=new IndependentDocumentTreeOrganizer();
    
    treeOrganizer->init();
    treeOrganizer->registerWithTouchDispatcher();
    
    Component* root=Component::create();
    addChild(root);
    
    treeOrganizer->setDocument(root);
    
    CCSize gridSize=CCSizeMake(100, 100);
    CCSize margin=CCSizeMake(20, 20);
    
    ccColor4B colors[4]={
        ccc4(255, 0, 0, 255),
        ccc4(0, 255, 0, 255),
        ccc4(0, 0, 255, 255),
        ccc4(255, 255, 0, 255)
    };
    
    //    ccDrawColor4B(colors[i].r,colors[i].g,colors[i].b,colors[i].a);
    
    for (int i=0; i<4; i++) {
        
        Box* child1=Box::create();
        child1->setContentSize(CCSizeMake(gridSize.width+margin.width, (gridSize.height+margin.height)*4));
        child1->setPosition(i*(gridSize.width+margin.width)+60,60);
        child1->color=ccc4(128, 128, 128, 255);
        child1->x=i;
        child1->y=0;
        
        root->addChild(child1);
        
        for (int j=0; j<400; j++) {
            Box* child11=Box::create();
            child11->setContentSize(gridSize);
            child11->setPosition(ccp(margin.width/2, margin.height/2 +j*20));
            child11->color=colors[i];
            child11->x=i+1;
            child11->y=j+1;
            
            child1->addChild(child11);
        }
    }
}

void TestOrganizer::testZOrderCallback(CCObject* pSender)
{
    DocumentTreeOrganizer* treeOrganizer=new DocumentTreeOrganizer();
    treeOrganizer->init();
    treeOrganizer->registerWithTouchDispatcher();
    
    Component* root=Component::create();
    addChild(root);
    
    treeOrganizer->setDocument(root);
    
    
    SolidBox* child1=SolidBox::create();
    
    child1->setContentSize(CCSizeMake(400,400));
    child1->setPosition(ccp(10, 10));
    child1->color=ccc4(255, 0, 0, 150);
    child1->x=0;
    child1->y=0;
    
    root->addChild(child1);
    
    
    SolidBox* child2=SolidBox::create();
    
    child2->setContentSize(CCSizeMake(400,400));
    child2->setPosition(ccp(200, 200));
    child2->color=ccc4(0, 0, 128, 150);
    child2->x=1;
    child2->y=0;
    
    root->addChild(child2);
    
    
    SolidBox* child3=SolidBox::create();
    
    child3->setContentSize(CCSizeMake(400,400));
    child3->setPosition(ccp(100, 200));
    child3->color=ccc4(0, 128, 0, 150);
    child3->x=2;
    child3->y=0;
    
    root->addChild(child3);
}