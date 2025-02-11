#include "player.h"
#include "../RAYCASTING/raycasting.h"
#include "../LIBS/math.h"
#include "../RAYCASTING/map.h"

Player::Player() :
	playerX(160),
	playerY(111)
{

}

void Player::turn(float deg) {
    direction += deg;
    changePosition(int(playerX), int(playerY), direction);
};

bool Player::checkInsideWall(int x, int y) {
    x = x / float(EADK::Screen::Width) * tileSize;
    y = y / float(EADK::Screen::Height) * tileSize;
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        if (worldMap[y][x] == 1) {
            return true;
        }
    }
    return false;
};

void Player::move(int movement) {
  float lastPlayerX = playerX;
  float lastPlayerY = playerY;
  playerX += movement * sinus(direction, false);
  playerY -= movement * cosinus(direction);
  if (checkInsideWall(int(playerX), int(playerY))) {
      playerX = lastPlayerX;
      playerY = lastPlayerY;
  }
  else {
      changePosition(playerX, playerY, direction);
  }
}
