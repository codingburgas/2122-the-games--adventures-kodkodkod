#pragma once
#include"CheckArrow.h"
class Jump{
public:
	bool LeftHero = 0;
	bool RightHero = 0;
	bool UpHero = 0;
	void CheckINputs()
	{
		if (IsKeyPressed(KEY_A) or IsKeyPressed(KEY_LEFT))
		{
			LeftHero = 1;
			RightHero = 0;

		}
		else if (IsKeyPressed(KEY_D) or IsKeyPressed(KEY_RIGHT))
		{
			RightHero = 1;
			LeftHero = 0;

		}
		else if (IsKeyPressed(KEY_W) or IsKeyPressed(KEY_UP))
		{
			UpHero = 1;
		}
	}
	void StartJump()
	{
		if (UpHero and LeftHero)
		{
			int start = Hero_obj_left.HeroPos.y;
			while (Hero_obj_left.HeroPos.y >= start - 60)
			{
				Hero_obj_left.HeroPos.y -= 5;
			}
			while (Hero_obj_left.HeroPos.y != start)
			{
				Hero_obj_left.HeroPos.y += 5;
			}
			UpHero = 0;
			
		}
		else if (UpHero and RightHero)
		{
			int start = Hero_obj_right.HeroPos.y;
			while (Hero_obj_right.HeroPos.y >= start - 60)
			{
				Hero_obj_right.HeroPos.y -= 5;
			}
			while (Hero_obj_right.HeroPos.y != start)
			{
				Hero_obj_right.HeroPos.y += 5;
			}
			UpHero = 0;
		}
	}
};