#pragma once
#include"include.h"
#include "Jump.h"
#include "DrawHeroRight.h"
#include "DrawHeroLeft.h"
class Arrows{
public:
	bool LeftHero = 0;
	bool RightHero = 0;
	
	HeroRight Hero_obj_right;
	HeroLeft Hero_obj_left;
	void checkArrows()
	{
<<<<<<< HEAD
		
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
=======
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
>>>>>>> 336db5f8fdcc196e6a36521ce5ff2fc003a2167f
		
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
