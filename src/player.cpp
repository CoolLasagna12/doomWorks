#include "player.h"
#include "palette.h"
#include "math.h"
#include "raycasting.h"

Player::Player() :
	playerX(2),
	playerY(2)
{

}

void Player::turn(float deg) {
	direction += deg;
	Raycasting raycasting_obj;
	raycasting_obj.changePosition(int(playerX), int(playerY), direction);
}

void Player::draw(const EADK::Color color) {
	EADK::Display::pushRectUniform(EADK::Rect(playerX -10, playerY - 10, 20, 20), color);
}

void Player::move(int x, int y) {
  playerX += x;
  playerY += y;
  playerX = playerX <= k_xLowerBound ? k_xLowerBound : playerX;
  playerY = playerY <= k_yLowerBound ? k_yLowerBound : playerY;
  playerX = playerX >= k_xUpperBound ? k_xUpperBound : playerX;
  playerY = playerY >= k_yUpperBound ? k_yUpperBound : playerY;
  Raycasting raycasting_obj;
  raycasting_obj.changePosition(playerX, playerY, direction);
  draw(Red);
}
