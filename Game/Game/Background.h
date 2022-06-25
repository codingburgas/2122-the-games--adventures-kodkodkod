#pragma once
#include "raylib.h"
#include<vector>
#include <algorithm>
class Background {

	void SetupSize()
	{
		background.width = GetScreenWidth() * 2;
		background.height = GetScreenHeight() * 2;


		background2.width = GetScreenWidth() * 2;
		background2.height = GetScreenHeight() * 2;

		background3.width = GetScreenWidth() * 2;
		background3.height = GetScreenHeight() * 2;

		background3_opened.width = GetScreenWidth() * 2;
		background3_opened.height = GetScreenHeight() * 2;

		map3.width = GetScreenWidth() * 2;
		map3.height = GetScreenHeight() * 2;

		map3_opened.width = GetScreenWidth() * 2;
		map3_opened.height = GetScreenHeight() * 2;
	}
	string StringOfBGs[3] = {"../images/backgrounds/background.png", "../images/backgrounds/background3.png","../images/backgrounds/map3.png" };
	public:
	Background()
	{
		random_shuffle(&StringOfBGs, &StringOfBGs + 3);
		for (string i : StringOfBGs)
		{
			cout << i;
		}
	}
	Texture2D background = LoadTexture(StringOfBGs[0].c_str());
	Texture2D background3 = LoadTexture(StringOfBGs[1].c_str());
	Texture2D background2 = LoadTexture("../images/backgrounds/background2.png");

	Texture2D background3_opened = LoadTexture("../images/backgrounds/background3_opened1.png");
	Texture2D map3 = LoadTexture(StringOfBGs[2].c_str());
	Texture2D map3_opened = LoadTexture("../images/backgrounds/map3_opened.png");

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
	void DrawBackground2()
	{
		SetupSize();
		DrawTextureRec(background2, bg_pos, { 0, 0 }, WHITE);
	}
	//new
	void DrawBackground3_Opened()
	{
		SetupSize();
		DrawTextureRec(background3_opened, bg_pos, { 0, 0 }, WHITE);
	}
	void DrawBackground4()
	{
		SetupSize();
		DrawTextureRec(map3, bg_pos, { 0, 0 }, WHITE);
	}
	void DrawBackground4_Opened()
	{
		SetupSize();
		DrawTextureRec(map3_opened, bg_pos, { 0, 0 }, WHITE);
	}
	void UnloadBG()
	{
		UnloadTexture(background);
		UnloadTexture(background3);
		UnloadTexture(background2);

		UnloadTexture(background3_opened);
		UnloadTexture(map3);
		UnloadTexture(map3_opened);
	}
};