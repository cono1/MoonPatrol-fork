#pragma once
#include "raylib.h"
#include "Bullets.h"


enum class InputType
{
	JumpW = KEY_W,
	JumpArrow = KEY_UP,
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
protected:
	JumpSettings jumpSettings;
	
	Vector2 velocity;
	Vector2 position;
	
	bool isDead;
	bool ascending;
	bool isGrounded;
	float radius;
	int health;
	Color color;

	Bullet* bullet;

public:
	Player(Vector2 position, float radius, int health);
	//~Player();

	//Main action selection
	virtual void TakeInput() = 0;
	
	//Simple update
	void Move();

	//Game flow functions
	void Damage(int damage);

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