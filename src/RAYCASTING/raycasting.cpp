#include "raycasting.h"
#include "../EADK/palette.h"
#include "../CHARACTERS/player.h"
#include "../LIBS/math.h"
#include "map.h"
#include "../TEXTURES/textures.h"

const float PI = 3.14159265359f;

float playerX = 2.5f;
float playerY = 2.5f;
float playerDirection = 0.0f;

const float FOV = 0.5f; //FOV doit être égal à x/180 où x représente le FOV, ainsi, pour 0.5f, le FOV est de 90 degrés

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
    int drawX = 0;
    for (int x = 0; x < EADK::Screen::Width/2; x++) {
        x = x * 2;
        float vision = ((x * 2.0f) / EADK::Screen::Width) - 1;
        float rayx = playerX;
        float rayy = playerY;
        int count = 0;
        bool touched = false;

        float hitPosition = 0.0f;

        float dx = math_obj.sinus(vision * 90.0f * FOV + playerDirection, false);
        float dy = -math_obj.cosinus(vision * 90.0f * FOV + playerDirection);
        float power = math_obj.pow(2, (count * 0.01));

        while (touched == false && count < 200) {
            count += 1;
            rayx += dx * 0.05f * power;
            rayy += dy * 0.05f * power;
            if (checkWall(rayx, rayy)) {
                touched = true;
                if (math_obj.abs(rayx - math_obj.floor(rayx)) < math_obj.abs(rayy - math_obj.floor(rayy))) { // SUD // EST
                    if (dx > 0.5) { // est
                        hitPosition = rayy - math_obj.floor(rayy);
                    }
                    else { // sud
                        hitPosition = rayx - math_obj.floor(rayx);
                    }
                }
                else { 
                    if (dy > 0.5) { // nord
                        hitPosition = rayx - math_obj.floor(rayx);
                    }
                    else { // ouest
                        hitPosition = rayy - math_obj.floor(rayy);
                    }

                }

            }
        }
        if (touched == true) {
            float disX = math_obj.pow((playerX - rayx), 2);
            float disY = math_obj.pow((playerY - rayy), 2);
            float distance = math_obj.sqrt(disX + disY);
            int nbPixels = int((EADK::Screen::Height - 20) / (distance + 0.01f));
            if ((EADK::Screen::Height - nbPixels) / 2 < 0) {
                nbPixels = 240;
            }
            EADK::Display::pushRectUniform(EADK::Rect(x, 0, 2, (EADK::Screen::Height - nbPixels) / 2), White);
            EADK::Display::pushRectUniform(EADK::Rect(x, EADK::Screen::Height / 2 + nbPixels / 2, 2, (EADK::Screen::Height - nbPixels) / 2), Grey);

            int pixelSize;
            int pixelNb = hitPosition * 16;
            int remainingPixels = nbPixels;

            for (int i = 0; i < wallHeight; ++i) {
                if (wallHeight - i > 0) {
                    pixelSize = remainingPixels / (wallHeight - i);
                }
                EADK::Display::pushRectUniform(EADK::Rect(drawX * 2, EADK::Screen::Height / 2 - nbPixels / 2 + nbPixels - remainingPixels, 2, pixelSize), wallTexture[i * 16 + pixelNb]);
                remainingPixels -= pixelSize;
            }
            drawX++;
        }
        else {
            EADK::Display::pushRectUniform(EADK::Rect(x, 0, 2, EADK::Screen::Height), White);
        }
        x = x / 2;
    }
}
