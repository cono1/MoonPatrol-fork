#include "BackgroundImage.h"

BackgroundImage::BackgroundImage(Texture2D text, Color color, int layer, Rectangle body)
{
	this->texture = text;
	this->color = color;
	this->layer = layer;

	switch (layer)
	{
	case 0:
		this->speedX = this->speedXReference / 5;
		break;
	case 1:
		this->speedX = this->speedXReference / 3;
		break;
	case 2:
		this->speedX = this->speedXReference / 2;
		break;
	case 3:
		this->speedX = this->speedXReference;
		break;
	default:
		break;
	}
	this->speedXReference = this->speedX;
	
	this->body = body;
}

BackgroundImage::~BackgroundImage()
{
	UnloadTexture(this->texture);
}

int BackgroundImage::GetLayer()
{
	return this->layer;
}

void BackgroundImage::ChangeSpeedX(int newSpeedX)
{
	this->speedX = newSpeedX;
}

void BackgroundImage::Move()
{
	if (this->body.x + this->body.width <= 0)
	{
		this->Reposition({ static_cast<float>(GetScreenWidth()), this->body.y });
	}
	this->body.x -= this->speedX * GetFrameTime();
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