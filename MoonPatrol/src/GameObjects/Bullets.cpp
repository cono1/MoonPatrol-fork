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
	isAlive = false;
}

Bullet::~Bullet()
{

}

void Bullet::Move()
{
	if (!isAlive)
	{
		return;
	}
	position.y -= speed * GetFrameTime();
}

void Bullet::Draw()
{
	if (isAlive)
	{
		DrawCircleV(this->position, radius, BLACK);
	}
}

void Bullet::Update(Vector2 playerPos)
{
	if (CheckCollision())
	{
		position.y -= 100;
		std::cout << "colision";
	}

	if (!isAlive)
	{
		isAlive = true;
		position = playerPos;
	}

	if (position.y <= 0)
	{
		isAlive = false;
	}
}

bool Bullet::CheckCollision()
{

	double distX = static_cast<double>(aerealEnemy->GetPosition().x) - static_cast<double>(position.x);
	double distY = static_cast<double>(aerealEnemy->GetPosition().y) - static_cast<double>(position.y);

	double distance = (sqrt((distX * distX) + (distY * distY)));

	if (distance <= aerealEnemy->GetRadius() + this->radius)
	{
		return true;
	}
	else
	{
		return false;
	}

	//if (CheckCollisionCircles(aerealEnemy->GetPosition(), aerealEnemy->GetRadius(), position, radius));
	//{
	//	std::cout << "esta colisionando" << std::endl;
	//	return true;
	//}

	//return false;

}

bool Bullet::GetIsAlive()
{
	//if (IsKeyPressed(KEY_ENTER))
	//{
	//	isAlive = true;
	//}
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