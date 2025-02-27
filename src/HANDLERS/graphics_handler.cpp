#include "../RAYCASTING/raycasting.h"
#include "../TEXTURES/textures.h"
#include "graphics_handler.h"

int middleScreenX = EADK::Screen::Width / 2 - 20;
int startY = EADK::Screen::Height - gunTextureHeight * 7; // Remplacer la dernière valeur par la taille d'un pixel de l'image
void graphicsHandler() {
	Raycast();

    for (int x = 0; x < gunTextureWidth; ++x) {
        for (int y = 0; y < gunTextureHeight; ++y) {
            if (gunTexture[y * gunTextureWidth + x] != 0) {
                EADK::Display::pushRectUniform(EADK::Rect(middleScreenX + x * 7, startY + y * 7, 7, 7), gunTexture[y * gunTextureWidth + x]);
            }
        }
    }
}