#pragma once
#include"include.h"
#include "DrawHeroRight.h"
#include "DrawHeroLeft.h"
class Arrows {
public:
	bool LeftHero = 0;
	bool RightHero = 0;
	HeroRight Hero_obj_right;
	HeroLeft Hero_obj_left;
	void checkArrows()
	{
		if (IsKeyPressed(KEY_A))
		{
			LeftHero = 1;
			RightHero = 0;
		}
		else if (IsKeyPressed(KEY_D))
		{
			RightHero = 1;
			LeftHero = 0;
		}
	}
	void StartMovement()
	{
		if (LeftHero)
		{
			Hero_obj_left.DrawLeft();

			Hero_obj_left.UpdateLeft();
		}
		else if (RightHero)
		{
			Hero_obj_right.DrawRight();

			Hero_obj_right.UpdateRight();
		}
		else
		{
			Hero_obj_right.DrawRight();

			Hero_obj_right.UpdateRight();
		}
	}
	
};
