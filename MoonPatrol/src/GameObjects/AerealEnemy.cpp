#include "AerealEnemy.h"

#include <cmath>

//const int maxBullets = 2;
//extern Bullet* bullet[maxBullets];

AerealEnemy::AerealEnemy(float radius, Vector2 speed) : Enemy(position, radius)
{
	this->radius = radius;
	this->speed = speed;

	this->position = { 0,0 };
}

AerealEnemy::~AerealEnemy()
{

}

float AerealEnemy::GetRadius()
{
	return this->radius;
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

bool AerealEnemy::CheckCollision(Player* player)
{
	//for (int i = 0; i < maxBullets; i++)
	//{
	//	double distX = static_cast<double>(bullet[i]->GetPosition().x) - static_cast<double>(this->position.x);
	//	double distY = static_cast<double>(bullet[i]->GetPosition().y) - static_cast<double>(this->position.y);

	//	float distance = sqrt((distX * distX) + (distY * distY));

	//	if (distance <= bullet[i]->GetRadius() + this->radius)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		return false;
	//	}
	//}
		return false;// (?
}

void AerealEnemy::Draw()
{
	DrawCircleV(this->position, this->radius, YELLOW);
}