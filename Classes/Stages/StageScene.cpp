#include "StageScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* StageScene::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0.0f, -10.0f));
    
    auto stageLayer = StageScene::create();
    //stageLayer->setPhysicWorld(scene->getPhysicsWorld());
    scene->addChild(stageLayer);
    stageLayer->toggleDebug();
    
    return scene;
}

bool StageScene::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    createBackgroundWithAnimation();
    createPlayer();
    
    auto label = Label::createWithTTF("Points: 0", "fonts/Marker Felt.ttf", 20);
    label->setPosition(Vec2(visibleSize.width - label->getContentSize().width - 10, origin.y + visibleSize.height - label->getContentSize().height));
    label->setAlignment(TextHAlignment::RIGHT);
    label->setAnchorPoint(Vec2(0.0f, 1.0f));
    this->addChild(label);
    
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    edgeBody->setContactTestBitmask(0xFFFFFFFF);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    this->addChild(edgeNode);
    
    auto bottomBody = PhysicsBody::createBox(Size(visibleSize.width, 20));
    bottomBody->setDynamic(false);
    bottomBody->setContactTestBitmask(0xFFFFFFFF);
    auto bottomNode = Node::create();
    bottomNode->setPosition(Point(visibleSize.width/2, 50));
    bottomNode->setPhysicsBody(bottomBody);
    this->addChild(bottomNode);
    
    this->scheduleUpdate();
    
    return true;
}

void StageScene::createPlayer()
{
    auto winSize = Director::getInstance()->getWinSize();
    
    player = Character::create("wizard");
    player->showRunAnimation(true);
    player->getSprite()->setPosition(Vec2(winSize.width/2, winSize.height/2));
    player->getSprite()->setScale(0.5f);
    
    this->addChild(player->getSprite());
}

void StageScene::createBackgroundWithAnimation()
{
    auto origin = Director::getInstance()->getVisibleOrigin();
    auto winSize = Director::getInstance()->getWinSize();
    
    auto backGround = Sprite::create("res/stages/stage1/background.png", Rect(0.0f, 0.0f, winSize.width, winSize.height));
    auto backGround2 = Sprite::create("res/stages/stage1/background.png", Rect(0.0f, 0.0f, winSize.width, winSize.height));
    
    parallaxNode = InfiniteParallaxNode::create();
    backGround->setAnchorPoint(Point::ZERO);
    backGround2->setAnchorPoint(Point::ZERO);
    
    parallaxNode->addChild(backGround, 0, Vec2(1.0f, 0.0f), Vec2(0.0f, 0.0f));
    parallaxNode->addChild(backGround2, 0, Vec2(1.0f, 0.0f), Vec2(winSize.width, 0.0f));
    
    addChild(parallaxNode);
}

void StageScene::update(float delta)
{
    Layer::update(delta);
    
    parallaxNode->setPosition(parallaxNode->getPosition() + Vec2(-2.0f, 0.0f));
    parallaxNode->updatePosition(Vec2(-2.0f, 0.0f));
}

void StageScene::toggleDebug()
{
    debugDraw = !debugDraw;
    getScene()->getPhysicsWorld()->setDebugDrawMask(debugDraw ? PhysicsWorld::DEBUGDRAW_ALL : PhysicsWorld::DEBUGDRAW_NONE);
}
