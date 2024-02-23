#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "Level.h"
#include "Actor.h"
#include <string>
#include <vector>
using namespace std;

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
  StudentWorld(std::string assetPath);
  virtual int init();
  virtual int move();
  virtual void cleanUp();
    bool isWallAt(double x, double y);
    StudentWorld();
    ~StudentWorld();

private:
    Avatar* m_avatar;
    vector<Wall*> walls;
    
};

#endif // STUDENTWORLD_H_
