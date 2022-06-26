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
	float healthBarBoss = 400;
	float healthBarHero = 200;
	float AtackBoss = 0.5;
	float AtackHero = 80;
	Rectangle HealthBoss = { (float)PosBoss.x, (float)PosBoss.y, (float)healthBarBoss, 10};
	Rectangle HealthHero = {0,0, (float)healthBarHero,10};
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
	void Draw()
	{
		//draw everything
		DrawTexture(finalBG, 0, 0, WHITE);
		DrawTextureRec(boss, ClipBoss, PosBoss, WHITE);
		DrawRectangleRec(HealthBoss, RED);
		DrawRectangleRec(HealthHero, RED);
	}
	void Check(Arrows &hero)
	{
		//gameover for losing
		if (healthBarHero <= 0)
		{
			//code
		}
		//gameover for winning
		if (healthBarBoss <= 0)
		{
			//code
		}
		if ((hero.Hero_obj.HeroPos.x >= PosBoss.x && hero.Hero_obj.HeroPos.x <= PosBoss.x + ClipBoss.width) && 
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