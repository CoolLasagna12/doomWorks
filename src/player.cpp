#include "player.h"
#include "palette.h"
#include "trigoApprox.h"

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
  if (move > 0.0f) {
    EADK::Display::drawString("move > 0", EADK::Point{10, 20}, false, White, Black);
  } else if (move < 10.0f) {
    EADK::Display::drawString("move < 10", EADK::Point{10, 20}, false, White, Black);
  } else {
    EADK::Display::drawString("move > 10", EADK::Point{10, 20}, false, White, Black);
  }
  if (trigo_obj.sinus(direction, false) < 0.0f) {
    EADK::Display::drawString("sin direction > 0", EADK::Point{10, 40}, false, White, Black);
  } else if (trigo_obj.sinus(direction, false) < 10.0f) {
    EADK::Display::drawString("sin direction < 10", EADK::Point{10, 40}, false, White, Black);
  } else if (trigo_obj.sinus(direction, false) < 100.0f) {
    EADK::Display::drawString("sin direction < 100", EADK::Point{10, 40}, false, White, Black);
  } else {
    EADK::Display::drawString("sin direction > 100", EADK::Point{10, 40}, false, White, Black);
  }
  if (direction < 0.0f) {
    EADK::Display::drawString("direction > 0", EADK::Point{10, 60}, false, White, Black);
  } else if (direction < 10.0f) {
    EADK::Display::drawString("direction < 10", EADK::Point{10, 60}, false, White, Black);
  } else if (direction < 100.0f) {
    EADK::Display::drawString("direction < 100", EADK::Point{10, 60}, false, White, Black);
  } else {
    EADK::Display::drawString("direction > 100", EADK::Point{10, 60}, false, White, Black);
  }
  if (trigo_obj.sinus(direction, true) < 0.0f) {
    EADK::Display::drawString("cos direction > 0", EADK::Point{10, 80}, false, White, Black);
  } else if (trigo_obj.sinus(direction, true) < 10.0f) {
    EADK::Display::drawString("cos direction < 10", EADK::Point{10, 80}, false, White, Black);
  } else if (trigo_obj.sinus(direction, true) < 100.0f) {
    EADK::Display::drawString("cos direction < 100", EADK::Point{10, 80}, false, White, Black);
  } else {
    EADK::Display::drawString("cos direction > 100", EADK::Point{10, 80}, false, White, Black);
  }
  EADK::Display::drawString("Hello World", EADK::Point{10, 0}, false, White, Black);
  p_x = p_x <= k_xLowerBound ? k_xLowerBound : p_x;
  p_y = p_y <= k_yLowerBound ? k_yLowerBound : p_y;
  p_x = p_x >= k_xUpperBound ? k_xUpperBound : p_x;
  p_y = p_y >= k_yUpperBound ? k_yUpperBound : p_y;
  draw(Yellow);
}
