#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp
void Avatar::doSomething() {
    int ch;
    if (getWorld()->getKey(ch))
        {
            switch(ch) {
                case KEY_PRESS_UP:
                    //check to see if its a valid pos 
                    if (!getWorld()->isWallAt(getX(), getY()+1)) {
                        setDirection(up);
                        moveTo(getX(), getY()+1);
                    }
                    break;
                case KEY_PRESS_DOWN:
                    if (!getWorld()->isWallAt(getX(), getY()-1)) {
                        setDirection(down);
                        moveTo(getX(), getY()-1);
                    }
                    break;
                case KEY_PRESS_LEFT:
                    if (!getWorld()->isWallAt(getX()-1, getY())) {
                        setDirection(left);
                        moveTo(getX()-1, getY());
                    }
                    break;
                case KEY_PRESS_RIGHT:
                    if (!getWorld()->isWallAt(getX()+1, getY())) {
                        setDirection(right);
                        moveTo(getX()+1, getY());
                    }
                    break;
                default:
                    break;
                    
            }
        }
}
