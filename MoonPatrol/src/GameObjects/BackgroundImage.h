#pragma once
#include "raylib.h"

class BackgroundImage
{
private:

	int speedXReference = 100;

	//Could be part of another class
	Color color;
	Texture2D texture;
	int layer;

	int speedX;

	Rectangle body;

public:
	BackgroundImage(Texture2D text, Color color, int layer, Rectangle body);
	//~BackgroundImage();

	int GetLayer();

	void ChangeSpeedX(int newSpeedX);
	void Move();
	void Reposition(Vector2 newPosition);
	void ChangeColor(Color color);

	void Draw();
};