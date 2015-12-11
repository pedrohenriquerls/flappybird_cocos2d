#include "GameScene.h"
#include "Definitions.h"
#include "Bird.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    auto scenePhysicsWorld = scene->getPhysicsWorld();
    if(DEBUG_MODE)
        scenePhysicsWorld->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto layer = GameScene::create();
    layer->setPhysicsWorld(scenePhysicsWorld);

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto director = Director::getInstance();
    Size visibleSize = director->getVisibleSize();
    Vec2 origin = director->getVisibleOrigin();
    new Bird(visibleSize, origin, this);
    pipe = new Pipe(visibleSize, origin);
    
    auto backgroundSprite = Sprite::create("Background.png");
    backgroundSprite->setPosition(CENTER_POSITION);
    addChild(backgroundSprite);
    
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(CENTER_POSITION);
    edgeNode->setPhysicsBody(edgeBody);
    addChild(edgeNode);
    
    this->schedule(schedule_selector(GameScene::spawnPipe), 0.005 * visibleSize.width);
    
    auto eventListener = EventListenerPhysicsContact::create();
    eventListener->onContactBegin = CC_CALLBACK_1(GameScene::onBirdCollidesWithPipe, this);
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventListener, this);

    return true;
}

bool GameScene::onBirdCollidesWithPipe(cocos2d::PhysicsContact &contact){
    PhysicsBody *a = contact.getShapeA( )->getBody();
    PhysicsBody *b = contact.getShapeB( )->getBody();
    
    if (checkCollision(a, b) || checkCollision(b, a))
        CCLOG("collision with pipe");
    
    return true;
}

bool GameScene::checkCollision(PhysicsBody *a, PhysicsBody *b){
    return (BIRD_COLLIDER == a->getCollisionBitmask( ) && PIPE_COLLIDER == b->getCollisionBitmask());
}

void GameScene::spawnPipe(float dt){
    pipe->spawnPipe(this);
}
