#include "FirstPlayer.h"
#include <iostream>

FirstPlayer::FirstPlayer(Vector2 position, float radius, int health) : Player(position, radius, health)
{
	this->position = position;
	this->radius = radius;
	this->health = health;
	this->color = WHITE;
	this->bullet = new Bullet(position, 1000, GetScreenHeight()/80);
}

FirstPlayer::~FirstPlayer()
{
	delete bullet;
}

void FirstPlayer::TakeInput()
{
	if (IsKeyPressed(static_cast<int>((InputType)(InputType::JumpArrow))))
	{
		if (this->jumpSettings.maxJump > 0)
		{
			this->Jump();
		}
	}

	if (IsKeyPressed(static_cast<int>((InputType)(InputType::AttackEnter))))
	{
		/*Shoot();*/
		bullet->Update(this->position);
		bullet->Move();
	}

	this->Move();
}

void FirstPlayer::Shoot()
{
	bullet->Draw();
}