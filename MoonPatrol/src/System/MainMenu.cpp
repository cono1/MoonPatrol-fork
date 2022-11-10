#include "MainMenu.h"

void StartWindow();


void ShowMenu(MenuScreen& currentScreen);

void ShowCredits(MenuScreen& currentScreen);

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
			ShowMenu(currentScreen);
			break;
		case MenuScreen::Play:
			GameLoop();
			currentScreen = MenuScreen::MainMenu;
			break;
		case MenuScreen::Options:
			break;
		case MenuScreen::Credits:
			ShowCredits(currentScreen);
			break;
		case MenuScreen::Quit:
			break;
		default:
			break;
		}

	}
}

void ShowMenu(MenuScreen& currentScreen)
{
	Rectangle playButton{ GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2,
		GetScreenHeight() / 2 + 20,
		GetScreenWidth() / 4,
		GetScreenHeight() / 12 };

	Rectangle optionsButton{ 0,0,0,0};

	Rectangle creditsButton{ GetScreenWidth() - GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2,
		GetScreenHeight() / 2 + 20,
		GetScreenWidth() / 4,
		GetScreenHeight() / 12 };
	
	Rectangle quitButton{ 0,0,0,0 };

	if (CheckButton(playButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentScreen = MenuScreen::Play;
	}
	else if (CheckButton(optionsButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{

	}
	else if (CheckButton(creditsButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentScreen = MenuScreen::Credits;
	}
	else if (CheckButton(quitButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{

	}

	DrawMenu(playButton, optionsButton, creditsButton, quitButton);
}

bool CheckButton(Rectangle button)
{
	if (GetMouseX() >= button.x &&
		GetMouseX() <= button.x + button.width &&
		GetMouseY() >= button.y &&
		GetMouseY() <= button.y + button.height)
	{
		return true;
	}

	return false;
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
	DrawRectangleRec(creditsButton, RAYWHITE);
	//DrawRectangleRec(quitButton, RAYWHITE);
}

void StartWindow()
{
	int width = 1024;
	int height = 768;

	InitWindow(width, height, "MoonPatrol - By Ian Kuznicki");
}