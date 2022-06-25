#pragma once
#include"raylib.h"
#include "CheckArrow.h"
class Boss{
	int fpscounter = 0;
	Texture2D Boss = LoadTexture("");
public:
	Rectangle HealthClipBoss = {0,0,0,0};
	Vector2 HealthPosBoss = {100, 200};
	int healthBarBoss = 100;
	int healthBarHero = 100;
	int AtackBoss = 100;
	int AtackHero = 100;
	Rectangle HealthRec = {};
	Vector2 HealthPosHero;
	void Update(Arrows& object)
	{
		HealthPosHero.x = object.Hero_obj.HeroPos.x;
		HealthPosHero.y = object.Hero_obj.HeroPos.y;
	}
};