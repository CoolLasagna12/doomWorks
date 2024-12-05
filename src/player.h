#ifndef PLAYER_H
#define PLAYER_H

#include "display.h"
#include "eadkpp.h"


class Spaceship {
public:
  Player();
  int x() const { return m_x; }
  int y() const { return m_y; }
  void move(int deltaX, int deltaY);
  static constexpr int k_step = 10;
private:
  static constexpr int k_xLowerBound = Display::CommonHorizontalMargin;
  static constexpr int k_xUpperBound = EADK::Screen::Width - Display::CommonHorizontalMargin;
  static constexpr int k_yLowerBound = 3*Display::CommonVerticalMargin;
  static constexpr int k_yUpperBound = EADK::Screen::Height - Display::CommonVerticalMargin;
  void draw(const EADK::Color c) const;
  int m_x;
  int m_y;
};

#endif
