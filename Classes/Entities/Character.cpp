#include "Character.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Character* Character::create(const std::string &type)
{
    auto *character = new Character();
    
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("res/characters/" + type + "/" + type + ".plist", "res/characters/" + type + "/" + type + ".png");
    
    AnimationCache *animationCache = AnimationCache::getInstance();
    animationCache->addAnimationsWithFile("res/characters/" + type + "/animations.plist");
    
    {
        // idle
        Animation *animation = animationCache->getAnimation("idle");
        character->setIdleAnimate(Animate::create(animation));
    }
    
    {
        // walk
        Animation *animation = animationCache->getAnimation("walk");
        character->setWalkAnimate(Animate::create(animation));
    }
    
    {
        // run
        Animation *animation = animationCache->getAnimation("run");
        character->setRunAnimate(Animate::create(animation));
    }
    
    {
        // attack
        Animation *animation = animationCache->getAnimation("attack");
        character->setAttackAnimate(Animate::create(animation));
    }
    
    {
        // jump
        Animation *animation = animationCache->getAnimation("jump");
        character->setJumpAnimate(Animate::create(animation));
    }
    
    {
        // dead
        Animation *animation = animationCache->getAnimation("dead");
        character->setDeadAnimate(Animate::create(animation));
    }
    
    character->setSprite(Sprite::createWithSpriteFrameName("characters/" + type + "/idle_1.png"));
    character->showIdleAnimation(true);
    //character->showAttackAnimation(true);
    //character->showWalkAnimation(true);
    //character->showRunAnimation(true);
    //character->showJumpAnimation(true);
    
    //character->setState(1);
    character->setDirection(2);
    
    // physics
    auto physicsBody = PhysicsBody::createBox(Size(60, 90), PhysicsMaterial(1, 0, 1));
    physicsBody->setRotationEnable(false);
    character->setPhysicsBody(physicsBody);
    character->getSprite()->addComponent(character->getPhysicsBody());
    
    return character;
}

Sprite* Character::getSprite()
{
    return sprite->get();
}

Animate* Character::getIdleAnimate()
{
    return idleAnimate->get();
}

Animate* Character::getWalkAnimate()
{
    return walkAnimate->get();
}

Animate* Character::getRunAnimate()
{
    return runAnimate->get();
}

Animate* Character::getAttackAnimate()
{
    return attackAnimate->get();
}

Animate* Character::getJumpAnimate()
{
    return jumpAnimate->get();
}

Animate* Character::getDeadAnimate()
{
    return deadAnimate->get();
}

void Character::setSprite(Sprite *sprite)
{
    this->sprite = new RefPtr<Sprite>(sprite);
}

void Character::setIdleAnimate(Animate *animate)
{
    idleAnimate = new RefPtr<Animate>(animate);
}

void Character::setWalkAnimate(Animate *animate)
{
    walkAnimate = new RefPtr<Animate>(animate);
}

void Character::setRunAnimate(Animate *animate)
{
    runAnimate = new RefPtr<Animate>(animate);
}

void Character::setAttackAnimate(Animate *animate)
{
    attackAnimate = new RefPtr<Animate>(animate);
}

void Character::setJumpAnimate(Animate *animate)
{
    jumpAnimate = new RefPtr<Animate>(animate);
}

void Character::setDeadAnimate(Animate *animate)
{
    deadAnimate = new RefPtr<Animate>(animate);
}

void Character::showIdleAnimation(const bool &repeat)
{
    if (state == 1)
    {
        return;
    }
    
    sprite->get()->stopAllActions();
    
    if (repeat)
    {
        sprite->get()->runAction(RepeatForever::create(idleAnimate->get()));
    }
    else
    {
        sprite->get()->runAction(idleAnimate->get());
    }
    
    state = 1;
}

void Character::showWalkAnimation(const bool &repeat)
{
    if (state == 2)
    {
        return;
    }
    
    sprite->get()->stopAllActions();
    
    if (repeat)
    {
        sprite->get()->runAction(RepeatForever::create(walkAnimate->get()));
    }
    else
    {
        sprite->get()->runAction(walkAnimate->get());
    }
    
    state = 2;
}

void Character::showRunAnimation(const bool &repeat)
{
    if (state == 3)
    {
        return;
    }
    
    sprite->get()->stopAllActions();
    
    if (repeat)
    {
        sprite->get()->runAction(RepeatForever::create(runAnimate->get()));
    }
    else
    {
        sprite->get()->runAction(runAnimate->get());
    }
    
    state = 3;
}

void Character::showAttackAnimation(const bool &repeat)
{
    if (state == 4)
    {
        return;
    }
    
    sprite->get()->stopAllActions();
    
    if (repeat)
    {
        sprite->get()->runAction(RepeatForever::create(attackAnimate->get()));
    }
    else
    {
        sprite->get()->runAction(attackAnimate->get());
    }
    
    state = 4;
}

void Character::showJumpAnimation(const bool &repeat)
{
    if (state == 5)
    {
        return;
    }
    
    sprite->get()->stopAllActions();
    
    if (repeat)
    {
        sprite->get()->runAction(RepeatForever::create(jumpAnimate->get()));
    }
    else
    {
        sprite->get()->runAction(jumpAnimate->get());
    }
    
    state = 5;
}

void Character::showDeadAnimation(const bool &repeat)
{
    if (state == 6)
    {
        return;
    }
    
    sprite->get()->stopAllActions();
    
    if (repeat)
    {
        sprite->get()->runAction(RepeatForever::create(deadAnimate->get()));
    }
    else
    {
        sprite->get()->runAction(deadAnimate->get());
    }
    
    state = 6;
}

PhysicsBody* Character::getPhysicsBody()
{
    return physicsBody->get();
}

void Character::setPhysicsBody(PhysicsBody *physicsBody)
{
    this->physicsBody = new RefPtr<PhysicsBody>(physicsBody);
}

void Character::updateVelocity(Point velocity)
{
    move(velocity);
}

void Character::move(Point velocity)
{
    if (velocity.x > 0)
    {
        // move right
        showRunAnimation(true);
        changeDirection(2);
        getPhysicsBody()->applyImpulse(Vec2(0.25, 0.0f));
    }
    else if (velocity.x < 0)
    {
        // move left
        showRunAnimation(true);
        changeDirection(1);
        
        getPhysicsBody()->applyImpulse(Vec2(-0.25, 0.0f));
    }
    else
    {
        // not moving
        showIdleAnimation(true);
    }
}

void Character::actionButtonPressed(int button)
{
    cocos2d::log("[Character : actionButtonPressed]");
    
    if (button == 1)
    {
        getPhysicsBody()->applyImpulse(Vec2(0.0f, 100.0f));
        showJumpAnimation(false);
    }
}

void Character::changeDirection(int direction)
{
    if (this->direction != direction && direction == 1)
    {
        sprite->get()->setFlippedX(true);
        this->direction = direction;
        
        if (state == 2 || state == 3)
        {
            stopMoving();
        }
    }
    else if (this->direction != direction && direction == 2)
    {
        sprite->get()->setFlippedX(false);
        this->direction = direction;
     
        if (state == 2 || state == 3)
        {
            stopMoving();
        }
    }
}

void Character::stopMoving()
{
    if (state == 2)
    {
        getPhysicsBody()->setVelocity(Vec2(0, 0));
    }
}

void Character::setState(int state)
{
    this->state = state;
}

void Character::setDirection(int direction)
{
    this->direction = direction;
}
