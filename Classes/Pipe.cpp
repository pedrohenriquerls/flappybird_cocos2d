#include "Pipe.h"
#include "Definitions.h"

USING_NS_CC;

Pipe::Pipe(cocos2d::Size visibleSize, cocos2d::Vec2 origin){
    this->visibleSize = visibleSize;
    this->origin = origin;
}

void Pipe::spawnPipe(cocos2d::Layer *layer){
    CCLOG("Blastoise");
}