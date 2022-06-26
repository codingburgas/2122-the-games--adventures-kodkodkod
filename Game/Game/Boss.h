#pragma once
#include"raylib.h"
#include "CheckArrow.h"
#include "Namespace.h"
class Boss{
	int fpscounter = 0;
	Texture2D boss = LoadTexture("../images/boss.png");
	Texture2D finalBG = LoadTexture("../images/backgrounds/finalmap.png");
	Texture2D AttackLeft = LoadTexture("../images/Hero/attackSprite_left.png");
	Texture2D AttackUp = LoadTexture("../images/Hero/attackSprite_up.png");
	Texture2D AttackRight = LoadTexture("../images/Hero/attackSprite_right.png");

	Rectangle AttackLeftClip = {0,0, (float)AttackLeft.width / 3, (float)AttackLeft.height };
	Rectangle AttackUpClip = {0,0, (float)AttackUp.width / 3, (float)AttackUp.height};
	Rectangle AttackRightClip = { (float)AttackRight.width, 0, (float)AttackRight.width / 3, (float)AttackRight.height};
	
public:
	
	Rectangle ClipBoss = {0,0, (float)boss.width / 3, (float)boss.height};
	Vector2 PosBoss = {(float)GetScreenWidth() / 2, 100};
	float healthBarBoss = 100;
	float healthBarHero = 200;
	float AtackBoss = 0.5;
	float AtackHero = 5;
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
		DrawTexture(finalBG, 0, 0, WHITE);
		DrawTextureRec(boss, ClipBoss, PosBoss, WHITE);
		DrawRectangleRec(HealthBoss, RED);
		DrawRectangleRec(HealthHero, RED);
	}
	void Check(Arrows &hero)
	{
		if (healthBarHero <= 0)
		{
			//code
		}
		if (healthBarBoss <= 0)
		{
			//code
		}
		if ((hero.Hero_obj.HeroPos.x >= PosBoss.x && hero.Hero_obj.HeroPos.x <= PosBoss.x + ClipBoss.width) && 
			(hero.Hero_obj.HeroPos.y <= PosBoss.y + ClipBoss.height))
		{
			
			if (IsKeyPressed(KEY_E))
			{
				healthBarBoss -= AtackHero;
			}
			if (help::idleAnims[0])
			{
				
				DrawTextureRec(AttackLeft, AttackLeftClip, hero.Hero_obj.HeroPos, WHITE);
				AttackLeftClip.x += AttackLeftClip.width;
				DrawTextureRec(AttackLeft, AttackLeftClip, hero.Hero_obj.HeroPos, WHITE);
				AttackLeftClip.x += AttackLeftClip.width;
				DrawTextureRec(AttackLeft, AttackLeftClip, hero.Hero_obj.HeroPos, WHITE);
				AttackLeftClip.x = 0;
			}
						
			if (help::idleAnims[1])
			{
				DrawTextureRec(AttackUp, AttackUpClip, hero.Hero_obj.HeroPos, WHITE);
				AttackUpClip.x += AttackUpClip.width;
				DrawTextureRec(AttackLeft, AttackUpClip, hero.Hero_obj.HeroPos, WHITE);
				AttackUpClip.x += AttackUpClip.width;
				DrawTextureRec(AttackUp, AttackUpClip, hero.Hero_obj.HeroPos, WHITE);
				AttackUpClip.x = 0;

			}
						
			if (help::idleAnims[2])
			{
				DrawTextureRec(AttackRight, AttackRightClip, hero.Hero_obj.HeroPos, WHITE);
				AttackRightClip.x -= AttackRightClip.width;
				DrawTextureRec(AttackLeft, AttackRightClip, hero.Hero_obj.HeroPos, WHITE);
				AttackRightClip.x -= AttackRightClip.width;
				DrawTextureRec(AttackRight, AttackRightClip, hero.Hero_obj.HeroPos, WHITE);
				AttackRightClip.x = 0;

			}
						
			if (help::idleAnims[3])
			{
				DrawTextureRec(AttackLeft, AttackLeftClip, hero.Hero_obj.HeroPos, WHITE);
				AttackLeftClip.x += AttackLeftClip.width;
				DrawTextureRec(AttackLeft, AttackLeftClip, hero.Hero_obj.HeroPos, WHITE);
				AttackLeftClip.x += AttackLeftClip.width;
				DrawTextureRec(AttackLeft, AttackLeftClip, hero.Hero_obj.HeroPos, WHITE);
				AttackLeftClip.x = 0;
			}
			healthBarHero -= AtackBoss;
			
			
		}
		
	}
	void Unload()
	{
		UnloadTexture(finalBG);
		UnloadTexture(boss);
	}
};