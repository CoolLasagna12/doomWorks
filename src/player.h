#ifndef PLAYER_H
#define PLAYER_H

#include "eadkpp.h"

class Player {
public:
	Player();
	float playerX;
	float playerY;
	void move(int movement);
	void turn(float deg);
	static constexpr int k_step = 5;
	float direction = 0.0;
private:
	bool checkInsideWall(int x, int y);
};

#endif
