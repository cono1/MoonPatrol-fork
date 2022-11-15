#pragma once
#include "raylib.h"
#include "Bullet.h"

enum class InputType
{
	Jump = KEY_SPACE,
	Pause = KEY_P,
	Quit = KEY_Q,
	Attack = KEY_ENTER
};

struct JumpSettings
{
	int jumpPower;
	float jumpTime;
	int maxJump;
	float downForce = 160.0f;
	float jumpTimeDefault = 0.5f;
	float jumpPowerDefault = -500.0f;
	int maxJumpDefault = 1;
};

class Player
{

private:
	
	Bullet bullets[20];

	JumpSettings jumpSettings;
	
	Vector2 velocity;
	Vector2 position;

	bool isDead;
	bool ascending;
	bool isGrounded;
	float radius;
	int health;
	

public:
	Player(Vector2 position, float radius, int health);
	//~Player();

	//Main action selection
	void TakeInput();
	
	//Simple update
	void Move();

	//Game flow functions
	void Damage(int damage);
	void Kill();

	//GameSetup functions
	void ChangePosition(Vector2 position);

	//Jump functions
	void Jump();
	void HandleGravity();
	bool CheckFloor();
	
	//Drawing functions
	void Draw();

	//Getters
	Vector2 GetPosition();
	float GetRadius();

};