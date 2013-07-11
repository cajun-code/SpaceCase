#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

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

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    _batchNode = CCSpriteBatchNode::create("Sprites.pvr.ccz");
    this->addChild(_batchNode);
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Sprites.plist");
    _ship = CCSprite::createWithSpriteFrameName("SpaceFlier_sm_1.png");
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    _ship->setPosition(ccp(winSize.width*0.1, winSize.height*0.5));
    _batchNode->addChild(_ship,1);
    
    // 1) Create the CCParallaxNode
    _backgroundNode = CCParallaxNode::create();
    this->addChild(_backgroundNode,-1);
    
    // 2) Create the sprites will be added to the CCParallaxNode
    _spacedust1 = CCSprite::create("bg_front_spacedust.png");
    _spacedust2 = CCSprite::create("bg_front_spacedust.png");
    _planetsunrise = CCSprite::create("bg_planetsunrise.png");
    _galaxy = CCSprite::create("bg_galaxy.png");
    _spacialanomaly = CCSprite::create("bg_spacialanomaly.png");
    _spacialanomaly2 = CCSprite::create("bg_spacialanomaly2.png");
    
    // 3) Determine relative movement speeds for space dust and background
    CCPoint dustSpeed = ccp(0.1,0.1);
    CCPoint bgSpeed = ccp(0.05,0.05);
    
    // 4) Add children to CCParallaxNode
    _backgroundNode->addChild(_spacedust1,0, dustSpeed, ccp(0,winSize.height/2));
    _backgroundNode->addChild(_spacedust2,0, dustSpeed, ccp( _spacedust1->getContentSize().width,winSize.height/2));
    _backgroundNode->addChild(_galaxy,-1, bgSpeed, ccp(0, winSize.height*0.7));
    _backgroundNode->addChild(_planetsunrise,-1, bgSpeed, ccp(600, winSize.height*0));
    _backgroundNode->addChild(_spacialanomaly,-1, bgSpeed, ccp(900, winSize.height*0.3));
    _backgroundNode->addChild(_spacialanomaly2,-1, bgSpeed, ccp(1500, winSize.height*0.9));
    
    this -> scheduleUpdate();
    return true;
}

void HelloWorld::update(float dt){
    CCPoint backgroundScrollVert = ccp(-1000, 0);
    _backgroundNode -> setPosition(ccpAdd(_backgroundNode -> getPosition(), ccpMult(backgroundScrollVert, dt)));
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
