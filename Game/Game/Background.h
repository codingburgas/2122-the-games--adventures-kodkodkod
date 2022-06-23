#pragma once
#include "raylib.h"
class Background {
	
	void SetupSize()
	{
		background.width = GetScreenWidth() * 2;
		background.height = GetScreenHeight() * 2;

		background3.width = GetScreenWidth() * 2;
		background3.height = GetScreenHeight() * 2;
	}
	
	public:
	Texture2D background = LoadTexture("../images/background.png");
	Texture2D background3 = LoadTexture("../images/background3.png");
	Rectangle bg_pos = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2, (float)GetScreenWidth(), (float)GetScreenHeight()};
	void DrawBackground()
	{
		SetupSize();
		DrawTextureRec(background, bg_pos, {0, 0}, WHITE);
	}
	void DrawBackground3()
	{
		SetupSize();
		DrawTextureRec(background3, bg_pos, { 0, 0 }, WHITE);
	}
	void UnloadBG()
	{
		UnloadTexture(background);
		UnloadTexture(background3);
	}
};