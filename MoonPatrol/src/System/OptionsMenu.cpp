#include "System/MainMenu.h"

void ShowOptions(MenuScreen& currentScreen)
{
	Rectangle backButton{ static_cast<float> (GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2),
		static_cast<float> (GetScreenHeight() / 2 + 20),
		static_cast<float> (GetScreenWidth() / 4),
		static_cast<float> (GetScreenHeight() / 12) };

	if (CheckButton(backButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentScreen = MenuScreen::MainMenu;
	}

	BeginDrawing();
	ClearBackground(BLACK);

	DrawRectangleRec(backButton, RAYWHITE);
	Vector2 backMeasure = MeasureTextEx(GetFontDefault(), "BACK", 36, 0);
	DrawText("BACK", static_cast<int> (backButton.x + backButton.width / 2 - backMeasure.x / 2), static_cast<int> (backButton.y + backButton.height / 2 - backMeasure.y / 2), 36, BLACK);

	EndDrawing();
	// si elige un player o dos players (?
}