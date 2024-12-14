#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "player.h"
#include "display.h"
#include "eadkpp.h"


const int MAP_WIDTH = 5;
const int MAP_HEIGHT = 5;

extern int worldMap[MAP_HEIGHT][MAP_WIDTH];

class Raycasting {
private:
    bool checkWall(int x, int y);
public:
    void changePosition(int x, int y);
    void Raycast();
};

#endif