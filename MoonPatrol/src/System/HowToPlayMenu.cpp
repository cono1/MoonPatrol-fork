#include "System/Game.h"

void ShowHowToPlay(MenuScreen& currentScreen)
{
	Rectangle backButton{ static_cast<float>(GetScreenWidth() / 2) - static_cast<float>(GetScreenWidth() / 4 / 2),
	static_cast<float>(GetScreenHeight() / 2 + GetScreenHeight() / 4),
	static_cast<float>(GetScreenWidth() / 4),
	static_cast<float>(GetScreenHeight() / 12) };

	if (CheckButton(backButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentScreen = MenuScreen::MainMenu;
	}

	BeginDrawing();
	ClearBackground(BLACK);

	DrawText("FIRST PLAYER: ", static_cast<int>(GetScreenWidth() / 4 - MeasureTextEx(GetFontDefault(), "FIRST PLAYER:", 39, 0).x / 2), static_cast<int>(GetScreenHeight() / 2 - GetScreenHeight() / 5), 39, MAGENTA);
	DrawText("Jump with UP ARROW", static_cast<int>(GetScreenWidth() / 4 - 10 - MeasureTextEx(GetFontDefault(), "Jump with UP ARROW", 36, 0).x / 2), static_cast<int>(GetScreenHeight() / 4 + GetScreenHeight() / 5), 36, RAYWHITE);
	DrawText("Shoot with ENTER", static_cast<int>(GetScreenWidth() / 4 - MeasureTextEx(GetFontDefault(), "Shoot with ENTER", 36, 0).x / 2), static_cast<int>(GetScreenHeight() / 3 + GetScreenHeight() / 5), 36, RAYWHITE);

	DrawText("SECOND PLAYER: ", static_cast<int>(GetScreenWidth() / 2 + GetScreenWidth() / 5 - MeasureTextEx(GetFontDefault(), "FIRST PLAYER:", 39, 0).x / 2), static_cast<int>(GetScreenHeight() / 2 - GetScreenHeight() / 5), 39, GREEN);
	DrawText("Jump with W", static_cast<int>(GetScreenWidth() / 2 - 10 + GetScreenWidth() / 5 - MeasureTextEx(GetFontDefault(), "Jump with W", 36, 0).x / 2), static_cast<int>(GetScreenHeight() / 4 + GetScreenHeight() / 5), 36, RAYWHITE);
	DrawText("Shoot with SPACE", static_cast<int>(GetScreenWidth() / 2 + GetScreenWidth() / 5 - MeasureTextEx(GetFontDefault(), "Shoot with SPACE", 36, 0).x / 2), static_cast<int>(GetScreenHeight() / 3 + GetScreenHeight() / 5), 36, RAYWHITE);

	DrawRectangleRec(backButton, RAYWHITE);

	Vector2 backMeasure = MeasureTextEx(GetFontDefault(), "BACK", 36, 0);
	DrawText("BACK", static_cast<int>(backButton.x + backButton.width / 2 - backMeasure.x / 2), static_cast<int>(backButton.y + backButton.height / 2 - backMeasure.y / 2), 36, BLACK);

	EndDrawing();
}