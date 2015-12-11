#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Pipe.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
private:
    Pipe *pipe;
    cocos2d::PhysicsWorld *sceneWorld;
    bool checkCollision(cocos2d::PhysicsBody *a, cocos2d::PhysicsBody *b);
    bool onBirdCollidesWithPipe(cocos2d::PhysicsContact &contact);
    void spawnPipe(float dt);
    void setPhysicsWorld(cocos2d::PhysicsWorld *world){
        sceneWorld = world;
    }
};

#endif // __GAME_SCENE_H__
