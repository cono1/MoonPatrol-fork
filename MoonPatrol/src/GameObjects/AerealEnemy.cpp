#include "AerealEnemy.h"

#include <cmath>

extern Player* firstPlayer;

AerealEnemy::AerealEnemy(float radius, Vector2 speed) : Enemy(position, radius)
{
	this->radius = radius;
	this->speed = speed;
	this->hp = 20;
	this->position = { 0,0 };
}

AerealEnemy::~AerealEnemy()
{

}

float AerealEnemy::GetRadius()
{
	return this->radius;
}

void AerealEnemy::Update()
{
	this->CheckLimits();

	position.x += speed.x * GetFrameTime(); 
	position.y += speed.y * sin(position.x) * GetFrameTime();

	if (CheckCollision(firstPlayer))
	{
		hp -= firstPlayer->GetBulletDamage();
	}

	if (hp <= 0)
	{
		position = { 0,150 };
		hp = 20;
	}
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
	double distX = static_cast<double>(player->GetBulletPos().x) - static_cast<double>(this->position.x);
	double distY = static_cast<double>(player->GetBulletPos().y) - static_cast<double>(this->position.y);

	float distance = sqrt((distX * distX) + (distY * distY));

	return (distance <= player->GetBulletRadius() + this->radius);
}

void AerealEnemy::Draw()
{
	DrawCircleV(this->position, this->radius, RED);
}