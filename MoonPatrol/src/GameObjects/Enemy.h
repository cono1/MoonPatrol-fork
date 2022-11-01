#pragma once
#include "raylib.h"

class Enemy
{
private:
	Vector2 position;
	float radius;
	float damage;
	float speed;

public:
	Enemy(float radius, float damage, float speed);

	void Move();
	void DealDamage();
	void ChangePosition(Vector2 newPosition);
	void CheckLimits();
	void CheckCollision();

	void Draw();
};