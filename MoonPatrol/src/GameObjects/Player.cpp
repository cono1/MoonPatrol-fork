#include "Player.h"



Player::Player(Vector2 position, float radius, int lifes)
{
	this->position = position;
	this->radius = radius;
	this->lifes = lifes;
}

void Player::ChangePosition(Vector2 position)
{
	this->position = position;
}

void Player::LoseLife()
{
	this->lifes--;
}

void Player::Draw()
{
	DrawCircleV(this->position, this->radius, RAYWHITE);
}