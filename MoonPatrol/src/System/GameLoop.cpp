#include <iostream>

#include "GameLoop.h"

int score;
int maxScore;

void InitialSetup();
void CreateBackgrounds();
void SortBackgrounds();

void Update(bool onePlayer);

void Draw(bool onePlayer);
void DrawBackground();
void DrawGameVersion();
void DrawScore();
void ShowFinalMessage();

Player* firstPlayer;
Player* secondPlayer;
Enemy* groundEnemy;
Enemy* aerealEnemy;
BackgroundImage* backgroundImages[8];

bool playing = true;

void InitialSetup()
{
	playing = true;
	score = 0;
	maxScore = 150;
	firstPlayer = new Player({ GetScreenWidth() / 3.0f , static_cast<float>(GetScreenHeight()-200) }, GetScreenHeight() / 10.0f, 3, MAGENTA);
	secondPlayer = new Player({ GetScreenWidth() / 4.0f ,  static_cast<float>(GetScreenHeight()-200) }, GetScreenHeight() / 10.0f, 3, GREEN);
	groundEnemy = new GroundEnemy(GetScreenHeight() / 20.0f, 1, -200.0f);
	aerealEnemy = new AerealEnemy(GetScreenHeight() / 20.0f, { 25, 250 });

	groundEnemy->ChangePosition({ GetScreenWidth() + 20.0f, static_cast<float>(GetScreenHeight() - 200) });
	aerealEnemy->ChangePosition({ static_cast<float>(GetScreenWidth() / 6), GetScreenHeight() / 4.0f });

	CreateBackgrounds();
	SortBackgrounds();
}

void CreateBackgrounds()
{
	Rectangle layer0Body = { 0,0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
	Rectangle layer1Body = { 0, static_cast < float>(0 - GetScreenHeight() / 8), static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };

	Rectangle layer0BodyOutOfScren = { static_cast<float>(GetScreenWidth()),0, static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
	Rectangle layer1BodyOutOfScren = { static_cast<float>(GetScreenWidth()), static_cast < float>(0 - GetScreenHeight() / 8), static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };

	backgroundImages[0] = new BackgroundImage(LoadTexture("textures/forest-back0.png"), RAYWHITE, 0, layer0Body);
	backgroundImages[1] = new BackgroundImage(LoadTexture("textures/forest-light1.png"), RAYWHITE, 1, layer1Body);
	backgroundImages[2] = new BackgroundImage(LoadTexture("textures/forest-middle2.png"), RAYWHITE, 2, layer1Body);
	backgroundImages[3] = new BackgroundImage(LoadTexture("textures/forest-front3.png"), RAYWHITE, 3, layer1Body);

	backgroundImages[4] = new BackgroundImage(LoadTexture("textures/forest-back0.png"), RAYWHITE, 0, layer0BodyOutOfScren);
	backgroundImages[5] = new BackgroundImage(LoadTexture("textures/forest-light1.png"), RAYWHITE, 1, layer1BodyOutOfScren);
	backgroundImages[6] = new BackgroundImage(LoadTexture("textures/forest-middle2.png"), RAYWHITE, 2, layer1BodyOutOfScren);
	backgroundImages[7] = new BackgroundImage(LoadTexture("textures/forest-front3.png"), RAYWHITE, 3, layer1BodyOutOfScren);
}

void SortBackgrounds()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = i+1; j < 8; j++)
		{
			if (backgroundImages[i]->GetLayer() > backgroundImages[j]->GetLayer())
			{
				BackgroundImage* temp = backgroundImages[i];
				backgroundImages[i] = backgroundImages[j];
				backgroundImages[j] = temp;
			}
		}
	}
}

