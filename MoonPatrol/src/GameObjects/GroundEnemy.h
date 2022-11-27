#pragma once
#include "Enemy.h"

class GroundEnemy : public Enemy
{
private:
	float damage;
	int spawnOffset;

public:
	GroundEnemy(float radius, float damage, float speed);
	~GroundEnemy();
	void Update() override;
	void ChangePosition(Vector2 newPosition) override;
	void CheckLimits() override;
	bool CheckCollision(Player* player) override;
	void Draw() override;
};