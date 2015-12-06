#ifndef __PIPE_H__
#define __PIPE_H__

#define PIPE_GAP 10
#define UPPER_SCREEN_PIPE_THRESHOLD 0.65
#define LOWER_SCREEN_PIPE_THRESHOLD 0.35
#define PIPE_VELOCITY 0.01

#include "cocos2d.h"

class Pipe{
public:
    Pipe(cocos2d::Size visibleSize, cocos2d::Vec2 origin);
    void spawnPipe(cocos2d::Layer *layer);
    
private:
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
};

#endif // __PIPE_H__
