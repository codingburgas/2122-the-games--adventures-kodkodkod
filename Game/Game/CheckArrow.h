#pragma once
#include "Namespace.h"
#include "DrawHero.h"
#include "Background.h"
#include <iostream>
class Arrows {
public:
	Hero Hero_obj;
	Background moveBG;
	bool checker = 1;
	bool checker2 = 0;
	bool checker3 = 0;
	bool checker4 = 0;

	bool checkInput[4] = {0, 0, 0, 0};
	Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };
	Texture2D Chest = LoadTexture("../images/chest.png");
	Texture2D Opened_Chest = LoadTexture("../images/opened_chest.png");
	Texture2D Key = LoadTexture("../images/Key.png");
	Rectangle Border;
	Rectangle KeyRec;
	Vector2 mousePoint;
	Vector2 Circlee;
	bool wrong_chest1 = 0, wrong_chest2 = 0, wrong_chest3 = 0, right_chest = 0;

	Rectangle chests[4];

	void MakeChests()
	{

		mousePoint = GetMousePosition();

		chests[0] = { 0,0, 500, 350 };
		chests[1] = { (float)GetScreenWidth() - 500, 0, 500, 350 };
		chests[2] = { 0, (float)GetScreenHeight() - 350, 500, 350 };
		chests[3] = { (float)GetScreenWidth() - 500, (float)GetScreenHeight() - 350, 500, 350 };

		Opened_Chest.width = 1800;
		Opened_Chest.height = 850;

		Key.width = 100;
		Key.height = 200;

		for (int i = 0; i < 4; i++)
		{


			DrawRectangleLinesEx(chests[i], 7.5, WHITE);
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
		if ((IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT)) && checkInput[3] == 0 && checkInput[1] == 0 && checkInput[2] == 0)
		{
			checkInput[0] = 1;
			checkInput[1] = 0;
			checkInput[2] = 0;
			checkInput[3] = 0;
			if (!(Hero_obj.HeroPos.x <= 5))
			{
				Hero_obj.HeroPos.x -= 5;
			}
			if (!(moveBG.bg_pos.x <= 0) && Hero_obj.HeroPos.x < (GetScreenWidth() - Hero_obj.HeroClip.width) - 200)
			{
				moveBG.bg_pos.x -= GetScreenWidth() / 100;
			}

		}
		else if ((IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT)) && checkInput[0] == 0 && checkInput[2] == 0 && checkInput[3] == 0)
		{
			checkInput[0] = 0;
			checkInput[1] = 1;
			checkInput[2] = 0;
			checkInput[3] = 0;
			if (!(Hero_obj.HeroPos.x >= (GetScreenWidth() - Hero_obj.HeroClip.width) - 5))
			{
				Hero_obj.HeroPos.x += 5;
			}
			if (!(moveBG.bg_pos.x >= GetScreenWidth()) && Hero_obj.HeroPos.x > 200)
			{
				moveBG.bg_pos.x += GetScreenWidth() / 100;
			}
		}
		else if ((IsKeyDown(KEY_W) or IsKeyDown(KEY_UP)) && checkInput[0] == 0 && checkInput[1] == 0 && checkInput[3] == 0)
		{
			checkInput[0] = 0;
			checkInput[1] = 0;
			checkInput[2] = 1;
			checkInput[3] = 0;
			if (!(Hero_obj.HeroPos.y <= 5))
			{
				Hero_obj.HeroPos.y -= 5;
			}
			if (!(moveBG.bg_pos.y <= 0) && Hero_obj.HeroPos.y < (GetScreenHeight() - Hero_obj.HeroClip.height) - 200)
			{
				moveBG.bg_pos.y -= GetScreenHeight() / 100;
			}
		}
		else if ((IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN)) && checkInput[0] == 0 && checkInput[1] == 0 && checkInput[2] == 0)
		{
			checkInput[0] = 0;
			checkInput[1] = 0;
			checkInput[2] = 0;
			checkInput[3] = 1;
			if (!(Hero_obj.HeroPos.y >= (GetScreenHeight() - Hero_obj.HeroClip.height) - 30))
			{
				Hero_obj.HeroPos.y += 5;
			}
			if (!(moveBG.bg_pos.y >= GetScreenHeight()) && Hero_obj.HeroPos.y > 200)
			{
				moveBG.bg_pos.y += GetScreenHeight() / 100;
			}
		}
		else
		{
			checkInput[0] = 0;
			checkInput[1] = 0;
			checkInput[2] = 0;
			checkInput[3] = 0;
		}
		if (chests[0].width - Hero_obj.HeroPos.x > Hero_obj.HeroClip.width / 2 && chests[0].height - Hero_obj.HeroPos.y > Hero_obj.HeroClip.height / 2)
		{

			if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[0]))
			{

				DrawText("Press 'E' to open the chest", 10, 10, 35, WHITE);
				if (IsKeyPressed(KEY_E))
				{
					checker2 = 1;
				}
			}

		}
		Border.x = 420;
		Border.y = 60;
		Border.width = 1300;
		Border.height = 800;

		KeyRec.x = 590;
		KeyRec.y = 350;
		KeyRec.width = 125;
		KeyRec.height = 225;
		if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[1]))
		{

			DrawText("Press 'E' to open the chest", 1380, 10, 35, WHITE);
			if (IsKeyPressed(KEY_E))
			{
				checker2 = 1;
			}

		}
		if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[2]))
		{

			DrawText("Press 'E' to open the chest", 10, 620, 35, WHITE);
			if (IsKeyPressed(KEY_E))
			{
				checker3 = 1;
			}
		}
		if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[3]))
		{
			DrawText("Press 'E' to open the chest", 1380, 620, 35, WHITE);
			if (IsKeyPressed(KEY_E))
			{
				checker2 = 1;
			}
		}

		if (checker2)
		{
			DrawTexture(Opened_Chest, 30, 30, WHITE);
			DrawCircle(1650, 125, 20, RED);
			DrawRectangleLinesEx(Border, 7.5, BLACK);
			DrawLine(1640, 108, 1660, 142, WHITE);
			DrawLine(1660, 108, 1640, 142, WHITE);
			Circlee.x = 1650;
			Circlee.y = 125;
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Circlee, 20))
			{
				checker2 = 0;
			}
		}
		if (checker3)
		{


			DrawTexture(Opened_Chest, 30, 30, WHITE);
			DrawTexture(Key, 600, 360, WHITE);

			DrawRectangleLinesEx(Border, 7.5, BLACK);
			DrawRectangleLinesEx(KeyRec, 6, BLANK);
			DrawCircle(1650, 125, 20, RED);
			DrawLine(1640, 108, 1660, 142, WHITE);
			DrawLine(1660, 108, 1640, 142, WHITE);
			Circlee.x = 1650;
			Circlee.y = 125;
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, KeyRec))
			{
				moveBG.background = LoadTexture("../images/background2.png");
				//DrawRectangleRec(hide, BLANK);
				checker3 = 0;
			}
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Circlee, 20))
			{
				checker3 = 0;
			}
		}

	}


};
