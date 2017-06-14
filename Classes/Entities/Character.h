#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"
USING_NS_CC;

class Character
{
public:
    static Character* create(const std::string &type);
    
    Sprite* getSprite();
    Animate* getIdleAnimate();
    Animate* getWalkAnimate();
    Animate* getRunAnimate();
    Animate* getAttackAnimate();
    Animate* getJumpAnimate();
    Animate* getDeadAnimate();
    PhysicsBody* getPhysicsBody();
    
    void setSprite(Sprite *sprite);
    void setIdleAnimate(Animate *animate);
    void setWalkAnimate(Animate *animate);
    void setRunAnimate(Animate *animate);
    void setAttackAnimate(Animate *animate);
    void setJumpAnimate(Animate *animate);
    void setDeadAnimate(Animate *animate);
    void setPhysicsBody(PhysicsBody *physicsBody);
    void setState(int state);
    void setDirection(int direction);
    
    void showIdleAnimation(const bool &repeat);
    void showWalkAnimation(const bool &repeat);
    void showRunAnimation(const bool &repeat);
    void showAttackAnimation(const bool &repeat);
    void showJumpAnimation(const bool &repeat);
    void showDeadAnimation(const bool &repeat);
    
    void updateVelocity(Point velocity);
    void move(Point velocity);
    void actionButtonPressed(int button);
    void changeDirection(int direction);
    void stopMoving();
    
private:
    RefPtr<Animate> *idleAnimate;
    RefPtr<Animate> *walkAnimate;
    RefPtr<Animate> *runAnimate;
    RefPtr<Animate> *attackAnimate;
    RefPtr<Animate> *jumpAnimate;
    RefPtr<Animate> *deadAnimate;
    
    RefPtr<Sprite> *sprite;
    RefPtr<PhysicsBody> *physicsBody;
    
    int direction;
    int state;
    
};

#endif // __CHARACTER_H__
