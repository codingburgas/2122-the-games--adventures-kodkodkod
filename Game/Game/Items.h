#pragma once
#include "include.h"
class Items
{
public:
	bool checker = 1;

	Texture2D Chest = LoadTexture("../images/chest.png");
	Texture2D Opened_Chest = LoadTexture("../images/opened_chest.png");
	Texture2D Key = LoadTexture("../images/Key.png");

	Vector2 mousePoint;

	bool wrong_chest1 = 0, wrong_chest2 = 0, wrong_chest3 = 0, right_chest = 0;

	Rectangle chests[4];
	void MakeChests()
	{
		mousePoint = GetMousePosition();

		chests[0] = { 70, 85, 175, 125 };
		chests[1] = { 270, 135, 175, 125 };
		chests[2] = { 470, 185, 175, 125 };
		chests[3] = { 670, 235, 175, 125 };

		Opened_Chest.width = 1800;
		Opened_Chest.height = 850;

		Key.width = 100;
		Key.height = 200;

		for (int i = 0; i < 4; i++)
		{
			DrawRectangleRec(chests[i], BLANK);
			DrawTexture(Chest, 0 + (i * 200) , 0+(i*50), WHITE);
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

		if (wrong_chest1 or wrong_chest2 or	wrong_chest3)
		{
			DrawTexture(Opened_Chest, 30, 30, WHITE);
		}
		if (right_chest)
		{
			DrawTexture(Opened_Chest, 30, 30, WHITE);
			DrawTexture(Key, 600, 360, WHITE);
		}
	}
};