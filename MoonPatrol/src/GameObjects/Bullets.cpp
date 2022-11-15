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
	do
	{
		this->position.y -= speed * GetFrameTime();
	} while (position.y > 0);
}

void Bullet::Draw()
{
	DrawCircleV(this->position, this->radius, RAYWHITE);
}

void Bullet::Update(Vector2 playerPos)
{
	this->position = playerPos;
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