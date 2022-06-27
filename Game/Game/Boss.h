#pragma once
#include"raylib.h"
#include "CheckArrow.h"
#include "Namespace.h"
class Boss {
	int fpscounter = 0;
	int Attack_counter = 0;
	//texture for boss
	Texture2D boss = LoadTexture("../images/boss.png");
	//texture for background
	Texture2D finalBG = LoadTexture("../images/backgrounds/finalmap.png");

public:
	//rectangle for boss
	Rectangle ClipBoss = { 0,0, (float)boss.width / 3, (float)boss.height };
	//boss position vector
	Vector2 PosBoss = { (float)GetScreenWidth() / 2, 100 };
	float healthBarBoss = 300;
	float healthBarHero = 200;
	float AtackBoss = 1;
	float AtackHero = 25;
	bool you_win = 0;
	bool you_lose = 0;
	bool playAgain = 0;
	bool checkToStopMovement = 1;
	Rectangle HealthBoss = { (float)PosBoss.x, (float)PosBoss.y, (float)healthBarBoss, 10 };
	Rectangle HealthHero = { 0,0, (float)healthBarHero,10 };
	bool check_attack = 0;
	bool not_play_again = 1;
	bool finish_attack = 1;

	Texture2D GameOver_img_lose = LoadTexture("../images/GameOver_you_lose.png");
	Texture2D GameOver_img_win = LoadTexture("../images/GameOver_you_win.png");

	Texture2D Attack_left = LoadTexture("../images/Hero/attackSprite_left.png");
	Texture2D Attack_up = LoadTexture("../images/Hero/attackSprite_up.png");
	Texture2D Attack_right = LoadTexture("../images/Hero/attackSprite_right.png");

	
	Rectangle RectLeft= { 0, 0, (float)Attack_left.width /3, (float)Attack_left.height };
	Rectangle RectUp = { 0, 0, (float)Attack_up.width /3, (float)Attack_up.height };
	Rectangle RectRight = { (float)Attack_right.width, 0, (float)Attack_right.width /3, (float)Attack_right.height };

	Vector2 Close;
	Vector2 mousePoint;

	Rectangle Play_Again = { 580,850, 275, 100 };
	Rectangle Exit = { 950,850, 275, 100 };

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
	void Draw(Menu& Menu_object, Arrows & hero)
	{
		//draw everything
		DrawTexture(finalBG, 0, 0, WHITE);
		DrawTextureRec(boss, ClipBoss, PosBoss, WHITE);
		DrawRectangleRec(HealthBoss, RED);
		DrawRectangleRec(HealthHero, RED);
		DrawText("Baikal", PosBoss.x + 45, PosBoss.y - 35, 40, WHITE);
		if (you_lose)
		{
			if (not_play_again)
			{
				mousePoint = GetMousePosition();

				GameOver_img_lose.width = 1600;
				GameOver_img_lose.height = 850;

				DrawRectangleRec(hide, Fade(BLACK, 0.79999999));

				DrawTexture(GameOver_img_lose, 150, 100, WHITE);

				DrawRectangleRounded(Play_Again, 7, 7, YELLOW);
				DrawText("Play again", 590, 875, 50, WHITE);

				DrawRectangleRounded(Exit, 7, 7, RED);
				DrawText("Quit", 1030, 875, 65, WHITE);

				if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, Play_Again))
				{
					playAgain = 1;

				}
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

			DrawRectangleRounded(Play_Again, 7, 7, YELLOW);
			DrawText("Play again", 590, 875, 50, WHITE);

			DrawRectangleRounded(Exit, 7, 7, RED);
			DrawText("Quit", 1030, 875, 65, WHITE);

			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, Play_Again))
			{
				playAgain = 1;

			}
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, Exit))
			{
				exit(0);

			}
		}
		if (playAgain)
		{

			Menu_object.Menu_checker = 1;
			Menu_object.If_it_is_not_chosen_an_option = 1;
			you_win = 0;
			you_lose = 0;
			Menu_object.Exit = 0;
			Menu_object.Settings_option = 0;
			Menu_object.Play = 0;
			Menu_object.Rules_option = 0;
			playAgain = 0;
		}
		if (checkToStopMovement == 0)
		{
			if (help::idleAnims[0] && finish_attack)
			{

			DrawTextureRec(Attack_left, RectLeft, hero.Hero_obj.HeroPos, WHITE);
			}
			else if (help::idleAnims[1] && finish_attack)
			{

			DrawTextureRec(Attack_right, RectRight, hero.Hero_obj.HeroPos, WHITE);
			}
			else if (help::idleAnims[2] && finish_attack)
			{
			DrawTextureRec(Attack_up, RectUp, hero.Hero_obj.HeroPos, WHITE);

			}
		}

	}
	void Check(Arrows& hero)
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
		else if ((hero.Hero_obj.HeroPos.x >= PosBoss.x && hero.Hero_obj.HeroPos.x <= PosBoss.x + ClipBoss.width) &&
			(hero.Hero_obj.HeroPos.y <= PosBoss.y + ClipBoss.height))
		{
			//atacks
			if (IsKeyPressed(KEY_F) or IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				healthBarBoss -= AtackHero;
				check_attack = 1;
				finish_attack = 1;
				checkToStopMovement = 0;
			}
			if (check_attack)
			{
				if (help::idleAnims[0] && finish_attack)
				{
					if (Attack_counter == 5)
					{
						RectLeft.x += (float)Attack_left.width / 3;
						Attack_counter = 0;
					}
					if (RectLeft.x >= Attack_left.width)
					{
						RectLeft.x = 0;
						finish_attack = 0;
						checkToStopMovement = 1;
					}
					Attack_counter++;
				}
				else if (help::idleAnims[1] && finish_attack)
				{
					if (Attack_counter == 5)
					{
						RectRight.x -= (float)Attack_right.width / 3;
						Attack_counter = 0;
					}
					if (RectRight.x <= 0)
					{
						RectRight.x = Attack_right.width;
						finish_attack = 0;
						checkToStopMovement = 1;
					}
					Attack_counter++;
				}
				else if (help::idleAnims[2] && finish_attack)
				{
					if (Attack_counter == 5)
					{
						RectUp.x += (float)Attack_up.width / 3;
						Attack_counter = 0;
					}
					if (RectUp.x >= Attack_up.width)
					{
						RectUp.x = 0;
						finish_attack = 0;
						checkToStopMovement = 1;
					}
					Attack_counter++;
				}
			}
			healthBarHero -= AtackBoss;


		}

	}
	void Unload()
	{
		//unload textures
		UnloadTexture(finalBG);
		UnloadTexture(boss);
		UnloadTexture(Attack_left);
		UnloadTexture(Attack_right);
		UnloadTexture(Attack_up);
	}
};