#pragma once
#include "raylib.h"
#include "Player.h"

class FirstPlayer : public Player
{
private:
	JumpSettings jumpSettings;
	Vector2 velocity;
	Vector2 position;
	bool isDead;
	bool ascending;
	bool isGrounded;
	float radius;
	int health;

public:
	FirstPlayer(Vector2 position, float radius, int health);
	~FirstPlayer();

	//Main action selection
	void TakeInput() override;

	//Simple update
	void Move()override;

	//Game flow functions
	void Damage(int damage)override;

	//GameSetup functions
	//void ChangePosition(Vector2 position)override;

	//Jump functions
	void Jump()override;
	void HandleGravity()override;
	bool CheckFloor()override;

	//Drawing functions
	void Draw()override;

	//Getters
	Vector2 GetPosition()override;
	//float GetRadius()override;
};