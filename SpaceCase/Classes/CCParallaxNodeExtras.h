#ifndef SpaceCase_CCParallaxNodeExtras_h

#define SpaceCase_CCParallaxNodeExtras_h

#include "cocos2d.h"

using namespace cocos2d;

class CCParallaxNodeExtras : public CCParallaxNode {

public :
    // Need to provide a constructor
    CCParallaxNodeExtras();
    
    // just to avoid ugly later cast and also for safety
    static CCParallaxNodeExtras * node();
    
    // Facility method (it’s expected to have it soon in COCOS2DX)
    void incrementOffset(CCPoint offset, CCNode* node);
};

#endif