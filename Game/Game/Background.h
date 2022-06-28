#pragma once
#include "include.h"
#include<vector>
#include <cstdlib>
#include <ctime>
using namespace std;
class Background {

	//all the backgrounds in a vector that  then is used to make them random
	vector<vector<string>>StringOfBGs = { 
		{"../images/backgrounds/map7.png", "../images/backgrounds/map7_opened.png" },
		{"../images/backgrounds/map2.png", "../images/backgrounds/map2_opened.png"},
		{"../images/backgrounds/map3.png", "../images/backgrounds/map3_opened.png"}, 
		{"../images/backgrounds/map4.png", "../images/backgrounds/map4_opened.png"}, 
		{"../images/backgrounds/map5.png", "../images/backgrounds/map5_opened.png"}, 
		{"../images/backgrounds/map6.png", "../images/backgrounds/map6_opened.png"} 
	};
	public:
		//array making them random
		string randomArr[3][2];
		Texture2D Basebackground = LoadTexture("../images/backgrounds/map1.png");
		Texture2D map1;
		Texture2D BasebackgroundOpened = LoadTexture("../images/backgrounds/map1_opened.png");
		Texture2D map1_opened;
		Texture2D map2;
		Texture2D map2_opened;
		Texture2D map3;
		Texture2D map3_opened;
		Rectangle bg_pos = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2, (float)GetScreenWidth(), (float)GetScreenHeight()};
	Background();
	void SetupSize();
	void DrawBase();
	void DrawBase_Opened();
	void DrawMap1();
	void DrawMap1_Opened();
	void DrawMap2();
	void DrawMap2_Opened();
	void DrawMap3();
	void DrawMap3_Opened();
	void UnloadBG();
};