#pragma once
#include "raylib.h"

class Bullet
{
private:
	Vector2 position;
	float speed;
	float radius;

protected:

public:
	bool isAlive;
	Bullet(Vector2 position, float speed, float radius);
	~Bullet();

	void Update();
	void Draw();
	void Update(Vector2 playerPos, int& score);
	bool CheckCollision();
	bool GetIsAlive();
	float GetRadius();
	Vector2 GetPosition();
};