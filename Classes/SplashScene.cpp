#include "SplashScene.h"
#include "MainMenuScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    this->scheduleOnce(schedule_selector(SplashScene::goToMainMenuScene), DISPLAY_TIME_SPLASH_SCENE);
    auto backgroundSprite = Sprite::create("Splash Screen.png");

    backgroundSprite->setPosition(CENTER_POSITION);
    
    this->addChild(backgroundSprite);
    
    return true;
}

void SplashScene::goToMainMenuScene(float dt){
    auto scene = MainMenuScene::createScene();
    auto transitionScene = TransitionFade::create(TRANSITION_TIME, scene);
    Director::getInstance()->replaceScene(transitionScene);
}

