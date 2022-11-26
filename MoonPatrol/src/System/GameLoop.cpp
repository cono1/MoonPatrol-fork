#include <iostream>
#include "GameLoop.h"

const int maxBullets = 2;
int score;

void InitialSetup();
void CreateBackgrounds();
void SortBackgrounds();

void Update(bool onePlayer);
void UpdateScore();

void Draw(bool onePlayer);
void DrawBackground();
void DrawGameVersion();
void DrawScore();
void ShowLoseScreen();

Player* firstPlayer;
Player* secondPlayer;
Enemy* groundEnemy;
Enemy* aerealEnemy;
//Bullet* bullet[maxBullets];
//Bullet* bullet;
BackgroundImage* backgroundImages[8];

bool playing = true;

void InitialSetup()
{
	playing = true;
	score = 0;
	firstPlayer = new FirstPlayer({ GetScreenWidth() / 3.0f , GetScreenHeight() / 2.0f }, GetScreenHeight() / 10.0f, 3);
	secondPlayer = new SecondPlayer({ GetScreenWidth() / 4.0f , GetScreenHeight() / 2.0f }, GetScreenHeight() / 10.0f, 3);
	groundEnemy = new GroundEnemy(GetScreenHeight() / 20.0f, 1, -200.0f);
	aerealEnemy = new AerealEnemy(GetScreenHeight() / 20.0f, { 25, 250 });
	//bullet = new Bullet(firstPlayer->GetPosition(), 1000, GetScreenHeight() / 80.0f);

	groundEnemy->ChangePosition({ GetScreenWidth() + 20.0f, GetScreenHeight() / 2.0f });
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

	while (!WindowShouldClose() && playing)
	{
		Update(onePlayer);
		Draw(onePlayer);
	}

	while (!playing)
	{
		ShowLoseScreen();
		if (IsKeyPressed(KEY_ENTER))
		{
			InitialSetup();
			playing = true;
		}

		if (IsKeyPressed(KEY_ESCAPE) || WindowShouldClose())
		{
			CloseWindow();
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

	//for (int i = 0; i < maxBullets; i++)
	//{
	//	if (bullet[i] != nullptr)
	//	{
	//		delete bullet[i];
	//		bullet[i] = nullptr;
	//	}
	//}

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
}

void Update(bool onePlayer)
{
	if (!onePlayer)
	{
		secondPlayer->TakeInput();

		/*bullet[1]->Update(secondPlayer->GetPosition());
		bullet[1]->Move();*/
		if (groundEnemy->CheckCollision(secondPlayer))
		{
			playing = false;
		}
	}

	firstPlayer->TakeInput();
	groundEnemy->Move();
	aerealEnemy->Move();

	//if (IsKeyPressed(static_cast<int>((InputType)(InputType::Attack))))
	//{
		//bullet->Update(firstPlayer->GetPosition());
		//bullet->Move();
	//}
	//UpdateScore();
	
	for (int i = 0; i < 8; i++)
	{
		backgroundImages[i]->Move();
	}

	if (groundEnemy->CheckCollision(firstPlayer))
	{
		playing = false;
	}
}

void UpdateScore()
{
	if (aerealEnemy->CheckCollision(firstPlayer))
	{
		score += 10;
	}
}

void Draw(bool onePlayer)
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawBackground();

	if (!onePlayer)
	{
		secondPlayer->Draw();
		secondPlayer->Shoot();
	}

	firstPlayer->Draw();
	firstPlayer->Shoot();
	groundEnemy->Draw();
	aerealEnemy->Draw();


	//if (bullet[1]->GetIsAlive() && !onePlayer)
	//{
	//	bullet[1]->Draw();
	//}
	
	DrawScore();

	DrawGameVersion();
	EndDrawing();
}

void DrawBackground()
{
	for (int i = 0; i < 8; i++)
	{	//CAMBIALE EL TAMAÑO A LOS FONDOS Y VAS ACHICANDOLOS,. EL ULTIMO DEJALO A MAX WIDTH PERO LOS OTROS ANDÁ ALEJANDOLOS
		backgroundImages[i]->Draw();
	}
	DrawRectangle(0, GetScreenHeight() - GetScreenHeight() / 4, GetScreenWidth(), GetScreenHeight() / 4, DARKGREEN);
}

void DrawGameVersion()
{
	DrawText("Version: 0.4", 0, 0, 46, RAYWHITE);
}

void DrawScore()
{
	DrawText(TextFormat("Score: %i ", score), GetScreenWidth() - 250, 0, 46, WHITE);
}

void ShowLoseScreen()
{
	BeginDrawing();
	ClearBackground(BLACK);
	DrawBackground();
	DrawText("You lost", GetScreenWidth() / 4, GetScreenHeight() / 4, 100, WHITE);
	DrawText(TextFormat("Your score was: %i ", score), GetScreenWidth() / 6, GetScreenHeight() / 2, 80, WHITE);
	DrawText("Press enter to play again", GetScreenWidth() / 4, GetScreenHeight() - 110, 40, WHITE);
	DrawText("Press esc to close game", GetScreenWidth() / 4, GetScreenHeight() - 70, 40, WHITE);
	EndDrawing();
}
