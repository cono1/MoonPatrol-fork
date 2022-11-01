#include "menu.h"

void StartWindow();


void ShowMenu();

void CheckButton(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton);

void DrawMenu(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton);
void DrawTitle(const char* text);
void DrawButtons(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton);

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
			ShowMenu();
			break;
		case MenuScreen::Play:
			//GameLoop();
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
	Rectangle playButton{ GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2,
		GetScreenHeight() / 2 + 20,
		GetScreenWidth() / 4,
		GetScreenHeight() / 12 };

	Rectangle optionsButton{ 0,0,0,0 };
	Rectangle creditsButton{ 0,0,0,0 };
	Rectangle quitButton{ 0,0,0,0 };

	CheckButton(playButton, optionsButton, creditsButton, quitButton);


	DrawMenu(playButton, optionsButton, creditsButton, quitButton);
}

void CheckButton(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton)
{
	
}

void DrawMenu(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton)
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawTitle(TextFormat("MOONPATROL"));

	DrawButtons(playButton, optionsButton, creditsButton, quitButton);


	EndDrawing();
}

void DrawTitle(const char* text)
{
	DrawText(text, GetScreenWidth() / 2.0f - MeasureText(text, 46) / 2, GetScreenHeight() / 7.0f, 46, RAYWHITE);
}

void DrawButtons(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton)
{
	DrawRectangleRec(playButton, RAYWHITE);
	//DrawRectangleRec(optionsButton, RAYWHITE);
	//DrawRectangleRec(creditsButton, RAYWHITE);
	//DrawRectangleRec(quitButton, RAYWHITE);
}

void StartWindow()
{
	int width = 1024;
	int height = 768;

	InitWindow(width, height, "MoonPatrol - By Ian Kuznicki");
}