#pragma once
#include "raylib.h"

class BackgroundImage
{
private:

	const int speedXDefault = 5;

	//Could be part of another class
	Color color;
	Texture2D texture;
	int layer;

	int speedX;

	Rectangle body;

public:
	BackgroundImage(Texture2D text, Color color, int layer);
	//~BackgroundImage();

	void ChangeSpeedX(int newSpeedX);
	void Move();
	void Reposition(Vector2 newPosition);
	void ChangeColor(Color color);
};