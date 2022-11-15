#include "Bullets.h"
#include "Player.h"

Bullet::Bullet(Vector2 position, float speed, float radius, bool isAlive)
{
	this->position = position;
	this->speed = speed;
	this->radius = radius;
	this->isAlive = isAlive;
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

bool Bullet::CheckCollision(Vector2 position, float radius)
{
	return true;
}

bool Bullet::GetStatus()
{
	if (IsKeyPressed(KEY_ENTER))
	{
		isAlive = true;
	}
	return isAlive;
}