#include "player.h"
#include "palette.h"
#include "trigoApprox.h"
#include "transformations.h"

Player::Player() :
  p_x(EADK::Screen::Width / 2),
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
  draw(Black);
  TrigoApprox trigo_obj;
  p_x += move * trigo_obj.sinus(direction, false);
  p_y -= move * trigo_obj.sinus(direction, true);
  EADK::Display::drawString("Hello World", EADK::Point{10, 0}, false, White, Black);
  EADK::Display::drawString("Hello World", EADK::Point{10, 0}, false, White, Black);
  p_x = p_x <= k_xLowerBound ? k_xLowerBound : p_x;
  p_y = p_y <= k_yLowerBound ? k_yLowerBound : p_y;
  p_x = p_x >= k_xUpperBound ? k_xUpperBound : p_x;
  p_y = p_y >= k_yUpperBound ? k_yUpperBound : p_y;
  draw(Yellow);
}
