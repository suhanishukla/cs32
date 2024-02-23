#include "StudentWorld.h"
#include "GameConstants.h"
#include "Level.h"
#include "Actor.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h, and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
: GameWorld(assetPath)
{
    m_avatar = nullptr;
    walls.clear();
}

int StudentWorld::init()
{
    Level lev(assetPath());
        string levelFile = "level0" + to_string(getLevel()) + ".txt"; // depends on if level is 1 or 2 digit
        Level::LoadResult result = lev.loadLevel(levelFile);
        if (result == Level::load_fail_file_not_found)
            cerr << "Cannot find " << levelFile << " data file" << endl;
        else if (result == Level::load_fail_bad_format)
            cerr << "Your level was improperly formatted" << endl;
        else if (result == Level::load_success) {
            cerr << "Successfully loaded level" << endl;
            for (int x = 0; x < 16; x++) {
                for (int y = 0; y < 16; y++) {
                    Level::MazeEntry me = lev.getContentsOf(x, y);
                    switch (me) {
                        case Level::empty:
                            cerr << "location " << x << " " << y << " is empty" << endl;
                            break;
                        case Level::exit:
                            cerr << "location " << x << " " << y << " is an exit" << endl;
                            break;
                        case Level::player:
                            cerr << "location " << x << " " << y << " is where player is" << endl;
                            m_avatar = new Avatar(this, x, y);
                            break;
                        case Level::wall:
                            cerr << "location " << x << " " << y << " is where a wall is" << endl;
                            walls.push_back(new Wall(this, x, y));
                            break;
                        default:
                            break;

                    }
                }
            }
        }
    
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    // This code is here merely to allow the game to build, run, and terminate after you type q
    m_avatar->doSomething();
    for (Wall* w: walls) {
        w->doSomething();
    }

    setGameStatText("Game will end when you type q");
    
	return GWSTATUS_CONTINUE_GAME;
}
bool StudentWorld::isWallAt(double x, double y) {
    for (Wall* w : walls) {
        if (x + SPRITE_WIDTH_GL >= w->getX() and x <= w->getX() + SPRITE_WIDTH_GL) {
            if (y + SPRITE_HEIGHT_GL >= w->getY() and y <= w->getY() + SPRITE_HEIGHT_GL) {
                return true;
            }
        }
    }
    return false;
}
void StudentWorld::cleanUp()
{
    for (Wall* w : walls) {
        delete w;
    }
    walls.clear();
    delete m_avatar;
    m_avatar = nullptr;
}
StudentWorld::~StudentWorld() {
    cleanUp();
}
