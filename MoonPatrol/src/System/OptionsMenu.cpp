#include "System/Game.h"

void ShowOptions(MenuScreen& currentScreen, bool& onePlayer)
{
	Rectangle backButton{ static_cast<float> (GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2),
		static_cast<float> (GetScreenHeight() / 2 + 20),
		static_cast<float> (GetScreenWidth() / 4),
		static_cast<float> (GetScreenHeight() / 12) };

	Rectangle onePlayerButton{ static_cast<float>(GetScreenWidth() - GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2),
	static_cast<float> (GetScreenHeight() / 4),
	static_cast<float> (GetScreenWidth() / 4 + 50),
	static_cast<float> (GetScreenHeight() / 12) };

	Rectangle twoPlayersButton{ static_cast<float>(GetScreenWidth() - GetScreenWidth() / 4 - GetScreenWidth() / 4 / 2),
	static_cast<float> (GetScreenHeight() / 2 + 150),
	static_cast<float> (GetScreenWidth() / 4 + 50),
	static_cast<float> (GetScreenHeight() / 12) };

	if (CheckButton(backButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		currentScreen = MenuScreen::MainMenu;
	}

	if (CheckButton(onePlayerButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		onePlayer = true;
		currentScreen = MenuScreen::MainMenu;
	}

	if (CheckButton(twoPlayersButton) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
	{
		onePlayer = false;
		currentScreen = MenuScreen::MainMenu;
	}

	BeginDrawing();
	ClearBackground(BLACK);

	DrawRectangleRec(backButton, RAYWHITE);
	Vector2 backMeasure = MeasureTextEx(GetFontDefault(), "BACK", 36, 0);
	DrawText("BACK", static_cast<int> (backButton.x + backButton.width / 2 - backMeasure.x / 2), static_cast<int> (backButton.y + backButton.height / 2 - backMeasure.y / 2), 36, BLACK);
	
	DrawRectangleRec(onePlayerButton, RAYWHITE);
	Vector2 onePlayerMeasure = MeasureTextEx(GetFontDefault(), "ONE PLAYER", 36, 0);
	DrawText("ONE PLAYER", static_cast<int> (onePlayerButton.x + onePlayerButton.width / 2 - onePlayerMeasure.x / 2), static_cast<int> (onePlayerButton.y + onePlayerButton.height / 2 - onePlayerMeasure.y / 2), 36, BLACK);
	
	DrawRectangleRec(twoPlayersButton, RAYWHITE);
	Vector2 twoPlayersMeasure = MeasureTextEx(GetFontDefault(), "TWO PLAYERS", 36, 0);
	DrawText("TWO PLAYERS", static_cast<int> (twoPlayersButton.x + twoPlayersButton.width / 2 - twoPlayersMeasure.x / 2), static_cast<int> (twoPlayersButton.y + twoPlayersButton.height / 2 - twoPlayersMeasure.y / 2), 36, BLACK);

	EndDrawing();
}