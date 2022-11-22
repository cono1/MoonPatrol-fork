#pragma once
#include "raylib.h"
#include "Player.h"

class SecondPlayer : public Player
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
	SecondPlayer(Vector2 position, float radius, int health);
	~SecondPlayer();
	void TakeInput() override;
	void Move()override;
	void Damage(int damage)override;
	void Jump()override;
	void HandleGravity()override;
	bool CheckFloor()override;
	void Draw()override;
	Vector2 GetPosition()override;
};