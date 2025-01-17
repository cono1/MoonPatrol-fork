#include "Bullets.h"

#include <cmath>

#include "AerealEnemy.h"

extern Enemy* aerealEnemy;

Bullet::Bullet(Vector2 position, float speed, float radius)
{
	this->position = position;
	this->speed = speed;
	this->radius = radius;
	isAlive = false;
	damage = 10;
}

Bullet::~Bullet()
{

}

void Bullet::Update()
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

void Bullet::Update(Vector2 playerPos, int& score)
{
	if (CheckCollision())
	{
		position.y -= playerPos.x;
		score += 10;
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

	return (distance <= aerealEnemy->GetRadius() + this->radius);

}

bool Bullet::GetIsAlive()
{
	return isAlive;
}

float Bullet::GetRadius()
{
	return this->radius;
}

int Bullet::GetDamage()
{
	return damage;
}

Vector2 Bullet::GetPosition()
{
	return this->position;
}