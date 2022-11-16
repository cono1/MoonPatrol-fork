#include "GameLoop.h"

int score;

void InitialSetup();
void CreateBackgrounds();
void SortBackgrounds();

void Update();
void UpdateScore();

void Draw();
void DrawBackground();
void DrawGameVersion();
void DrawScore();

Player* player;
Enemy* groundEnemy;
Enemy* aerealEnemy;
Bullet* bullet;

BackgroundImage* backgroundImages[8];

bool playing = true;

void InitialSetup()
{
	playing = true;

	player = new Player({ GetScreenWidth() / 3.0f , GetScreenHeight() / 2.0f }, GetScreenHeight() / 10.0f, 3);
	groundEnemy = new GroundEnemy(GetScreenHeight() / 20.0f, 1, -200.0f);
	aerealEnemy = new AerealEnemy(GetScreenHeight() / 20.0f, { 10, 100 });
	bullet = new Bullet(player->GetPosition(), 1000, GetScreenHeight() / 80.0f, false);

	groundEnemy->ChangePosition({ GetScreenWidth() + 20.0f, GetScreenHeight() / 2.0f });
	aerealEnemy->ChangePosition({ static_cast<float>(GetScreenWidth() / 6), GetScreenHeight() / 4.0f });

	CreateBackgrounds();

	SortBackgrounds();
}

void CreateBackgrounds()
{
	Rectangle layer0Body = { 0,0, GetScreenWidth(), GetScreenHeight() };
	Rectangle layer1Body = { 0, 0 - GetScreenHeight() / 8, GetScreenWidth(), GetScreenHeight() };

	Rectangle layer0BodyOutOfScren = { GetScreenWidth(),0, GetScreenWidth(), GetScreenHeight() };
	Rectangle layer1BodyOutOfScren = { GetScreenWidth(), 0 - GetScreenHeight() / 8, GetScreenWidth(), GetScreenHeight() };

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

void GameLoop()
{
	InitialSetup();

	while (!WindowShouldClose() && playing)
	{
		Update();
		Draw();
	}

	if (player != nullptr)
	{
		delete player;
		player = nullptr;
	}

	if (bullet != nullptr)
	{
		delete bullet;
		bullet = nullptr;
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
}

void Update()
{
	groundEnemy->Move();
	aerealEnemy->Move();
	player->TakeInput();
	bullet->Update(player->GetPosition());
	bullet->Move();
	UpdateScore();
	
	for (int i = 0; i < 8; i++)
	{
		backgroundImages[i]->Move();
	}
}

void UpdateScore()
{
	if (aerealEnemy->CheckCollision())
	{
		score += 100;
	}
}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawBackground();

	player->Draw();
	groundEnemy->Draw();
	aerealEnemy->Draw();

	if (bullet->GetStatus())
	{
		bullet->Draw();
	}
	
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
	DrawText("Version: 0.3", 0, 0, 46, RAYWHITE);
}

void DrawScore()
{
	DrawText(TextFormat("Score: %i ", score), GetScreenWidth() - 250, 0, 46, WHITE);
}
