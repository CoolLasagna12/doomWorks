#include "player.h"
#include "palette.h"
#include "math.h"

Player::Player() :
  p_x(EADK::Screen::Width / 2),
  p_y(EADK::Screen::Height - Display::CommonVerticalMargin)
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
  playerX += move * math_obj.sinus(direction);
  playerY -= move * math_obj.cosinus(direction);
  playerX = playerX <= k_xLowerBound ? k_xLowerBound : p_x;
  playerY = playerY <= k_yLowerBound ? k_yLowerBound : p_y;
  playerX = playerX >= k_xUpperBound ? k_xUpperBound : p_x;
  playerY = playerY >= k_yUpperBound ? k_yUpperBound : p_y;
  draw(Yellow);
}
