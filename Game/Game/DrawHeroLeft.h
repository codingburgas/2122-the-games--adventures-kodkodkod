#pragma once
class HeroLeft {
private:
	int fpscouter = 0;
public:
	Texture2D hero = LoadTexture("../images/heroLeft.png");
	Rectangle HeroClip = { (float)hero.width, 0, (float)hero.width / 6, (float)hero.height };

	Vector2 HeroPos = {800, 700 };
	int DrawLeft()
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
	void UpdateLeft()
	{
		fpscouter++;
		if (fpscouter == 10)
		{
			HeroClip.x -= hero.width / 6;
			fpscouter = 0;
		}
		if (HeroClip.x == 0)
		{
			HeroClip.x = hero.width;
		}
	}
	void UnloadHeroLeft()
	{
		UnloadTexture(hero);
	}
};