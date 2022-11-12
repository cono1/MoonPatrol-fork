#include "BackgroundImage.h"

BackgroundImage::BackgroundImage(Texture2D text, Color color, int layer)
{
	this->texture = text;
	this->color = color;
	this->layer = layer;

	this->speedX = this->speedXDefault;
	this->body = { 0,0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
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

void BackgroundImage::Draw()
{
	DrawTexturePro(this->texture, { 0,0, static_cast<float>(this->texture.width), static_cast<float>(this->texture.height) }, this->body, { 0,0 }, 0.0f, RAYWHITE);
	//DrawTextureRec(this->texture, this->body, { this->body.x, this->body.y }, RAYWHITE);
}