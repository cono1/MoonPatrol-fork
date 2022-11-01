#include "Player.h"
#include "Enemy.h"

extern Player* player;

int spawnOffset = 10;

Enemy::Enemy(float radius, float damage, float speed)
{
	this->radius = radius;
	this->damage = damage;
	this->speed = speed;

	this->position = { 0,0 };
}

void Enemy::ChangePosition(Vector2 newPosition)
{
	this->position = newPosition;
}

void Enemy::Move()
{
	Vector2 newPos;

	newPos = { this->position.x + speed * GetFrameTime(), this->position.y };

	this->position = newPos;
}

void Enemy::DealDamage()
{

}

void Enemy::CheckLimits()
{
	if (this->position.x <= 0)
	{
		this->position.x = GetScreenWidth() + spawnOffset;
	}
}

void Enemy::CheckCollision()
{
	
}

void Enemy::Draw()
{
	DrawCircleV(this->position, this->radius, RAYWHITE);
}