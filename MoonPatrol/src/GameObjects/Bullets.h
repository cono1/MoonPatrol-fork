#pragma once

#include <raylib.h>

class Bullet
{
private:
	Vector2 position;
	//Color color;
	float speed;
	float radius;

protected:

public:
	bool isAlive;
	Bullet(Vector2 position, float speed, float radius);
	~Bullet();

	void Move();
	void Draw();
	void Update(Vector2 playerPos);
	bool CheckCollision();
	bool GetStatus();
	bool GetIsAlive();
	float GetRadius();
	Vector2 GetPosition();
};


