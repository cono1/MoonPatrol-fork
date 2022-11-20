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
			if(IsKeyPressed(KEY_ESCAPE) || WindowShouldClose())
			currentScreen = MenuScreen::Quit;
			break;
		case MenuScreen::Options: 
			break;
		case MenuScreen::Credits:
			ShowCredits(currentScreen);
			break;
		case MenuScreen::Quit:
			CloseWindow();
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
	DrawText(text, GetScreenWidth() / 2.0f - MeasureText(text, 46) / 2, GetScreenHeight() / 7.0f, 48, RAYWHITE);
}

void DrawButtons(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton)
{
	DrawRectangleRec(playButton, RAYWHITE);
	Vector2 playMeasure = MeasureTextEx(GetFontDefault(), "PLAY", 36, 0);
	DrawText("PLAY", playButton.x + playButton.width / 2 - playMeasure.x / 2, playButton.y + playButton.height / 2 - playMeasure.y / 2, 36, BLACK);
	//DrawRectangleRec(optionsButton, RAYWHITE);
	Vector2 creditsMeasure = MeasureTextEx(GetFontDefault(), "CREDITS", 36, 0);
	DrawRectangleRec(creditsButton, RAYWHITE);
	DrawText("CREDITS", creditsButton.x + creditsButton.width / 2 - creditsMeasure.x / 2, creditsButton.y + creditsButton.height / 2 - creditsMeasure.y / 2, 36, BLACK);
	//DrawRectangleRec(quitButton, RAYWHITE);
}

void StartWindow()
{
	int width = 1024;
	int height = 720;

	InitWindow(width, height, "MoonPatrol - By Ian Kuznicki");
}