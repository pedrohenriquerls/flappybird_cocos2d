#include "Pipe.h"
#include "Definitions.h"

USING_NS_CC;

Pipe::Pipe(cocos2d::Size visibleSize, cocos2d::Vec2 origin){
    this->visibleSize = visibleSize;
    this->origin = origin;
}

void Pipe::spawnPipe(cocos2d::Layer *layer){
    auto topPipe = Sprite::create("Pipe.png");
    auto bottomPipe = Sprite::create("Pipe.png");
    
    auto topPipeBody = PhysicsBody::createBox(topPipe->getContentSize());
    auto bottomPipeBody = PhysicsBody::createBox(bottomPipe->getContentSize());
    
    auto random = CCRANDOM_0_1( );
    
    if ( random < LOWER_SCREEN_PIPE_THRESHOLD )
        random = LOWER_SCREEN_PIPE_THRESHOLD;
    else if ( random > UPPER_SCREEN_PIPE_THRESHOLD )
        random = UPPER_SCREEN_PIPE_THRESHOLD;
    
    auto topPipeSize = topPipe->getContentSize();
    
    auto topPipePosition = (random * visibleSize.height) + (topPipeSize.height/2);
    
    topPipeBody->setDynamic(false);
    topPipeBody->setCollisionBitmask(PIPE_COLLIDER);

    bottomPipeBody->setDynamic(false);
    bottomPipeBody->setCollisionBitmask(PIPE_COLLIDER);
    
    if(DEBUG_MODE){
        bottomPipeBody->setContactTestBitmask(true);
        topPipeBody->setContactTestBitmask(true);
    }
    
    topPipe->setPhysicsBody(topPipeBody);
    bottomPipe->setPhysicsBody(bottomPipeBody);
    
    float ballSpriteHeight = Sprite::create("Ball.png")->getContentSize().height;
    topPipe->setPosition(Point(visibleSize.width + topPipeSize.width + origin.x, topPipePosition));
    bottomPipe->setPosition(Point(topPipe->getPositionX(), topPipePosition-(ballSpriteHeight * PIPE_GAP) - topPipeSize.height));
    
    layer->addChild(topPipe);
    layer->addChild(bottomPipe);

    float realSpeed = PIPE_VELOCITY * visibleSize.width;
    auto point = Point(-visibleSize.width * 1.5, 0);

    auto topPipeMovement = MoveBy::create(realSpeed, point);
    auto topPipeMovementRelease = CallFunc::create( [layer, topPipe]() {
        CCLOG("Removing top pipe!!");
        layer->removeChild(topPipe);
    });
    auto topPipeMovementSequence = Sequence::create(topPipeMovement, topPipeMovementRelease, NULL);
    topPipe->runAction(topPipeMovementSequence);

    auto bottomPipeMovement = MoveBy::create(realSpeed, point);
    auto bottomPipeMovementRelease = CallFunc::create( [layer, bottomPipe]() {
        CCLOG("Removing bottom pipe!!");
        layer->removeChild(bottomPipe);
    });
    auto bottomPipeMovementSequence = Sequence::create(bottomPipeMovement, bottomPipeMovementRelease, NULL);
    bottomPipe->runAction(bottomPipeMovementSequence);
}
