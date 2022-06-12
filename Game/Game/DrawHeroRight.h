#pragma once
#include "include.h"
class HeroRight {
	private:
		int fpscouter = 0;
		
		Vector2 HeroPos = { 200, 100 };
		Texture2D hero = LoadTexture("../images/heroRight.png");
		Rectangle HeroClip = { 0, 0, (float) hero.width / 6, (float)hero.height};
	public:
	
	int DrawRight()
	{
		try {
			
				DrawTextureRec(hero, HeroClip, HeroPos, WHITE);
				throw 0;
		}
		catch (int except)
		{
			if (except == 0)
				return except;
			else
				return 1;
		}
	}
	void UpdateRight()
	{
		fpscouter++;
		if (fpscouter == 10)
		{
			HeroClip.x += hero.width / 6;
			fpscouter = 0;
		}
		if (HeroClip.x == hero.width)
		{
			HeroClip.x = 0;
		}
	}
	void UnloadHeroRight()
	{
		UnloadTexture(hero);
	}
};