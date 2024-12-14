#include "raycasting.h"
#include "palette.h"
#include "player.h"
#include "math.h"

const float PI = 3.14159265359f;

int playerX = 0;
int playerY = 0;

void Raycasting::changePosition(int x, int y) {
    playerX = x;
    playerY = y;
    Raycast();
}

int worldMap[MAP_HEIGHT][MAP_WIDTH] = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

bool Raycasting::checkWall(int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        return worldMap[int(y)][int(x)] == 1;
    }
    return false;
};



void Raycasting::Raycast() {
    EADK::Display::pushRectUniform(EADK::Rect(0,0, EADK::Screen::Width, EADK::Screen::Height),White);
    Math math_obj;
    for (int x = 0; x < EADK::Screen::Width; x++) {
        float vision = ((x * 2) / EADK::Screen::Width) - 1;
        float rayx = 0;
        float rayy = 0;
        bool touched = false;
        while (touched == false) {
            rayx += math_obj.sinus(vision * PI + 0.5 * PI, false);
            rayy += math_obj.sinus(vision * 180 / PI, false);
            if (checkWall(rayx, rayy)) {
                touched = true;
            }
        }
        float disX = math_obj.pow((playerX - rayx), 2);
        float disY = math_obj.pow((playerY - rayy), 2);
        float distance = math_obj.sqrt(disX + disY);
        int nbPixels = int(926.94 / (distance + 4.17));
        EADK::Display::pushRectUniform(EADK::Rect(x,EADK::Screen::Height / 2 - nbPixels / 2,1,nbPixels), Black);
    }
    EADK::Display::drawString("doomWorks 0.0.1", EADK::Point{ 10, 0 }, false, Black, White);

    EADK::Display::drawString("inDev version - Made by RockingCha1r", EADK::Point{ 10, 20 }, false, Black, White);
}
