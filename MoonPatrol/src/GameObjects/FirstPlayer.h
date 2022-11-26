#pragma once
#include "raylib.h"
#include "Player.h"

class FirstPlayer : public Player
{
private:

public:
	FirstPlayer(Vector2 position, float radius, int health);
	~FirstPlayer();
	void TakeInput() override;
	void Shoot() override;
};