#include "raycasting.h"
#include "palette.h"
#include "player.h"
#include "math.h"

const float PI = 3.14159265359f;

float playerX = 0.0f;
float playerY = 0.0f;
int playerDirection = 0;

float FOV = 0.5f; //FOV doit être égal à x/180 où x représente le FOV, ainsi, pour 0.5f, le FOV est de 90 degrés

void Raycasting::changePosition(int x, int y, int rotation) {
    playerX = x * MAP_WIDTH / EADK::Screen::Width;
    playerY = y * MAP_HEIGHT / EADK::Screen::Height;
    playerDirection = rotation;
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
    Math math_obj;
    for (int x = 0; x < EADK::Screen::Width; x++) {
        float vision = ((x * 2) / EADK::Screen::Width) - 1;
        float rayx = playerX;
        float rayy = playerY;
        int count = 0;
        bool touched = false;
        while (touched == false && count < 20) {
            count += 1;
            rayx += math_obj.sinus(vision * 90.0f * FOV + playerDirection, false);
            rayy += math_obj.cosinus(vision * 90.0f * FOV + playerDirection);
            if (checkWall(rayx, rayy)) {
                touched = true;
            }
        }
        if (touched == true) {
            float disX = math_obj.pow((playerX - rayx), 2);
            float disY = math_obj.pow((playerY - rayy), 2);
            float distance = math_obj.sqrt(disX + disY);
            int nbPixels = int((EADK::Screen::Width - 20) / (distance + 1));
            EADK::Display::pushRectUniform(EADK::Rect(x, EADK::Screen::Height / 2 - nbPixels / 2, 1, nbPixels), Black);
            EADK::Display::pushRectUniform(EADK::Rect(x, 0, 1, (EADK::Screen::Height - nbPixels) / 2), White);
            EADK::Display::pushRectUniform(EADK::Rect(x, (EADK::Screen::Height / 2 + nbPixels / 2), 1, (EADK::Screen::Height - nbPixels) / 2), White);
        }
    }
    EADK::Display::drawString("doomWorks 0.0.1", EADK::Point{ 10, 0 }, false, Black, White);

    EADK::Display::drawString("inDev version - Made by RockingCha1r", EADK::Point{ 10, 20 }, false, Black, White);
}