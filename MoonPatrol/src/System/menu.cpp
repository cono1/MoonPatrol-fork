#include "menu.h"

void StartWindow();


void ShowMenu();

void DrawMenu();
void DrawTitle(const char* text);
void DrawButtons();

void GameLoop();

void StartProgram()
{
	StartWindow();

	MenuScreen currentScreen = MenuScreen::MainMenu;

	while (!WindowShouldClose())
	{
		
		switch (currentScreen)
		{
		case MenuScreen::MainMenu:
			GameLoop();
			//ShowMenu();
			break;
		case MenuScreen::Play:
			break;
		case MenuScreen::Options:
			break;
		case MenuScreen::Credits:
			break;
		case MenuScreen::Quit:
			break;
		default:
			break;
		}
		
	}

	GameLoop();
}

void ShowMenu()
{



	DrawMenu();
}

void DrawMenu()
{
	BeginDrawing();
	ClearBackground(BLACK);
	
	DrawTitle(TextFormat("MOONPATROL"));

	DrawButtons();


	EndDrawing();
}

void DrawTitle(const char *text)
{
	DrawText(text, GetScreenWidth() / 2.0f - MeasureText(text, 46) / 2, GetScreenHeight() / 7.0f, 46, RAYWHITE);
}

void DrawButtons()
{

}

void StartWindow()
{
	int width = 1024;
	int height = 768;
		
	InitWindow(width, height, "MoonPatrol - By Ian Kuznicki");
}