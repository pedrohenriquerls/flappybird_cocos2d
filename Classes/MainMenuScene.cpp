#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto backgroundSprite = Sprite::create("Background.png");
    backgroundSprite->setPosition(CENTER_POSITION);
    this->addChild(backgroundSprite);
    
    Vector<MenuItem*> menuItems;
    auto playCallback = CC_CALLBACK_1(MainMenuScene::goToGameScene, this);
    auto playBtn = MenuItemImage::create("Play Button.png", "Play Button Clicked.png", playCallback);
    
    menuItems.pushBack(playBtn);
    
    auto menu = Menu::createWithArray(menuItems);
    menu->setPosition(CENTER_POSITION);
    this->addChild(menu);

    return true;
}

void MainMenuScene::goToGameScene(cocos2d::Ref *sender){
    auto scene = GameScene::createScene();
    auto transitionScene = TransitionFade::create(TRANSITION_TIME, scene);
    Director::getInstance()->replaceScene(transitionScene);
}


