#pragma once
#include "raylib.h"
#include<vector>
#include <cstdlib>
#include <ctime>
class Background {

	void SetupSize()
	{
		Basebackground.width = GetScreenWidth() * 2;
		Basebackground.height = GetScreenHeight() * 2;


		BasebackgroundOpened.width = GetScreenWidth() * 2;
		BasebackgroundOpened.height = GetScreenHeight() * 2;

		map1.width = GetScreenWidth() * 2;
		map1.height = GetScreenHeight() * 2;

		map1_opened.width = GetScreenWidth() * 2;
		map1_opened.height = GetScreenHeight() * 2;

		map2.width = GetScreenWidth() * 2;
		map2.height = GetScreenHeight() * 2;

		map2_opened.width = GetScreenWidth() * 2;
		map2_opened.height = GetScreenHeight() * 2;

		map3.width = GetScreenWidth() * 2;
		map3.height = GetScreenHeight() * 2;

		map3_opened.width = GetScreenWidth() * 2;
		map3_opened.height = GetScreenHeight() * 2;
	}
	vector<vector<string>>StringOfBGs = { 
		{"../images/backgrounds/map7.png", "../images/backgrounds/map7_opened.png" },
		{"../images/backgrounds/map2.png", "../images/backgrounds/map2_opened.png"},
		{"../images/backgrounds/map3.png", "../images/backgrounds/map3_opened.png"}, 
		{"../images/backgrounds/map4.png", "../images/backgrounds/map4_opened.png"}, 
		{"../images/backgrounds/map5.png", "../images/backgrounds/map5_opened.png"}, 
		{"../images/backgrounds/map6.png", "../images/backgrounds/map6_opened.png"} 
	};
	public:
		string randomArr[3][2];
		Texture2D Basebackground = LoadTexture("../images/backgrounds/map1.png");
		Texture2D map1;
		Texture2D BasebackgroundOpened = LoadTexture("../images/backgrounds/map1_opened.png");
		Texture2D map1_opened;
		Texture2D map2;
		Texture2D map2_opened;
		Texture2D map3;
		Texture2D map3_opened;
		Background() // constructor
		{
			srand(time(0));// set random number every time
			for (int i = 0; i < 3; i++)
			{
				int random = rand() % StringOfBGs.size(); // get random number index of vector with all directories
				randomArr[i][0] = StringOfBGs[random][0]; // initialize randomArr
				randomArr[i][1] = StringOfBGs[random][1]; // initialize randomArr
				StringOfBGs.erase(StringOfBGs.begin() + random);// erase used element of vector
			}
			map1 = LoadTexture(randomArr[0][0].c_str());
			map1_opened = LoadTexture(randomArr[0][1].c_str());
			map2 = LoadTexture(randomArr[1][0].c_str());
			map2_opened = LoadTexture(randomArr[1][1].c_str());
			map3 = LoadTexture(randomArr[2][0].c_str());
			map3_opened = LoadTexture(randomArr[2][1].c_str());
		}

	Rectangle bg_pos = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2, (float)GetScreenWidth(), (float)GetScreenHeight()};
	void DrawBase()
	{
		SetupSize();
		DrawTextureRec(Basebackground, bg_pos, {0, 0}, WHITE);
		
	}
	void DrawBase_Opened()
	{
		SetupSize();
		DrawTextureRec(BasebackgroundOpened, bg_pos, { 0, 0 }, WHITE);
	}
	void DrawMap1()
	{
		SetupSize();
		DrawTextureRec(map1, bg_pos, { 0, 0 }, WHITE);
	}
	//new
	void DrawMap1_Opened()
	{
		SetupSize();
		DrawTextureRec(map1_opened, bg_pos, { 0, 0 }, WHITE);
	}
	void DrawMap2()
	{
		SetupSize();
		DrawTextureRec(map2, bg_pos, { 0, 0 }, WHITE);
	}
	void DrawMap2_Opened()
	{
		SetupSize();
		DrawTextureRec(map2_opened, bg_pos, { 0, 0 }, WHITE);
	}
	void DrawMap3()
	{
		SetupSize();
		DrawTextureRec(map3, bg_pos, { 0, 0 }, WHITE);
	}
	void DrawMap3_Opened()
	{
		SetupSize();
		DrawTextureRec(map3_opened, bg_pos, { 0, 0 }, WHITE);
	}
	void UnloadBG()
	{
		UnloadTexture(Basebackground);
		UnloadTexture(BasebackgroundOpened);

		UnloadTexture(map1);
		UnloadTexture(map1_opened);

		UnloadTexture(map2);
		UnloadTexture(map2_opened);

		UnloadTexture(map3);
		UnloadTexture(map3_opened);
	}
};