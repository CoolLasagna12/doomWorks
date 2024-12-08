#include "player.h"
#include "palette.h"
#include "trigoApprox.h"
#include <cmath>
#include <string>

Player::Player() :
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
  draw(Black);
  TrigoApprox trigo_obj;
  p_x += move * trigo_obj.sinus(direction, false);
  p_y -= move * trigo_obj.sinus(direction, true);
  EADK::Display::drawString("Hello World", EADK::Point{10, 0}, false, White, Black);
  std::string text1 = std::to_string(direction);
  std::string text2 = std::to_string(trigo_obj.sinus(direction, false));
  std::string text3 = std::to_string(trigo_obj.sinus(direction, true));
  EADK::Display::drawString(text1.c_str(), EADK::Point{10, 20}, false, White, Black);
  EADK::Display::drawString(text2.c_str(), EADK::Point{10, 40}, false, White, Black);
  EADK::Display::drawString(text3.c_str(), EADK::Point{10, 60}, false, White, Black);
  p_x = p_x <= k_xLowerBound ? k_xLowerBound : p_x;
  p_y = p_y <= k_yLowerBound ? k_yLowerBound : p_y;
  p_x = p_x >= k_xUpperBound ? k_xUpperBound : p_x;
  p_y = p_y >= k_yUpperBound ? k_yUpperBound : p_y;
  draw(Yellow);
}
