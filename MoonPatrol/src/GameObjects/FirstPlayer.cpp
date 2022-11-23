#include "FirstPlayer.h"

FirstPlayer::FirstPlayer(Vector2 position, float radius, int health) : Player(position, radius, health)
{
	this->position = position;
	this->radius = radius;
	this->health = health;
	this->velocity = { 0,0 };

	this->isDead = false;
	this->ascending = false;
	this->isGrounded = true;

	this->jumpSettings.maxJump = this->jumpSettings.maxJumpDefault;
	this->jumpSettings.jumpPower = static_cast<int> (this->jumpSettings.jumpPowerDefault);
	this->jumpSettings.jumpTime = this->jumpSettings.jumpTimeDefault;
	this->jumpSettings.maxJump = this->jumpSettings.maxJumpDefault;
}

FirstPlayer::~FirstPlayer()
{

}

void FirstPlayer::TakeInput()
{
	if (IsKeyPressed(static_cast<int>((InputType)(InputType::JumpSpace))))
	{
		if (this->jumpSettings.maxJump > 0)
		{
			this->Jump();
		}
	}

	this->Move();
}

void FirstPlayer::Jump()
{
	this->velocity.y = this->jumpSettings.jumpPower - this->velocity.y;
	this->jumpSettings.maxJump--;
	this->ascending = true;
	this->isGrounded = false;
}

void FirstPlayer::Move()
{
	this->position.y += this->velocity.y * GetFrameTime();
	this->HandleGravity();
}

void FirstPlayer::HandleGravity()
{
	if (this->isGrounded)
		return;

	if (ascending)
	{
		if (this->jumpSettings.jumpTime <= 0)
		{
			this->velocity.y = this->jumpSettings.downForce * GetFrameTime();
			ascending = false;
		}
		else
			this->jumpSettings.jumpTime -= GetFrameTime();
	}
	else
	{
		this->isGrounded = CheckFloor();
	}
}

bool FirstPlayer::CheckFloor()
{
	//Is grounded
	if (this->position.y >= GetScreenHeight() / 2)
	{
		this->ChangePosition({ this->position.x,GetScreenHeight() / 2.0f });
		this->velocity.y = 0;

		this->jumpSettings.jumpTime = this->jumpSettings.jumpTimeDefault;
		this->jumpSettings.maxJump = this->jumpSettings.maxJumpDefault;
		return true;
	}
	else
	{
		this->velocity.y += this->jumpSettings.downForce * GetFrameTime();
		return false;
	}
}

//void FirstPlayer::ChangePosition(Vector2 position)
//{
//	this->position = position;
//}

void FirstPlayer::Damage(int damage)
{
	this->health -= damage;
	if (health <= 0)
		this->isDead = true;
}

Vector2 FirstPlayer::GetPosition()
{
	return this->position;
}

//float FirstPlayer::GetRadius()
//{
//	return this->radius;
//}

void FirstPlayer::Draw()
{
	DrawCircleV(this->position, this->radius, RAYWHITE);
}