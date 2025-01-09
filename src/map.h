#ifndef MAP_H
#define MAP_H

const int MAP_WIDTH = 7;
const int MAP_HEIGHT = 10;

const int worldMap[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1, 0, 0},
    {1, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1}
};

#endif