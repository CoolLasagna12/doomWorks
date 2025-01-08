#include "raycasting.h"
#include "palette.h"
#include "player.h"
#include "math.h"

const float PI = 3.14159265359f;

float playerX = 0.0f;
float playerY = 0.0f;
float playerDirection = 0.0f;

float FOV = 0.5f; //FOV doit être égal à x/180 où x représente le FOV, ainsi, pour 0.5f, le FOV est de 90 degrés
float tileSize = 5.0f; // Taille d'une tile. Plus le nombre est grand, plus elle est petite. 5, c'est pas mal

void Raycasting::changePosition(float x, float y, float rotation) {
    playerX = x / float(EADK::Screen::Width) * tileSize;
    playerY = y / float(EADK::Screen::Height) * tileSize;
    playerDirection = rotation;
    Raycast();
}

int worldMap[MAP_HEIGHT][MAP_WIDTH] = {
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

bool Raycasting::checkWall(int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        if (worldMap[int(y)][int(x)] == 1) {
            return true;
        }
    }
    return false;
};

void Raycasting::Raycast() {
    Math math_obj;
    for (int x = 0; x < EADK::Screen::Width; x++) {
        float vision = ((x * 2.0f) / EADK::Screen::Width) - 1;
        float rayx = playerX;
        float rayy = playerY;
        int count = 0;
        bool touched = false;
        while (touched == false && count < 100) {
            count += 1;
            rayx += math_obj.sinus(vision * 90.0f * FOV + playerDirection, false) * 0.1f * (math_obj.pow(2,(count * 0.01)));
            rayy -= math_obj.cosinus(vision * 90.0f * FOV + playerDirection) * 0.1f * (math_obj.pow(2, (count * 0.01)));
            if (checkWall(rayx, rayy)) {
                touched = true;
            }
        }
        if (touched == true) {
            float disX = math_obj.pow((playerX - rayx), 2);
            float disY = math_obj.pow((playerY - rayy), 2);
            float distance = math_obj.sqrt(disX + disY);
            int nbPixels = int((EADK::Screen::Height - 20) / (distance + 0.01f));
            EADK::Display::pushRectUniform(EADK::Rect(x, EADK::Screen::Height / 2 - nbPixels / 2, 1, nbPixels), Black);
            if ((EADK::Screen::Height - nbPixels) / 2 < 0) {
                EADK::Display::pushRectUniform(EADK::Rect(x, 0, 1, 222), Black);
            }
            else {
                EADK::Display::pushRectUniform(EADK::Rect(x, 0, 1, (EADK::Screen::Height - nbPixels) / 2), White);
                EADK::Display::pushRectUniform(EADK::Rect(x, EADK::Screen::Height / 2 + nbPixels / 2, 1, (EADK::Screen::Height - nbPixels) / 2), White);
            }
        }
        else {
            EADK::Display::pushRectUniform(EADK::Rect(x, 0, 1, EADK::Screen::Height), White);
        }
    }
    EADK::Display::drawString("doomWorks 0.0.1", EADK::Point{ 10, 0 }, false, Black, White);

    EADK::Display::drawString("inDev version - Made by RockingCha1r", EADK::Point{ 10, 20 }, false, Black, White);
}
