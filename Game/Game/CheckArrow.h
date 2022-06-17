#pragma once
#include "Namespace.h"
#include "DrawHero.h"
#include "Background.h"
class Arrows{
public:
	Hero Hero_obj;
	Background moveBG;
	bool checker = 1;
	bool checker2 = 0;
	bool checker3 = 0;
	Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };
	Texture2D Chest = LoadTexture("../images/chest.png");
	Texture2D Opened_Chest = LoadTexture("../images/opened_chest.png");
	Texture2D Key = LoadTexture("../images/Key.png");
	Vector2 mousePoint;
	Vector2 Circlee;
	bool wrong_chest1 = 0, wrong_chest2 = 0, wrong_chest3 = 0, right_chest = 0;

	Rectangle chests[4];

	void MakeChests()
	{

		mousePoint = GetMousePosition();

		chests[0] = { 0,0, 400, 350 };
		chests[1] = { 11270, 135, 150, 100 };
		chests[2] = { 111470, 185, 150, 100 };
		chests[3] = { 111670, 235, 150, 100 };

		Opened_Chest.width = 1800;
		Opened_Chest.height = 850;

		Key.width = 100;
		Key.height = 200;

		for (int i = 0; i < 4; i++)
		{


			DrawRectangleLinesEx(chests[i], 7.5, BLANK);
		}

	}
	void CheckChests()
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, chests[0]) && checker)
		{

			wrong_chest1 = true;
			wrong_chest2 = 0;
			wrong_chest3 = 0;
			right_chest = 0;
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, chests[1]) && checker)
		{
			wrong_chest1 = 0;
			wrong_chest2 = true;
			wrong_chest3 = 0;
			right_chest = 0;
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, chests[2]) && checker)
		{

			wrong_chest1 = 0;
			wrong_chest2 = 0;
			wrong_chest3 = true;
			right_chest = 0;
		}
		else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, chests[3]) && checker)
		{

			wrong_chest1 = 0;
			wrong_chest2 = 0;
			wrong_chest3 = 0;
			right_chest = true;
		}

	}
	void checkArrows()
	{
		if (IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT))
		{
			if (!(Hero_obj.HeroPos.x <= 5))
			{
			Hero_obj.HeroPos.x -= 5;
			}
			if (!(moveBG.bg_pos.x <= 0) && Hero_obj.HeroPos.x < (GetScreenWidth() - Hero_obj.HeroClip.width) - 200)
			{
				moveBG.bg_pos.x -= GetScreenWidth() / 100;
			}
			
		}
		else if (IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT))
		{
			if (!(Hero_obj.HeroPos.x >= (GetScreenWidth() - Hero_obj.HeroClip.width) - 5))
			{
				Hero_obj.HeroPos.x += 5;
			}
			if (!(moveBG.bg_pos.x >= GetScreenWidth()) && Hero_obj.HeroPos.x > 200)
			{
				moveBG.bg_pos.x += GetScreenWidth() / 100;
			}
		}
		if (IsKeyDown(KEY_W) or IsKeyDown(KEY_UP))
		{
			if (!(Hero_obj.HeroPos.y <= 5))
			{
				Hero_obj.HeroPos.y -= 5;
			}
			if (!(moveBG.bg_pos.y <= 0) && Hero_obj.HeroPos.y < (GetScreenHeight() - Hero_obj.HeroClip.height) - 200)
			{
				moveBG.bg_pos.y -= GetScreenHeight() / 100;
			}
		}
		else if (IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN))
		{
			if (!(Hero_obj.HeroPos.y >= (GetScreenHeight() - Hero_obj.HeroClip.height) - 30))
			{
				Hero_obj.HeroPos.y += 5;
			}
			if (!(moveBG.bg_pos.y >= GetScreenHeight()) && Hero_obj.HeroPos.y > 200)
			{
				moveBG.bg_pos.y += GetScreenHeight() / 100;
			}
		}
		if (chests[0].width - Hero_obj.HeroPos.x > Hero_obj.HeroClip.width / 2 && chests[0].height - Hero_obj.HeroPos.y > Hero_obj.HeroClip.height / 2)
		{
			if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[0]))
			{

				DrawText("Press 'E' to open the chest", 10, 10, 40, WHITE);
				if (IsKeyPressed(KEY_E))
				{
					checker2 = 1;
				}
			}
		}
		if (checker2)
		{
			DrawTexture(Opened_Chest, 30, 30, WHITE);
			DrawCircle(1650, 125, 20, RED);
			Circlee.x = 1650;
			Circlee.y = 125;
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Circlee, 20))
			{
				checker2=0;
			}
		}
		
	}
	
	
};
