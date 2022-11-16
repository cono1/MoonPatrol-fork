#include "AerealEnemy.h"

#include <cmath>

#include "Bullets.h"

extern Bullet* bullet;

AerealEnemy::AerealEnemy(float radius, Vector2 speed) : Enemy()
{
	this->radius = radius;
	this->speed = speed;

	this->position = { 0,0 };
}

AerealEnemy::~AerealEnemy()
{

}

void AerealEnemy::Move()
{
	this->CheckLimits();

	position.x += speed.x * GetFrameTime(); 
	position.y += speed.y * sin(position.x) * GetFrameTime(); 

}

void AerealEnemy::ChangePosition(Vector2 newPosition)
{
	this->position = newPosition;
}

void AerealEnemy::CheckLimits()
{
	if (this->position.x > GetScreenWidth())
	{
		this->position.x = 0;
	}
}

bool AerealEnemy::CheckCollision()
{
	double distX = static_cast<double>(bullet->GetPosition().x) - static_cast<double>(this->position.x);
	double distY = static_cast<double>(bullet->GetPosition().y) - static_cast<double>(this->position.y);

	float distance = sqrt((distX * distX) + (distY * distY));

	if (distance <= bullet->GetRadius() + this->radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AerealEnemy::Draw()
{
	DrawCircleV(this->position, this->radius, YELLOW);
}