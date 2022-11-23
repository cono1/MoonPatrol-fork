#include "Bullets.h"

#include <iostream>
#include <cmath>

#include "Player.h"
#include "AerealEnemy.h"

extern Enemy* aerealEnemy;
extern Player* firstPlayer;

Bullet::Bullet(Vector2 position, float speed, float radius)
{
	this->position = position;
	this->speed = speed;
	this->radius = radius;

}

Bullet::~Bullet()
{

}

void Bullet::Move()
{
	this->position.y -= speed * GetFrameTime();
}

void Bullet::Draw()
{
	DrawCircleV(this->position, this->radius, RAYWHITE);
}

void Bullet::Update(Vector2 playerPos)
{
	if (aerealEnemy->CheckCollision(firstPlayer))
	{
		this->position.y -=  100;
	} 

	if (IsKeyPressed(KEY_ENTER) && !isAlive)
	{
		this->position = playerPos;
		isAlive = true;
	}

	if (position.y < 0)
	{
		isAlive = false;
	}
}

bool Bullet::CheckCollision()
{
	double distX = static_cast<double>(this->position.x) - static_cast<double>(aerealEnemy->GetPosition().x);
	double distY = static_cast<double>(this->position.y) - static_cast<double>(aerealEnemy->GetPosition().y);

	float distance = static_cast<float>(sqrt((distX * distX) + (distY * distY)));

	if (distance <= aerealEnemy->GetRadius() + this->radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Bullet::GetStatus()
{
	if (IsKeyPressed(KEY_ENTER))
	{
		isAlive = true;
	}
	return isAlive;
}

float Bullet::GetRadius()
{
	return this->radius;
}

Vector2 Bullet::GetPosition()
{
	return this->position;
}