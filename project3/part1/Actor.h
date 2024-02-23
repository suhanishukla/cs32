#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
//base
class StudentWorld;

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp
class Actor : public GraphObject {
public:
    Actor(StudentWorld* world, int imageID, double startX, double startY, int startDirection): GraphObject(imageID, startX, startY), m_world(world) {}
    virtual void doSomething() = 0;
    StudentWorld* getWorld() {return m_world;}
private:
    StudentWorld* m_world;
};
class Wall : public Actor {
public:
    Wall(StudentWorld* world, double levelx, double levely) : Actor(world, IID_WALL, levelx, levely, none) {setVisible(true);}
    virtual void doSomething() {return;}
    
};
class Avatar : public Actor {
public:
    Avatar(StudentWorld* world, int levelx, int levely) : Actor(world, IID_PLAYER, levelx,  levely, right) {setVisible(true);}
    virtual void doSomething();
};

#endif // ACTOR_H_
