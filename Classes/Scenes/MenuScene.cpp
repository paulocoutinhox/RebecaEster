#include "MenuScene.h"
#include "SimpleAudioEngine.h"

#include "../Stages/StageScene1.h"
#include "../Extras/Util.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    return MenuScene::create();
}

bool MenuScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto winSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // background sound
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("res/sounds/menu.mp3", true);
    
    // components
    auto backgroundImage = Sprite::create("res/scenes/menu/background.png");
    backgroundImage->setContentSize(Size(winSize.width, winSize.height));
    backgroundImage->setAnchorPoint(Point::ZERO);
    backgroundImage->setPosition(0.0f, 0.0f);
    this->addChild(backgroundImage, 0);
    
    auto logoImage = Sprite::create("res/hud/logo.png");
    Util::autoHeightForWidth(logoImage, ((winSize.width * 80) / 100));
    logoImage->setPosition(Vec2(visibleSize.width/2 + origin.x, winSize.height + logoImage->getContentSize().height));
    this->addChild(logoImage);
    
    auto startItem = MenuItemImage::create("res/hud/buttons/btStart.png", "res/hud/buttons/btStart.png", CC_CALLBACK_1(MenuScene::menuStartCallback, this));
    Util::autoHeightForWidth(startItem->getNormalImage(), ((winSize.width * 16) / 100));
    Util::autoHeightForWidth(startItem->getSelectedImage(), ((winSize.width * 16) / 100));
    startItem->setPosition(Vec2(visibleSize.width/2, -startItem->getNormalImage()->getContentSize().height));
    
    auto menu = Menu::create(startItem, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu);
    
    // animations
    auto moveLogoImage = MoveTo::create(0.5f, Vec2(visibleSize.width/2 + origin.x, visibleSize.height - 40));
    logoImage->runAction(moveLogoImage);
    
    auto moveStartItem = MoveTo::create(0.5f, Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y - 80));
    startItem->runAction(moveStartItem);

    return true;
}

void MenuScene::menuStartCallback(Ref* pSender)
{
    Scene *scene = StageScene1::createScene();
    Director::getInstance()->replaceScene(scene);
}

void MenuScene::onExit()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->end();
    Scene::onExit();
}
