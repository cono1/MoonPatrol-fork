#include "Enemy.h"

Enemy::Enemy(Vector2 position, float radius)
{
	this->position = position;
	this->radius = radius;
}

Enemy::~Enemy()
{

}

Vector2 Enemy::GetPosition()
{
	return position;
}

float Enemy::GetRadius()
{
	return radius;
}