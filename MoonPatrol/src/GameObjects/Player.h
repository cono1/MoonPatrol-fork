#pragma once
#include "raylib.h"

#include "Bullets.h"

enum class InputType
{
	JumpW = KEY_W,
	JumpArrow = KEY_UP,
	Pause = KEY_P,
	Quit = KEY_Q,
	AttackEnter = KEY_ENTER,
	AttackSpace = KEY_SPACE
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

	bool shooting;

public:
	Bullet* bullet;
	Player(Vector2 position, float radius, int health, Color color);
	~Player();

	//Main action selection
	void TakeInput(KeyboardKey jumpKey, KeyboardKey attackKey, int& score);
	
	//Simple update
	void Update();

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
	void Shoot();

	//Getters
	Vector2 GetPosition();
	Vector2 GetBulletPos();
	float GetBulletRadius();
	float GetRadius();
	int GetBulletDamage();
};