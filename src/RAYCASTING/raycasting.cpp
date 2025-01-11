#include "raycasting.h"
#include "../EADK/palette.h"
#include "../CHARACTERS/player.h"
#include "../LIBS/math.h"
#include "map.h"

const float PI = 3.14159265359f;

float playerX = 2.5f;
float playerY = 2.5f;
float playerDirection = 0.0f;

float FOV = 0.5f; //FOV doit être égal à x/180 où x représente le FOV, ainsi, pour 0.5f, le FOV est de 90 degrés

void Raycasting::changePosition(float x, float y, float rotation) {
    playerX = x / float(EADK::Screen::Width) * tileSize;
    playerY = y / float(EADK::Screen::Height) * tileSize;
    playerDirection = rotation;
    Raycast();
}

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
    for (int x = 0; x < EADK::Screen::Width/2; x++) {
        x = x * 2;
        float vision = ((x * 2.0f) / EADK::Screen::Width) - 1;
        float rayx = playerX;
        float rayy = playerY;
        int count = 0;
        bool touched = false;
        while (touched == false && count < 200) {
            count += 1;
            rayx += math_obj.sinus(vision * 90.0f * FOV + playerDirection, false) * 0.05f * (math_obj.pow(2,(count * 0.01)));
            rayy -= math_obj.cosinus(vision * 90.0f * FOV + playerDirection) * 0.05f * (math_obj.pow(2, (count * 0.01)));
            if (checkWall(rayx, rayy)) {
                touched = true;
            }
        }
        if (touched == true) {
            float disX = math_obj.pow((playerX - rayx), 2);
            float disY = math_obj.pow((playerY - rayy), 2);
            float distance = math_obj.sqrt(disX + disY);
            int nbPixels = int((EADK::Screen::Height - 20) / (distance + 0.01f));
            EADK::Display::pushRectUniform(EADK::Rect(x, EADK::Screen::Height / 2 - nbPixels / 2, 2, nbPixels), Black);
            if ((EADK::Screen::Height - nbPixels) / 2 < 0) {
                EADK::Display::pushRectUniform(EADK::Rect(x, 0, 2, EADK::Screen::Height), Black);
            }
            else {
                EADK::Display::pushRectUniform(EADK::Rect(x, 0, 2, (EADK::Screen::Height - nbPixels) / 2), White);
                EADK::Display::pushRectUniform(EADK::Rect(x, EADK::Screen::Height / 2 + nbPixels / 2, 2, (EADK::Screen::Height - nbPixels) / 2), White);
            }
        }
        else {
            EADK::Display::pushRectUniform(EADK::Rect(x, 0, 2, EADK::Screen::Height), White);
        }
        x = x / 2;
    }
}
