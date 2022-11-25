#include "FirstPlayer.h"
#include <iostream>

FirstPlayer::FirstPlayer(Vector2 position, float radius, int health) : Player(position, radius, health)
{
	this->position = position;
	this->radius = radius;
	this->health = health;
	this->color = WHITE;
}

FirstPlayer::~FirstPlayer()
{

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

	if (IsKeyPressed(static_cast<int>((InputType)(InputType::Attack))))
	{
		//bullet->Update(this->GetPosition());
	/*	bullet->Move();
		bullet->Draw();*/
	}

	this->Move();
}