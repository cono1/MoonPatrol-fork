#include "GameLoop.h"

void InitialSetup();
void Update();

void Draw();
void DrawBackground();
void DrawGameVersion();

Player* player;
Enemy* lower;

BackgroundImage* backgroundImages[4];
BackgroundImage* forestLight;
BackgroundImage* forestMiddle;
BackgroundImage* forestFront;

bool playing = true;

void InitialSetup()
{

	playing = true;

	player = new Player({ GetScreenWidth() / 3.0f , GetScreenHeight() / 2.0f }, GetScreenHeight() / 10.0f, 3);
	lower = new Enemy(GetScreenHeight() / 20.0f, 1, -200.0f);

	lower->ChangePosition({ GetScreenWidth() + 20.0f, GetScreenHeight() / 2.0f });

	backgroundImages[0] = new BackgroundImage(LoadTexture("textures/forest-back0.png"), RAYWHITE, 0);
	backgroundImages[1] = new BackgroundImage(LoadTexture("textures/forest-light1.png"), RAYWHITE, 1);
	backgroundImages[2] = new BackgroundImage(LoadTexture("textures/forest-middle2.png"), RAYWHITE, 2);
	backgroundImages[3] = new BackgroundImage(LoadTexture("textures/forest-front3.png"), RAYWHITE, 3);
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

	if (lower != nullptr)
	{
		delete lower;
		lower = nullptr;
	}
}

void Update()
{
	lower->Move();
	player->TakeInput();
}

void Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawBackground();

	player->Draw();
	lower->Draw();

	DrawGameVersion();
	EndDrawing();
}

void DrawBackground()
{
	for (int i = 0; i < 4; i++)
	{	//CAMBIALE EL TAMAÑO A LOS FONDOS Y VAS ACHICANDOLOS,. EL ULTIMO DEJALO A MAX WIDTH PERO LOS OTROS ANDÁ ALEJANDOLOS
		backgroundImages[i]->Draw();
	}
}

void DrawGameVersion()
{
	DrawText("Version: 0.2", 0, 0, 46, RAYWHITE);
}