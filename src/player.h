#ifndef PLAYER_H
#define PLAYER_H

#include "display.h"
#include "eadkpp.h"
#include <stdlib.h>


  class Player {
public:
  Player();
  int x() const { return p_x; }
  int y() const { return p_y; }
  void move(int move);
  static constexpr int k_step = 1;
  static constexpr int k_turn_step = 0.01;
  float direction = 0.0;
  void turn(float deg);
private:
  static constexpr int k_xLowerBound = Display::CommonHorizontalMargin/2;
  static constexpr int k_xUpperBound = EADK::Screen::Width - Display::CommonHorizontalMargin/2;
  static constexpr int k_yLowerBound = Display::CommonVerticalMargin/2;
  static constexpr int k_yUpperBound = EADK::Screen::Height - Display::CommonVerticalMargin/2;
  void draw(const EADK::Color c) const;
  int p_x;
  int p_y;
};

#endif
