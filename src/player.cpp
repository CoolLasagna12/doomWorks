#include "player.h"
#include "raycasting.h"
#include "math.h"

Player::Player() :
	playerX(160),
	playerY(111)
{

}

void Player::turn(float deg) {
	direction += deg;
	Raycasting raycasting_obj;
	raycasting_obj.changePosition(int(playerX), int(playerY), direction);
}

void Player::move(int movement) {
  Math playerMath;
  playerX += movement * playerMath.sinus(direction, false);
  playerY -= movement * playerMath.cosinus(direction);
  Raycasting raycasting_obj;
  raycasting_obj.changePosition(playerX, playerY, direction);
}
