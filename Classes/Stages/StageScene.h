#ifndef __STAGE_SCENE_H__
#define __STAGE_SCENE_H__

#include "cocos2d.h"
#include "../Extras/InfiniteParallaxNode.h"
#include "../Entities/Character.h"

#include "../SneakyInput/SneakyButton.h"
#include "../SneakyInput/SneakyButtonSkinnedBase.h"
#include "../SneakyInput/SneakyJoystick.h"
#include "../SneakyInput/SneakyJoystickSkinnedBase.h"

class StageScene : public cocos2d::Layer
{
private:
    Character *player;
    void toggleDebug();
    bool debugDraw;
    PhysicsWorld *physicsWorld;
    SneakyJoystick *leftJoystick;
    SneakyButton *action1Button;
    
public:
    static cocos2d::Scene* createScene();
    InfiniteParallaxNode *parallaxNode;
    
    virtual bool init();
    virtual void update(float delta);
    
    void createBackgroundWithAnimation();
    void createPlayer();
    void menuStartCallback(cocos2d::Ref* pSender);
    void setPhysicsWorld(PhysicsWorld *physicsWorld);
    
    CREATE_FUNC(StageScene);
};

#endif // __STAGE_SCENE_H__
