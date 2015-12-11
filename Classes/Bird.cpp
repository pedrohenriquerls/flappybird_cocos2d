#include "Bird.h"
#include "Definitions.h"

USING_NS_CC;

Bird::Bird(cocos2d::Size visibleSize, cocos2d::Vec2 origin, cocos2d::Layer *scene){
    this->visibleSize = visibleSize;
    this->origin = origin;
    
    auto birdSprite = Sprite::create("Ball.png");
    birdSprite->setPosition(CENTER_POSITION);
    
    auto birdBody = PhysicsBody::createCircle(birdSprite->getContentSize().width/2);
    birdBody->setCollisionBitmask(BIRD_COLLIDER);

    if(DEBUG_MODE)
        birdBody->setContactTestBitmask(true);
    
    birdSprite->setPhysicsBody(birdBody);
    scene->addChild(birdSprite);
}
