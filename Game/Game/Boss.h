#pragma once
#include"raylib.h"
#include "CheckArrow.h"
#include "Namespace.h"
class Boss{
	int fpscounter = 0;
	//texture for boss
	Texture2D boss = LoadTexture("../images/boss.png");
	//texture for background
	Texture2D finalBG = LoadTexture("../images/backgrounds/finalmap.png");

public:
	//rectangle for boss
	Rectangle ClipBoss = {0,0, (float)boss.width / 3, (float)boss.height};
	//boss position vector
	Vector2 PosBoss = {(float)GetScreenWidth() / 2, 100};
	float healthBarBoss = 300;
	float healthBarHero = 200;
	float AtackBoss = 1;
	float AtackHero = 25;
	bool you_win = 0;
	bool you_lose = 0;
	Rectangle HealthBoss = { (float)PosBoss.x, (float)PosBoss.y, (float)healthBarBoss, 10};
	Rectangle HealthHero = {0,0, (float)healthBarHero,10};

	bool not_play_again = 1;

	Texture2D GameOver_img_lose = LoadTexture("../images/GameOver_you_lose.png");
	Texture2D GameOver_img_win = LoadTexture("../images/GameOver_you_win.png");

	Vector2 Close;
	Vector2 mousePoint;


	Rectangle Exit = { 750,850, 275, 100 };

	Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };

	void Update(Arrows& object)
	{
		finalBG.width = GetScreenWidth();
		finalBG.height = GetScreenHeight();
		//fps begin
		if (fpscounter == 10)
		{
			ClipBoss.x += (float)boss.width / 3;
			fpscounter = 0;
		}
		if (ClipBoss.x >= boss.width)
		{
			ClipBoss.x = 0;
		}
		fpscounter++;
		//fps end
		HealthHero.x = object.Hero_obj.HeroPos.x;
		HealthHero.y = object.Hero_obj.HeroPos.y - 20;
		HealthHero.width = healthBarHero;
		HealthBoss.width = healthBarBoss;
		
	}
	void Draw(Menu& Menu_object)
	{
		//draw everything
		DrawTexture(finalBG, 0, 0, WHITE);
		DrawTextureRec(boss, ClipBoss, PosBoss, WHITE);
		DrawRectangleRec(HealthBoss, RED);
		DrawRectangleRec(HealthHero, RED);
		DrawText("Baikal",PosBoss.x +45, PosBoss.y - 35,40,WHITE);
		if (you_lose)
		{
			if (not_play_again)
			{
				mousePoint = GetMousePosition();

				GameOver_img_lose.width = 1600;
				GameOver_img_lose.height = 850;

				DrawRectangleRec(hide, Fade(BLACK, 0.79999999));

				DrawTexture(GameOver_img_lose, 150, 100, WHITE);

				DrawRectangleRounded(Exit, 7, 7, DARKGRAY);
				DrawText("Quit", 830, 875, 65, WHITE);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, Exit))
				{
					exit(0);
				}

				
			}

		}
		if (you_win)
		{
			mousePoint = GetMousePosition();

			GameOver_img_win.width = 1600;
			GameOver_img_win.height = 850;


			DrawRectangleRec(hide, Fade(BLACK, 0.79999999));

			DrawTexture(GameOver_img_win, 150, 100, WHITE);

			

			DrawRectangleRounded(Exit, 7, 7, DARKGRAY);
			DrawText("Quit", 830, 875, 65, WHITE);

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, Exit))
			{
				exit(0);

			}
		}
		
		
	}
	void Check(Arrows &hero)
	{
		//gameover for losing
		if (healthBarHero <= 0)
		{
			you_lose = 1;
		}
		//gameover for winning
		else if (healthBarBoss <= 0)
		{
			you_win = 1;


		}
		else if ((hero.Hero_obj.HeroPos.x >= PosBoss.x + 200 && hero.Hero_obj.HeroPos.x <= PosBoss.x + ClipBoss.width) && 
			(hero.Hero_obj.HeroPos.y <= PosBoss.y + ClipBoss.height))
		{
			//atacks
			if (IsKeyPressed(KEY_E))
			{
				healthBarBoss -= AtackHero;
			}
			
			healthBarHero -= AtackBoss;
			
			
		}
		
	}
	void Unload()
	{
		//unload textures
		UnloadTexture(finalBG);
		UnloadTexture(boss);
	}
};