#pragma once
#include "raylib.h"
class Background {
	Texture2D background = LoadTexture("../images/background.png");
	
	void SetupSize()
	{
		background.width = GetScreenWidth();
		background.height = GetScreenHeight();
	}
	
	public:

	void DrawBackground()
	{
		SetupSize();
		DrawTexture(background, 0, 0, WHITE);
	}
	void UnloadBG()
	{
		UnloadTexture(background);
	}
};