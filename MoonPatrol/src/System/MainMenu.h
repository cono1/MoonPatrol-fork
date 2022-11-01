#pragma once
#include "raylib.h"

void StartProgram();
bool CheckButton(Rectangle playButton);

enum class MenuScreen
{
	MainMenu,
	Play,
	Options,
	Credits,
	Quit
};