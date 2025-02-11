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

void changePosition(float x, float y, float rotation) {
    playerX = x / float(EADK::Screen::Width) * tileSize;
    playerY = y / float(EADK::Screen::Height) * tileSize;
    playerDirection = rotation;
    Raycast();
}

bool checkWall(int x, int y) {
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        if (worldMap[int(y)][int(x)] == 1) {
            return true;
        }
    }
    return false;
};

void Raycast() {
    int drawX = 0;
    for (int x = 0; x < EADK::Screen::Width/2; x++) {
        x = x * 2;
        float vision = ((x * 2.0f) / EADK::Screen::Width) - 1;
        float rayx = playerX;
        float rayy = playerY;
        int count = 0;
        bool touched = false;

        float hitPosition = 0.0f;

        float dx = sinus(vision * 90.0f * FOV + playerDirection, false);
        float dy = -cosinus(vision * 90.0f * FOV + playerDirection);
        int mapX = int(floor(rayx));
        int mapY = int(floor(rayy));

        float deltaDistX = (dx == 0) ? 1e30f : abs(1.0f / dx);
        float deltaDistY = (dy == 0) ? 1e30f : abs(1.0f / dy);

        int stepX, stepY;
        float sideDistX, sideDistY; 

        if (dx < 0) {
            stepX = -1;
            sideDistX = (rayx - mapX) * deltaDistX;
        }
        else {
            stepX = 1;
            sideDistX = (mapX + 1.0f - rayx) * deltaDistX;
        }

        if (dy < 0) {
            stepY = -1;
            sideDistY = (rayy - mapY) * deltaDistY;
        }
        else {
            stepY = 1;
            sideDistY = (mapY + 1.0f - rayy) * deltaDistY;
        }

        int side = 0;
        float distance = 0.0f;

        while (!touched && count < 200) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            count++;

            if (checkWall(mapX, mapY)) {
                touched = true;

                float perpWallDist;
                if (side == 0) {
                    perpWallDist = (mapX - rayx + (1 - stepX) / 2.0f) / dx;
                }
                else {
                    perpWallDist = (mapY - rayy + (1 - stepY) / 2.0f) / dy;
                }
                distance = perpWallDist;

                if (side == 0) {
                    hitPosition = rayy + perpWallDist * dy;
                }
                else {
                    hitPosition = rayx + perpWallDist * dx;
                }
                hitPosition -= floor(hitPosition);

                break;
            }
        }
        if (touched == true) {
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
