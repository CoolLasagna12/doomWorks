#ifndef PLAYER_H
#define PLAYER_H

#include "display.h"
#include "eadkpp.h"


  class Player {
public:
  Player();
  int x() const { return p_x; }
  int y() const { return p_y; }
  void move(int deltaX, int deltaY);
  static constexpr int k_step = 1;
private:
  static constexpr int k_xLowerBound = DISPLAY::CommonHorizontalMargin/2;
  static constexpr int k_xUpperBound = EADK::Screen::Width - DISPLAY::CommonHorizontalMargin/2;
  static constexpr int k_yLowerBound = DISPLAY::CommonVerticalMargin/2;
  static constexpr int k_yUpperBound = EADK::Screen::Height - DISPLAY::CommonVerticalMargin/2;
  void draw(const EADK::Color c) const;
  int p_x;
  int p_y;
};

#endif
