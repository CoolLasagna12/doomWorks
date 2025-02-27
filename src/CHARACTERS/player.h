#ifndef PLAYER_H
#define PLAYER_H

#include "../EADK/eadkpp.h"

class Player {
public:
	float playerX = 160.0f;
	float playerY = 111.0f;
	void move(int movement);
	void turn(float deg);
	static constexpr int k_step = 5;
	float playerDirection = 0.0f;
private:
	bool checkInsideWall(int x, int y);
};

#endif
