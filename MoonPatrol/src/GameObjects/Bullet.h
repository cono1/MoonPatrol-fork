#pragma once
#include <raylib.h>

class Bullet
{
private:
	Vector2 position;
	Vector2 speed;

	Color color;

	float radius;

	int health;
	int damage;

public:
	Bullet();
	~Bullet();

	void Move();
	void ChangeSpeed(Vector2 speed);
	void ChangeColor(Color color);
	bool CircleCollision(Vector2 position, float radius);

	int GetHealth();
	int GetDamage();
};

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}