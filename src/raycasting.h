#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "player.h"
#include "eadkpp.h"

class Raycasting {
private:
    bool checkWall(int x, int y);
public:
    static constexpr float tileSize = 5.0f; // Taille d'une tile. Plus le nombre est grand, plus elle est petite. 5, c'est pas mal
    void changePosition(float x, float y, float rotation);
    void Raycast();
};

#endif