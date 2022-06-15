#pragma once
#include "raylib.h"
class Background {
	Texture2D background = LoadTexture("../images/background.png");
	
	void SetupSize()
	{
		background.width = GetScreenWidth() * 3;
		background.height = GetScreenHeight() * 3;
	}
	
	public:
	Rectangle bg_pos = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2, (float)GetScreenWidth(), (float)GetScreenHeight()};
	void DrawBackground()
	{
		SetupSize();
		DrawTextureRec(background, bg_pos, {0, 0}, WHITE);
	}
	void UnloadBG()
	{
		UnloadTexture(background);
	}
};