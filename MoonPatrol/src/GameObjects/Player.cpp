#include "Player.h"

Player::Player(Vector2 position, float radius, int health, Color color)
{
	this->position = position;
	this->radius = radius;
	this->health = health;
	this->velocity = { 0,0 };

	this->isDead = false;
	this->ascending = false;
	this->isGrounded = true;

	this->color = color;
	shooting = false;
	this->jumpSettings.maxJump = this->jumpSettings.maxJumpDefault;
	this->jumpSettings.jumpPower = static_cast<int> (this->jumpSettings.jumpPowerDefault);
	this->jumpSettings.jumpTime = this->jumpSettings.jumpTimeDefault;
	this->jumpSettings.maxJump = this->jumpSettings.maxJumpDefault;

	this->bullet = new Bullet(position, 800, static_cast<float>(GetScreenHeight() / 80));
}

Player::~Player()
{
	delete bullet;
}

void Player::TakeInput(KeyboardKey jumpKey, KeyboardKey attackKey)
{
	if (IsKeyPressed(jumpKey))
	{
		if (this->jumpSettings.maxJump > 0)
		{
			this->Jump();
		}
	}

	if (IsKeyPressed(attackKey))
	{
		shooting = true;
	}

	if (shooting)
	{
		bullet->Move();
		bullet->Update(this->position);

		shooting = bullet->GetIsAlive();
	}
	Move();
}

void Player::Move()
{
	this->position.y += this->velocity.y * GetFrameTime();
	this->HandleGravity();
}

void Player::Damage(int damage)
{
	this->health -= damage;
	if (health <= 0)
		this->isDead = true;
}

void Player::ChangePosition(Vector2 position)
{
	this->position = position;
}

void Player::Jump()
{
	this->velocity.y = this->jumpSettings.jumpPower - this->velocity.y;
	this->jumpSettings.maxJump--;
	this->ascending = true;
	this->isGrounded = false;
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

void Player::Draw()
{
	Shoot();
	DrawCircleV(this->position, this->radius, color);
}

void Player::Shoot()
{
	bullet->Draw();
}

Vector2 Player::GetPosition()
{
	return this->position;
}

float Player::GetRadius()
{
	return this->radius;
}
