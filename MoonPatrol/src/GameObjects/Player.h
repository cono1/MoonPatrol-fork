#pragma once
#include "raylib.h"

class Player
{

private:

	Vector2 position;
	float radius;

	int lifes;

public:
	Player(Vector2 position, float radius, int lifes);
	//~Player();

	void ChangePosition(Vector2 position);
	void LoseLife();

	void Draw();
};
