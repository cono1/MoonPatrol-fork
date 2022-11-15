#include "GameLoop.h"

void InitialSetup();
void CreateBackgrounds();
void SortBackgrounds();

void Update();

void Draw();
void DrawBackground();
void DrawGameVersion();

Player* player;
Enemy* groundEnemy;
Bullet* bullet;

BackgroundImage* backgroundImages[8];

bool playing = true;

void InitialSetup()
{
	playing = true;

	player = new Player({ GetScreenWidth() / 3.0f , GetScreenHeight() / 2.0f }, GetScreenHeight() / 10.0f, 3);
	groundEnemy = new Enemy(GetScreenHeight() / 20.0f, 1, -200.0f);
	bullet = new Bullet(player->GetPosition(), 10, GetScreenHeight() / 40.0f, false);

	groundEnemy->ChangePosition({ GetScreenWidth() + 20.0f, GetScreenHeight() / 2.0f });

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
}

void Update()
{
	groundEnemy->Move();
	player->TakeInput();
	bullet->Update(player->GetPosition());
	if (bullet->GetStatus())
	{
		bullet->Move();
	}
	for (int i = 0; i < 8; i++)
	{
		backgroundImages[i]->Move();
	}
}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawBackground();

	player->Draw();
	groundEnemy->Draw();

	bullet->Draw();
	

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
	DrawText("Version: 0.2", 0, 0, 46, RAYWHITE);
}