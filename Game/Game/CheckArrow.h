#pragma once
#include "Namespace.h"
#include "DrawHero.h"
#include "Background.h"
class Arrows{
public:
	Hero Hero_obj;
	Background moveBG;
	void checkArrows()
	{
		if (IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT))
		{
			Hero_obj.HeroPos.x -= 5;
			if (!(moveBG.bg_pos.x <= 0) && Hero_obj.HeroPos.x < GetScreenWidth() - 200)
			{
				moveBG.bg_pos.x -= 20;
			}

		}
		else if (IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT))
		{
			Hero_obj.HeroPos.x += 5;
			if (!(moveBG.bg_pos.x >= GetScreenWidth()) && Hero_obj.HeroPos.x > 200)
			{
				moveBG.bg_pos.x += 20;
			}
		}
		if (IsKeyDown(KEY_W) or IsKeyDown(KEY_UP))
		{
			Hero_obj.HeroPos.y -= 5;
			if (!(moveBG.bg_pos.y <= 0) && Hero_obj.HeroPos.x < GetScreenHeight() - 200)
			{
				moveBG.bg_pos.y -= 20;
			}
		}
		else if (IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN))
		{
			Hero_obj.HeroPos.y += 5;
			if (!(moveBG.bg_pos.y >= GetScreenHeight()) && Hero_obj.HeroPos.y > 200)
			{
				moveBG.bg_pos.y += 20;
			}
		}
		
	}
	
	
};
