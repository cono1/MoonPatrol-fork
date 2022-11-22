#pragma once
#include "raylib.h"

enum class InputType
{
	JumpSpace = KEY_SPACE,
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

private:
	//JumpSettings jumpSettings;
	
	//Vector2 velocity;
	Vector2 position;

	//bool isDead;
	//bool ascending;
	//bool isGrounded;
	float radius;
	int health;

public:
	Player(Vector2 position, float radius, int health);
	//~Player();

	//Main action selection
	virtual void TakeInput() = 0;
	
	//Simple update
	virtual void Move() = 0;

	//Game flow functions
	virtual void Damage(int damage)=0;

	//GameSetup functions
	 void ChangePosition(Vector2 position);

	//Jump functions
	virtual void Jump()=0;
	virtual void HandleGravity()=0;
	virtual bool CheckFloor()=0;
	
	//Drawing functions
	virtual void Draw()=0;

	//Getters
	virtual Vector2 GetPosition()=0;
	float GetRadius();

};