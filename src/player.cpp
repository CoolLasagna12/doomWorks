#include "player.h"
#include "palette.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Player::Player() :
  float tempDir;
  p_x(EADK::Screen::Width/2),
  p_y(EADK::Screen::Height - Display::CommonVerticalMargin)
{
  draw(Yellow);
}

void Player::draw(const EADK::Color color) const {
  EADK::Display::pushRectUniform(EADK::Rect(p_x - 10, p_y - 10, 20, 20), color);
}

void Player::turn(float deg) {
  direction += deg;
}

void Player::move(int move) {
  tempDir = (direction * M_PI)/180;
  draw(Black);
  p_x += move * sin(tempDir)
  p_y -= move * cos(tempDir);
  p_x = p_x <= k_xLowerBound ? k_xLowerBound : p_x;
  p_y = p_y <= k_yLowerBound ? k_yLowerBound : p_y;
  p_x = p_x >= k_xUpperBound ? k_xUpperBound : p_x;
  p_y = p_y >= k_yUpperBound ? k_yUpperBound : p_y;
  draw(Yellow);
}
