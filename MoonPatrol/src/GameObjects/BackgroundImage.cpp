#include "BackgroundImage.h"

BackgroundImage::BackgroundImage(Texture2D text, Color color, int layer)
{
	this->texture = text;
	this->color = color;
	this->layer = layer;

	this->speedX = this->speedXDefault;
	this->body = { 0,0, static_cast<float>(text.width), static_cast<float>(text.height) };
}

void BackgroundImage::ChangeSpeedX(int newSpeedX)
{
	this->speedX = newSpeedX;
}

void BackgroundImage::Move()
{
	this->body.x -= this->speedX;
}

void BackgroundImage::Reposition(Vector2 newPosition)
{
	this->body.x = newPosition.x;
	this->body.y = newPosition.y;
}

void BackgroundImage::ChangeColor(Color newColor)
{
	this->color = newColor;
}