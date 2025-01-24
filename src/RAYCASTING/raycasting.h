#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "../CHARACTERS/player.h"
#include "../EADK/eadkpp.h"

class Raycasting {
private:
    bool checkWall(int x, int y);
    float calculateAngle(float x1, float y1, float x2, float y2);
public:
    static constexpr float tileSize = 5.0f; // Taille d'une tile. Plus le nombre est grand, plus elle est petite. 5, c'est pas mal
    void changePosition(float x, float y, float rotation);
    void Raycast();
};

#endif