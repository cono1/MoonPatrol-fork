#pragma once

#include "Enemy.h"

class GroundEnemy : public Enemy
{
private:
	Vector2 position;
	float radius;
	float damage;
	float speed;

public:
	GroundEnemy(float radius, float damage, float speed);
	~GroundEnemy();
	void Move() override;
	void ChangePosition(Vector2 newPosition) override;
	void CheckLimits() override;
	bool CheckCollision() override;
	void Draw() override;
};