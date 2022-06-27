#include"Background.h"
void Background::SetupSize()
{
	//sets backgrounds width and heigth *2 because the background should move 
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

Background::Background() // constructor
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
void Background::DrawBase()
{
	SetupSize();
	DrawTextureRec(Basebackground, bg_pos, { 0, 0 }, WHITE);

}
void Background::DrawBase_Opened()
{
	SetupSize();
	DrawTextureRec(BasebackgroundOpened, bg_pos, { 0, 0 }, WHITE);
}
void Background::DrawMap1()
{
	SetupSize();
	DrawTextureRec(map1, bg_pos, { 0, 0 }, WHITE);
}
//new
void Background::DrawMap1_Opened()
{
	SetupSize();
	DrawTextureRec(map1_opened, bg_pos, { 0, 0 }, WHITE);
}
void Background::DrawMap2()
{
	SetupSize();
	DrawTextureRec(map2, bg_pos, { 0, 0 }, WHITE);
}
void Background::DrawMap2_Opened()
{
	SetupSize();
	DrawTextureRec(map2_opened, bg_pos, { 0, 0 }, WHITE);
}
void Background::DrawMap3()
{
	SetupSize();
	DrawTextureRec(map3, bg_pos, { 0, 0 }, WHITE);
}
void Background::DrawMap3_Opened()
{
	SetupSize();
	DrawTextureRec(map3_opened, bg_pos, { 0, 0 }, WHITE);
}
void Background::UnloadBG()
{
	//unload every background
	UnloadTexture(Basebackground);
	UnloadTexture(BasebackgroundOpened);

	UnloadTexture(map1);
	UnloadTexture(map1_opened);

	UnloadTexture(map2);
	UnloadTexture(map2_opened);

	UnloadTexture(map3);
	UnloadTexture(map3_opened);
}