void GameLoop(bool onePlayer)
{
	InitialSetup();

	bool pause = false;

	while (!WindowShouldClose() && playing)
	{
		if (IsKeyPressed(KEY_P))
		{
			pause = !pause;
		}
		if (!pause)
		{

			Update(onePlayer);
			Draw(onePlayer);

			if (IsKeyPressed(KEY_M))
			{
				break;
			}

			if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose())
			{
				CloseWindow();
			}
		}
	}

	while (!playing && !WindowShouldClose())
	{
		ShowFinalMessage();

		if (IsKeyPressed(KEY_ENTER))
		{
			InitialSetup();
			playing = true;
		}

		if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose())
		{
			CloseWindow();
		}

		if (IsKeyPressed(KEY_M))
		{
			break;
		}
	}
	
	if (firstPlayer != nullptr)
	{
		delete firstPlayer;
		firstPlayer = nullptr;
	}

	if (secondPlayer != nullptr)
	{
		delete firstPlayer;
		firstPlayer = nullptr;
	}

	if (groundEnemy != nullptr)
	{
		delete groundEnemy;
		groundEnemy = nullptr;
	}

	if (aerealEnemy != nullptr)
	{
		delete aerealEnemy;
		aerealEnemy = nullptr;
	}

	for (int i = 0; i < 8; i++)
	{
		if (backgroundImages[i] != nullptr)
		{
			delete backgroundImages[i];
			backgroundImages[i] = nullptr;
		}
	}
}

void Update(bool onePlayer)
{
	if (!onePlayer)
	{
		secondPlayer->TakeInput(KEY_W, KEY_SPACE, score);

		if (groundEnemy->CheckCollision(secondPlayer))
		{
			playing = false;
		}
	}

	firstPlayer->TakeInput(KEY_UP, KEY_ENTER, score);
	groundEnemy->Update();
	aerealEnemy->Update();
	
	for (int i = 0; i < 8; i++)
	{
		backgroundImages[i]->Move();
	}

	if (groundEnemy->CheckCollision(firstPlayer) || score > maxScore)
	{
		playing = false;
	}
}

void Draw(bool onePlayer)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawBackground();

	DrawText("M to open menu", GetScreenWidth() / 3, 0, 30, WHITE);

	if (!onePlayer)
	{
		secondPlayer->Draw();
	}

	firstPlayer->Draw();
	groundEnemy->Draw();
	aerealEnemy->Draw();
	
	DrawScore();

	DrawGameVersion();
	EndDrawing();
}

void DrawBackground()
{
	for (int i = 0; i < 8; i++)
	{	
		backgroundImages[i]->Draw();
	}
	DrawRectangle(0, GetScreenHeight() - GetScreenHeight() / 4, GetScreenWidth(), GetScreenHeight() / 4, DARKGREEN);
}

void DrawGameVersion()
{
	DrawText("Version: 1.0", 0, 0, 46, RAYWHITE);
}

void DrawScore()
{
	DrawText(TextFormat("Score: %i ", score), GetScreenWidth() - 250, 0, 46, WHITE);
}

void ShowFinalMessage()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawBackground();
	if (score < maxScore)
	{
		DrawText("You lost", GetScreenWidth() / 4, GetScreenHeight() / 4, 100, WHITE);
		DrawText(TextFormat("Your score was: %i ", score), GetScreenWidth() / 6, GetScreenHeight() / 2, 80, WHITE);
		DrawText("Press ENTER to play again", GetScreenWidth() / 4, GetScreenHeight() - 150, 40, WHITE);
		DrawText("Press M to go back to menu", GetScreenWidth() / 4, GetScreenHeight() - 110, 40, WHITE);
		DrawText("Press ESC to close game", GetScreenWidth() / 4, GetScreenHeight() - 70, 40, WHITE);
	}	
	else if (score >= maxScore)
	{
		DrawText("You reached\nthe max score!", GetScreenWidth() / 5, GetScreenHeight() / 4, 100, WHITE);
		DrawText(TextFormat("  Your score was: %i ", score), GetScreenWidth() / 5, GetScreenHeight() - 250, 60, WHITE);
		DrawText("Press ENTER to play again", GetScreenWidth() / 4, GetScreenHeight() - 150, 40, WHITE);
		DrawText("Press M to go back to menu", GetScreenWidth() / 4, GetScreenHeight() - 110, 40, WHITE);
		DrawText("Press ESC to close game", GetScreenWidth() / 4, GetScreenHeight() - 70, 40, WHITE);
	}
	EndDrawing();
}
