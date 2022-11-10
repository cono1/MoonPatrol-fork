#include "System/MainMenu.h"

void DrawTitle(const char* text);

void ShowCredits(MenuScreen& currentScreen)
{
	Rectangle backButton { GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2,
		GetScreenHeight() / 2 + 20,
		GetScreenWidth() / 4,
		GetScreenHeight() / 12 };

	if (CheckButton(backButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentScreen = MenuScreen::MainMenu;
	}

	BeginDrawing();
	ClearBackground(BLACK);

	DrawTitle("CREDITS");

	DrawRectangleRec(backButton, RAYWHITE);


	EndDrawing();
}