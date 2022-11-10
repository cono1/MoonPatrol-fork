#include "GameLoop.h"

void InitialSetup();
void Update();

void Draw();
void DrawGameVersion();

Player* player;
Enemy* lower;

bool playing = true;

void InitialSetup()
{
	playing = true;
	player = new Player({ GetScreenWidth() / 3.0f , GetScreenHeight() / 2.0f }, GetScreenHeight() / 10.0f, 3);
	lower = new Enemy(GetScreenHeight() / 20.0f, 1, -200.0f);

	lower->ChangePosition({GetScreenWidth() + 20.0f, GetScreenHeight()/2.0f});
}

void GameLoop()
{
	InitialSetup();

	while (!WindowShouldClose() && playing)
	{
		Update();
		Draw();
	}

	delete player;
	delete lower;
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

void DrawGameVersion()
{
	DrawText("Version: 0.2", 0,0, 46, RAYWHITE);
}