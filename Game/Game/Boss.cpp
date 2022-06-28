#include "Boss.h"
void Boss::Update(Arrows& object)
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
void Boss::Draw(Menu& Menu_object, Arrows& hero)
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

		
			DrawRectangleRounded(Exit, 7, 7, RED);
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

	

		DrawRectangleRounded(Exit, 7, 7, RED);
		DrawText("Quit", 830, 875, 65, WHITE);

	
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
			if (!(hero.Hero_obj.HeroPos.x >= PosBoss.x && hero.Hero_obj.HeroPos.x <= PosBoss.x + ClipBoss.width) || (hero.Hero_obj.HeroPos.y > PosBoss.y + ClipBoss.height))
			{
				finish_attack = 0;
				checkToStopMovement = 1;
				check_attack = 0;
			}else
			DrawTextureRec(Attack_left, RectLeft, hero.Hero_obj.HeroPos, WHITE);
			
		}
		else if (help::idleAnims[1] && finish_attack)
		{
			if (!(hero.Hero_obj.HeroPos.x >= PosBoss.x && hero.Hero_obj.HeroPos.x <= PosBoss.x + ClipBoss.width) || (hero.Hero_obj.HeroPos.y > PosBoss.y + ClipBoss.height))
			{
				finish_attack = 0;
				checkToStopMovement = 1;
				check_attack = 0;
			}
			else
			DrawTextureRec(Attack_right, RectRight, hero.Hero_obj.HeroPos, WHITE);
			
		}
		else if (help::idleAnims[2] || help::idleAnims[3]  && finish_attack)
		{
			if (!(hero.Hero_obj.HeroPos.x >= PosBoss.x && hero.Hero_obj.HeroPos.x <= PosBoss.x + ClipBoss.width) || (hero.Hero_obj.HeroPos.y > PosBoss.y + ClipBoss.height))
			{
				finish_attack = 0;
				checkToStopMovement = 1;
				check_attack = 0;
				
			}
			else
			DrawTextureRec(Attack_up, RectUp, hero.Hero_obj.HeroPos, WHITE);
			

		}
	}

}
void Boss::Check(Arrows& hero)
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
	if ((hero.Hero_obj.HeroPos.x >= PosBoss.x && hero.Hero_obj.HeroPos.x <= PosBoss.x + ClipBoss.width) &&
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
			else if (help::idleAnims[2] || help::idleAnims[3] && finish_attack)
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
void Boss::Unload()
{
	//unload textures
	UnloadTexture(finalBG);
	UnloadTexture(boss);
	UnloadTexture(Attack_left);
	UnloadTexture(Attack_right);
	UnloadTexture(Attack_up);
}