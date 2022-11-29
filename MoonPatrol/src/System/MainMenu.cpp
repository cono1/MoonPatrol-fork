#include "MainMenu.h"

#include "CreditsMenu.h"
#include "HowToPlayMenu.h"
#include "OptionsMenu.h"

void StartWindow();

void ShowMenu(MenuScreen& currentScreen);
void DrawMenu(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton, Rectangle howToPlayButton);
void DrawTitle(const char* text);
void DrawButtons(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton, Rectangle howToPlayButton);

void GameLoop(bool onePlayer);

void StartProgram()
{
	StartWindow();

	MenuScreen currentScreen = MenuScreen::MainMenu;
	bool onePlayer = true;

	while (!WindowShouldClose())
	{
		switch (currentScreen)
		{
		case MenuScreen::MainMenu:
			ShowMenu(currentScreen);
			break;
		case MenuScreen::Play:
			GameLoop(onePlayer);
			currentScreen = MenuScreen::MainMenu;
			break;
		case MenuScreen::Options: 
			ShowOptions(currentScreen, onePlayer);
			break;
		case MenuScreen::Credits:
			ShowCredits(currentScreen);
			break;
		case MenuScreen::Quit:
			CloseWindow();
			break;
		case MenuScreen::HowToPlay:
			ShowHowToPlay(currentScreen);
			break;
		default:
			break;
		}
	}
}

void ShowMenu(MenuScreen& currentScreen)
{
	Rectangle playButton{ static_cast<float>(GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2),
		static_cast<float> (GetScreenHeight() / 2 + 20),
		static_cast<float> (GetScreenWidth() / 4 + 20),
		static_cast<float> (GetScreenHeight() / 12) };

	Rectangle optionsButton{ static_cast<float>(GetScreenWidth() - GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2),
		static_cast<float> (GetScreenHeight() / 2 + 20),
		static_cast<float> (GetScreenWidth() / 4 + 20),
		static_cast<float> (GetScreenHeight() / 12) };

	Rectangle creditsButton{ static_cast<float> (GetScreenWidth() - GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2),
		static_cast<float> (GetScreenHeight() / 2 + 150),
		static_cast<float> (GetScreenWidth() / 4 + 20),
		static_cast<float> (GetScreenHeight() / 12) };

	Rectangle quitButton{ 0,0,0,0 };

	Rectangle howToPlayButton{ static_cast<float>(GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2),
		static_cast<float> (GetScreenHeight() / 2 + 150),
		static_cast<float> (GetScreenWidth() / 4 + 20),
		static_cast<float> (GetScreenHeight() / 12) };


	if (CheckButton(playButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT) || IsKeyPressed(KEY_ENTER))
	{
		currentScreen = MenuScreen::Play;
	}
	else if (CheckButton(optionsButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentScreen = MenuScreen::Options;
	}
	else if (CheckButton(creditsButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentScreen = MenuScreen::Credits;
	}
	else if (CheckButton(quitButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{

	}
	else if (CheckButton(howToPlayButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentScreen = MenuScreen::HowToPlay;
	}

	DrawMenu(playButton, optionsButton, creditsButton, quitButton, howToPlayButton);
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

void DrawMenu(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton, Rectangle howToPlayButton)
{
	BeginDrawing();
	ClearBackground(BLACK);

	DrawTitle(TextFormat("MOONPATROL"));
	DrawButtons(playButton, optionsButton, creditsButton, quitButton, howToPlayButton);

	EndDrawing();
}

void DrawTitle(const char* text)
{
	DrawText(text, static_cast<int> (GetScreenWidth() / 2.0f - MeasureText(text, 60) / 2), static_cast<int> (GetScreenHeight() / 4.0f), 60, GREEN);
}

void DrawButtons(Rectangle playButton, Rectangle optionsButton, Rectangle creditsButton, Rectangle quitButton, Rectangle howToPlayButton)
{
	DrawRectangleRec(playButton, RAYWHITE);
	Vector2 playMeasure = MeasureTextEx(GetFontDefault(), "PLAY", 36, 0);
	DrawText("PLAY", static_cast<int> (playButton.x + playButton.width / 2 - playMeasure.x / 2), static_cast<int> (playButton.y + playButton.height / 2 - playMeasure.y / 2), 36, BLACK);
	
	DrawRectangleRec(optionsButton, RAYWHITE);
	Vector2 optionsMeasure = MeasureTextEx(GetFontDefault(), "OPTIONS", 36, 0);
	DrawText("OPTIONS", static_cast<int> (optionsButton.x + optionsButton.width / 2 - optionsMeasure.x / 2), static_cast<int> (optionsButton.y + optionsButton.height / 2 - optionsMeasure.y / 2), 36, BLACK);

	DrawRectangleRec(creditsButton, RAYWHITE);
	Vector2 creditsMeasure = MeasureTextEx(GetFontDefault(), "CREDITS", 36, 0);
	DrawText("CREDITS", static_cast<int> (creditsButton.x + creditsButton.width / 2 - creditsMeasure.x / 2), static_cast<int> (creditsButton.y + creditsButton.height / 2 - creditsMeasure.y / 2), 36, BLACK);
	//DrawRectangleRec(quitButton, RAYWHITE);

	DrawRectangleRec(howToPlayButton, RAYWHITE);
	Vector2 howToPlayMeasure = MeasureTextEx(GetFontDefault(), "HOW TO PLAY--", 36, 0);
	DrawText("HOW TO PLAY", static_cast<int> (howToPlayButton.x + howToPlayButton.width / 2 - howToPlayMeasure.x / 2), static_cast<int> (howToPlayButton.y + howToPlayButton.height / 2 - howToPlayMeasure.y / 2), 36, BLACK);
}

void StartWindow()
{
	int width = 1024;
	int height = 720;

	InitWindow(width, height, "MoonPatrol - By Ian Kuznicki  -  Daniela Gonzalez");
}