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

	DrawText("MADE BY", GetScreenWidth() / 2 - MeasureTextEx(GetFontDefault(),"MADE BY", 36, 0).x / 2, GetScreenHeight() / 2 - GetScreenHeight() / 5, 36, RAYWHITE);
	DrawText("IAN KUZNICKI", GetScreenWidth() / 2 - MeasureTextEx(GetFontDefault(),"IAN KUZNICKI", 36, 0).x / 2, GetScreenHeight() / 2 - GetScreenHeight() / 8, 36, RAYWHITE);

	DrawRectangleRec(backButton, RAYWHITE);
	
	Vector2 backMeasure = MeasureTextEx(GetFontDefault(), "BACK", 36, 0);
	DrawText("BACK", backButton.x + backButton.width / 2 - backMeasure.x / 2, backButton.y + backButton.height / 2 - backMeasure.y / 2, 36, BLACK);

	EndDrawing();
}