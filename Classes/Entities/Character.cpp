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
    
    float characterWidth = character->getSprite()->getContentSize().width;
    float characterHeight = character->getSprite()->getContentSize().height;
    
    // physics
    auto physicsBody = PhysicsBody::createBox(Size(characterWidth, characterHeight), PhysicsMaterial(0, 1, 0));
    physicsBody->setRotationEnable(false);
    character->setPhysicsBody(physicsBody);
    character->getSprite()->addComponent(character->getPhysicsBody());
    
    return character;
}

Sprite* Character::getSprite()
{
    return sprite;
}

Animate* Character::getIdleAnimate()
{
    return idleAnimate;
}

Animate* Character::getWalkAnimate()
{
    return walkAnimate;
}

Animate* Character::getRunAnimate()
{
    return runAnimate;
}

Animate* Character::getAttackAnimate()
{
    return attackAnimate;
}

Animate* Character::getJumpAnimate()
{
    return jumpAnimate;
}

Animate* Character::getDeadAnimate()
{
    return deadAnimate;
}

void Character::setSprite(Sprite *sprite)
{
    this->sprite = sprite;
}

void Character::setIdleAnimate(Animate *animate)
{
    idleAnimate = animate;
}

void Character::setWalkAnimate(Animate *animate)
{
    walkAnimate = animate;
}

void Character::setRunAnimate(Animate *animate)
{
    runAnimate = animate;
}

void Character::setAttackAnimate(Animate *animate)
{
    attackAnimate = animate;
}

void Character::setJumpAnimate(Animate *animate)
{
    jumpAnimate = animate;
}

void Character::setDeadAnimate(Animate *animate)
{
    deadAnimate = animate;
}

void Character::showIdleAnimation(const bool &repeat)
{
    if (repeat)
    {
        sprite->runAction(RepeatForever::create(idleAnimate));
    }
    else
    {
        sprite->runAction(idleAnimate);
    }
}

void Character::showWalkAnimation(const bool &repeat)
{
    if (repeat)
    {
        sprite->runAction(RepeatForever::create(walkAnimate));
    }
    else
    {
        sprite->runAction(walkAnimate);
    }
}

void Character::showRunAnimation(const bool &repeat)
{
    if (repeat)
    {
        sprite->runAction(RepeatForever::create(runAnimate));
    }
    else
    {
        sprite->runAction(runAnimate);
    }
}

void Character::showAttackAnimation(const bool &repeat)
{
    if (repeat)
    {
        sprite->runAction(RepeatForever::create(attackAnimate));
    }
    else
    {
        sprite->runAction(attackAnimate);
    }
}

void Character::showJumpAnimation(const bool &repeat)
{
    if (repeat)
    {
        sprite->runAction(RepeatForever::create(jumpAnimate));
    }
    else
    {
        sprite->runAction(jumpAnimate);
    }
}

void Character::showDeadAnimation(const bool &repeat)
{
    if (repeat)
    {
        sprite->runAction(RepeatForever::create(deadAnimate));
    }
    else
    {
        sprite->runAction(deadAnimate);
    }
}

PhysicsBody* Character::getPhysicsBody()
{
    return physicsBody;
}

void Character::setPhysicsBody(PhysicsBody *physicsBody)
{
    this->physicsBody = physicsBody;
}
