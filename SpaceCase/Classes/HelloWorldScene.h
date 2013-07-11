#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CCParallaxNodeExtras.h"

using namespace cocos2d;

class HelloWorld : public CCLayer
{
    
private:
    CCSpriteBatchNode* _batchNode;
    CCSprite* _ship;
    CCParallaxNodeExtras *_backgroundNode;
    CCSprite *_spacedust1;
    CCSprite *_spacedust2;
    CCSprite *_planetsunrise;
    CCSprite *_galaxy;
    CCSprite *_spacialanomaly;
    CCSprite *_spacialanomaly2;
    
    float _shipPointsPerSecY;
    
    CCArray* _asteroids;
    int _nextAsteroid;
    float _nextAsteroidSpawn;
    
    CCArray* _shipLasers;
    int _nextShipLaser;
    
    int _lives;
    
    // schedule updates
    void update(float dt);
    
    
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    
    virtual void didAccelerate(CCAcceleration* pAccelerationValue);

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HelloWorld);
    
    float randomValueBetween(float low,float high);
    void setInvisible(CCNode * node);
    float getTimeTick();
    
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
};

#endif // __HELLOWORLD_SCENE_H__
