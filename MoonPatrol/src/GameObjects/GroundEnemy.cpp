#include "GroundEnemy.h"

#include "raymath.h"

#include "Player.h"
#include "Enemy.h"

int spawnOffset = 10;

GroundEnemy::GroundEnemy(float radius, float damage, float speed) : Enemy(position, radius)
{
	this->radius = radius;
	this->damage = damage;
	this->speed = { speed, 0 };

	this->position = { 0,0 };
}

GroundEnemy::~GroundEnemy()
{

}

void GroundEnemy::Move()
{
	this->CheckLimits();

	Vector2 newPos;

	newPos = { this->position.x + speed.x * GetFrameTime(), this->position.y };

	this->position = newPos;
}

void GroundEnemy::ChangePosition(Vector2 newPosition)
{
	this->position = newPosition;
}

void GroundEnemy::CheckLimits()
{
	if (this->position.x <= 0)
	{
		this->position.x = static_cast<float>(GetScreenWidth() + spawnOffset);
	}
}

bool GroundEnemy::CheckCollision(Player* player)
{
	double distX = static_cast<double>(player->GetPosition().x) - static_cast<double>(this->position.x);
	double distY = static_cast<double>(player->GetPosition().y) - static_cast<double>(this->position.y);

	float distance = static_cast<float>(sqrt((distX * distX) + (distY * distY)));

	if (distance <= player->GetRadius() + this->radius)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GroundEnemy::Draw()
{
	DrawCircleV(this->position, this->radius, RAYWHITE);
}