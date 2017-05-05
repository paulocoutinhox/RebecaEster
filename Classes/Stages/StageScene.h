#ifndef __STAGE_SCENE_H__
#define __STAGE_SCENE_H__

#include "cocos2d.h"
#include "../Extras/InfiniteParallaxNode.h"
#include "../Entities/Character.h"

class StageScene : public cocos2d::Layer
{
private:
    Character *player;
    void toggleDebug();
    bool debugDraw;
    
public:
    static cocos2d::Scene* createScene();
    InfiniteParallaxNode *parallaxNode;
    
    virtual bool init();
    virtual void update(float delta);
    
    void createBackgroundWithAnimation();
    void createPlayer();
    void menuStartCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(StageScene);
};

#endif // __STAGE_SCENE_H__
