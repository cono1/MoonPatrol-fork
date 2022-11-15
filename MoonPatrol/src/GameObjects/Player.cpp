#include "Player.h"

Player::Player(Vector2 position, float radius, int health)
{
	this->position = position;
	this->radius = radius;
	this->health = health;
	this->velocity = { 0,0 };

	this->isDead = false;
	this->ascending = false;
	this->isGrounded = true;

	this->jumpSettings.maxJump = this->jumpSettings.maxJumpDefault;
	this->jumpSettings.jumpPower = this->jumpSettings.jumpPowerDefault;
	this->jumpSettings.jumpTime = this->jumpSettings.jumpTimeDefault;
	this->jumpSettings.maxJump = this->jumpSettings.maxJumpDefault;
}

void Player::Damage(int damage)
{
	this->health -= damage;
	if (health <= 0)
		this->isDead = true;
}

void Player::TakeInput()
{
	InputType inputRecieved;

	inputRecieved = static_cast<InputType>(GetKeyPressed());

	switch (inputRecieved)
	{
	case InputType::Jump:
		if (this->jumpSettings.maxJump > 0)
			this->Jump();
		break;
	case InputType::Pause:
		break;
	case InputType::Quit:
		break;
	case InputType::Attack:
		break;
	default:
		break;
	}

	this->Move();
}

void Player::Jump()
{
	this->velocity.y = this->jumpSettings.jumpPower - this->velocity.y;
	this->jumpSettings.maxJump--;
	this->ascending = true;
	this->isGrounded = false;
}

void Player::Move()
{
	this->position.y += this->velocity.y * GetFrameTime();
	this->HandleGravity();
}

void Player::HandleGravity()
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

bool Player::CheckFloor()
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

void Player::ChangePosition(Vector2 position)
{
	this->position = position;
}

Vector2 Player::GetPosition()
{
	return this->position;
}

float Player::GetRadius()
{
	return this->radius;
}

void Player::Draw()
{
	DrawCircleV(this->position, this->radius, RAYWHITE);
}