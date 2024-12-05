#include "player.h"
#include "palette.h"

Player::Player() :
  p_x(EADK::Screen::Width/2),
  p_y(EADK::Screen::Height - Display::CommonVerticalMargin)
{
  draw(Yellow);
}

void Player::draw(const EADK::Color color) const {
  EADK::Display::pushRectUniform(EADK::Rect(p_x - 10, p_y - 10, 20, 20), color);
}

void Player::move(int deltaX, int deltaY) {
  draw(Black);
  p_x += deltaX;
  p_y += deltaY;
  m_x = m_x <= k_xLowerBound ? k_xLowerBound : m_x;
  m_y = m_y <= k_yLowerBound ? k_yLowerBound : m_y;
  m_x = m_x >= k_xUpperBound ? k_xUpperBound : m_x;
  m_y = m_y >= k_yUpperBound ? k_yUpperBound : m_y;
  draw(Yellow);
}
