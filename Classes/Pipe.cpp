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
    bottomPipeBody->setDynamic(false);
    
    topPipe->setPhysicsBody(topPipeBody);
    bottomPipe->setPhysicsBody(bottomPipeBody);
    
    float ballSpriteHeight = Sprite::create("Ball.png")->getContentSize().height;
    topPipe->setPosition(Point(visibleSize.width/2 + topPipeSize.width + origin.x+CCRANDOM_MINUS1_1()*250, topPipePosition));
    bottomPipe->setPosition(Point(topPipe->getPositionX(), topPipePosition-(ballSpriteHeight * PIPE_GAP) - topPipeSize.height));
    
    layer->addChild(topPipe);
    layer->addChild(bottomPipe);

}