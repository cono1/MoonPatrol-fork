#pragma once
#include "raylib.h"

class Enemy
{
public:
	Enemy();
	virtual ~Enemy();
	virtual void Move() = 0;
	virtual void ChangePosition(Vector2 newPosition) = 0;
	virtual void CheckLimits() = 0;
	virtual bool CheckCollision() = 0;
	virtual void Draw() = 0;
};