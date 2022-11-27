#pragma once
#include "Enemy.h"

class AerealEnemy : public Enemy
{
private:
	float hp;

public:
	AerealEnemy(float radius, Vector2 speed);
	~AerealEnemy();
	float GetRadius();
	void Update() override;
	void ChangePosition(Vector2 newPosition) override;
	void CheckLimits() override;
	bool CheckCollision(Player* player) override;
	void Draw() override;
};
