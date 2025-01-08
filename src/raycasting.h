#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "player.h"
#include "display.h"
#include "eadkpp.h"


const int MAP_WIDTH = 7;
const int MAP_HEIGHT = 10;

extern int worldMap[MAP_HEIGHT][MAP_WIDTH];

class Raycasting {
private:
    bool checkWall(int x, int y);
public:
    void changePosition(float x, float y, float rotation);
    void Raycast();
};

#endif