#ifndef PLAYER_H
#define PLAYER_H

#include "display.h"
#include "eadkpp.h"



  class Player {
public:
  Player();
  float playerX;
  float playerY;
  void move(int move);
  static constexpr int k_step = 5;
  static constexpr float k_turn_step = 5;
  float direction = 0.0;
  void turn(float deg);
private:
  static constexpr int k_xLowerBound = Display::CommonHorizontalMargin/2;
  static constexpr int k_xUpperBound = EADK::Screen::Width - Display::CommonHorizontalMargin/2;
  static constexpr int k_yLowerBound = Display::CommonVerticalMargin/2;
  static constexpr int k_yUpperBound = EADK::Screen::Height - Display::CommonVerticalMargin/2;
  void draw(const EADK::Color c) const;
};

#endif
