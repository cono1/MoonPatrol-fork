#include "System/MainMenu.h"

void DrawTitle(const char* text);

void ShowCredits(MenuScreen& currentScreen)
{
	Rectangle backButton { static_cast<float>(GetScreenWidth() / 4) - static_cast<float>(GetScreenWidth() / 4 / 2),
		static_cast<float>(GetScreenHeight() / 2 + 20),
		static_cast<float>(GetScreenWidth() / 4),
		static_cast<float>(GetScreenHeight() / 12) };

	if (CheckButton(backButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentScreen = MenuScreen::MainMenu;
	}

	BeginDrawing();
	ClearBackground(BLACK);

	DrawTitle("CREDITS");

	DrawText("MADE BY", static_cast<int>(GetScreenWidth() / 2 - MeasureTextEx(GetFontDefault(),"MADE BY", 25, 0).x / 2), static_cast<int>(GetScreenHeight() / 2 - GetScreenHeight() / 6), 25, RAYWHITE);
	DrawText("IAN KUZNICKI", static_cast<int>(GetScreenWidth() / 2 - MeasureTextEx(GetFontDefault(), "IAN KUZNICKI", 36, 0).x / 2), static_cast<int>(GetScreenHeight() / 2 - GetScreenHeight() / 8), 36, RAYWHITE);
	DrawText("DANIELA GONZALEZ", static_cast<int>(GetScreenWidth() / 2 - MeasureTextEx(GetFontDefault(),"DANIELA GONZALEZ", 36, 0).x / 2), static_cast<int>(GetScreenHeight() / 2 - GetScreenHeight() / 14), 36, RAYWHITE);

	DrawRectangleRec(backButton, RAYWHITE);
	
	Vector2 backMeasure = MeasureTextEx(GetFontDefault(), "BACK", 36, 0);
	DrawText("BACK", static_cast<int>(backButton.x + backButton.width / 2 - backMeasure.x / 2), static_cast<int>(backButton.y + backButton.height / 2 - backMeasure.y / 2), 36, BLACK);

	EndDrawing();
}