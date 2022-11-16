#pragma once
#include "Enemy.h"

class AerealEnemy : public Enemy
{
private:
	Vector2 position;
	float radius;
	Vector2 speed;

public:
	AerealEnemy(float radius, Vector2 speed);
	~AerealEnemy();
	float GetRadius();
	void Move() override;
	void ChangePosition(Vector2 newPosition) override;
	void CheckLimits() override;
	bool CheckCollision() override;
	void Draw() override;
};
