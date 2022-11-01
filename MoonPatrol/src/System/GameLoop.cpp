#include "GameLoop.h"

void InitialSetup();
void Update();

void Draw();
void DrawGameVersion();

Player* player;
Enemy* lower;

void InitialSetup()
{
	player = new Player({ GetScreenWidth() / 3.0f , GetScreenHeight() / 2.0f }, GetScreenHeight() / 10.0f, 3);
	lower = new Enemy(GetScreenHeight() / 20.0f, 1, -200.0f);

	lower->ChangePosition({GetScreenWidth() + 20.0f, GetScreenHeight()/2.0f});
}

void GameLoop()
{
	InitialSetup();


	while (true)
	{
		Update();
		Draw();
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
	player->Draw();
	lower->Draw();



	DrawGameVersion();
	EndDrawing();
}

void DrawGameVersion()
{
	DrawText("Version: 0.1", 0,0, 46, RAYWHITE);
}