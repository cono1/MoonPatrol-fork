#include "SecondPlayer.h"

SecondPlayer::SecondPlayer(Vector2 position, float radius, int health) : Player(position, radius, health)
{
	this->position = position;
	this->radius = radius;
	this->health = health;
	this->velocity = { 0,0 };
	this->color = GREEN;
	this->bullet = new Bullet(position, 1000, GetScreenHeight() / 80);
}

SecondPlayer::~SecondPlayer()
{

}

void SecondPlayer::TakeInput()
{
	if (IsKeyPressed(static_cast<int>((InputType)(InputType::JumpW))))
	{
		if (this->jumpSettings.maxJump > 0)
		{
			this->Jump();
		}
	}

	if (IsKeyPressed(static_cast<int>((InputType)(InputType::AttackSpace))))
	{
		bullet->Update(this->position);
		bullet->Move();
	}

	this->Move();
}

void SecondPlayer::Shoot()
{
	bullet->Draw();
}