#pragma once
#include "raylib.h"

#include "Player.h"

class Enemy
{
protected:
	Vector2 position;
	float radius;
	Vector2 speed;
public:
	Enemy(Vector2 position, float radius);
	virtual ~Enemy();
	Vector2 GetPosition();
	float GetRadius();
	virtual void Move() = 0;
	virtual void ChangePosition(Vector2 newPosition) = 0;
	virtual void CheckLimits() = 0;
	virtual bool CheckCollision(Player* player) = 0;
	virtual void Draw() = 0;
};