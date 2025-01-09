#include "player.h"
#include "raycasting.h"
#include "math.h"
#include "map.h"

Player::Player() :
	playerX(160),
	playerY(111)
{

}

void Player::turn(float deg) {
    direction += deg;
    Raycasting raycasting_obj;
    raycasting_obj.changePosition(int(playerX), int(playerY), direction);
};

bool Player::checkInsideWall(int x, int y) {
    x = x / float(EADK::Screen::Width) * Raycasting::tileSize;
    y = y / float(EADK::Screen::Height) * Raycasting::tileSize;
    if (x >= 0 && x < MAP_WIDTH && y >= 0 && y < MAP_HEIGHT) {
        if (worldMap[y][x] == 1) {
            return true;
        }
    }
    return false;
};

void Player::move(int movement) {
  Math playerMath;
  float lastPlayerX = playerX;
  float lastPlayerY = playerY;
  playerX += movement * playerMath.sinus(direction, false);
  playerY -= movement * playerMath.cosinus(direction);
  if (checkInsideWall(int(playerX), int(playerY))) {
      playerX = lastPlayerX;
      playerY = lastPlayerY;
  }
  else {
      Raycasting raycasting_obj;
      raycasting_obj.changePosition(playerX, playerY, direction);
  }
}
