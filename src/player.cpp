#include "player.h"
#include "palette.h"
#include "math.h"
#include "raycasting.h"

Player::Player() :
  playerX(2),
  playerY(2)
{
  draw(Yellow);
}

void Player::draw(const EADK::Color color) const {
  EADK::Display::pushRectUniform(EADK::Rect(int(playerX) - 10, int(playerY) - 10, 20, 20), color);
}

void Player::turn(float deg) {
  direction += deg;
}

void Player::move(int move) {
  draw(Black);
  Math math_obj;
  playerX += move * math_obj.sinus(direction, false);
  playerY -= move * math_obj.cosinus(direction);
  playerX = playerX <= k_xLowerBound ? k_xLowerBound : playerX;
  playerY = playerY <= k_yLowerBound ? k_yLowerBound : playerY;
  playerX = playerX >= k_xUpperBound ? k_xUpperBound : playerX;
  playerY = playerY >= k_yUpperBound ? k_yUpperBound : playerY;
  draw(Yellow);
  Raycasting raycasting_obj;
  raycasting_obj.changePosition(int(playerX), int(playerY));
}
