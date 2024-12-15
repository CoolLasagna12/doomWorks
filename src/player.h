#ifndef PLAYER_H
#define PLAYER_H

#include "display.h"
#include "eadkpp.h"



  class Player {
public:
  Player();
  float playerX;
  float playerY;
  void move(int x, int y);
  void turn(float deg);
  static constexpr int k_step = 5;
  float direction = 0.0;
private:
  static constexpr int k_xLowerBound = Display::CommonHorizontalMargin/2;
  static constexpr int k_xUpperBound = EADK::Screen::Width - Display::CommonHorizontalMargin/2;
  static constexpr int k_yLowerBound = Display::CommonVerticalMargin/2;
  static constexpr int k_yUpperBound = EADK::Screen::Height - Display::CommonVerticalMargin/2;
};

#endif
