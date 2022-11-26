#pragma once
#include "raylib.h"
#include "Player.h"

class SecondPlayer : public Player
{
private:

public:
	SecondPlayer(Vector2 position, float radius, int health);
	~SecondPlayer();
	void TakeInput() override;
	void Shoot() override;
};