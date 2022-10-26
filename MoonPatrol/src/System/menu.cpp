#include "menu.h"

void StartWindow();
void GameLoop();

void StartProgram()
{
	StartWindow();

	GameLoop();
}

void StartWindow()
{
	int width = 1024;
	int height = 768;
		
	InitWindow(width, height, "MoonPatrol - By Ian Kuznicki");
}