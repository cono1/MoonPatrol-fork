#pragma once
#include "GameObjects/Enemy.h"
#include "GameObjects/Player.h"

class BackgroundImage
{
private:
	Color color;
	Texture2D sprite;
	int speedX;
	Rectangle body;
	int layer;

public:
	BackgroundImage();
	~BackgroundImage();

	void Move();
	void Reposition();
	void ChangeColor(Color color);
};


void GameLoop();