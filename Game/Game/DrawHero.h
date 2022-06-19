#pragma once
class Hero {
private:
	int fpscouter = 0;
public:
	Texture2D hero = LoadTexture("../images/heroLeft.png");
	Rectangle HeroClip = { (float)hero.width, 0, (float)hero.width / 6 + 10, (float)hero.height };
	Vector2 HeroPos = {800, 700};


	void DrawLeft()
	{
		hero = LoadTexture("../images/heroLeft.png");
		
		DrawTextureRec(hero, HeroClip, HeroPos, WHITE);
		
		
	}
	void DrawRight()
	{
		hero = LoadTexture("../images/heroRight.png");
		
		DrawTextureRec(hero, HeroClip, HeroPos, WHITE);

		
	}
	void UpdateLeft()
	{
		fpscouter++;
		if (fpscouter == 10)
		{
			HeroClip.x -= (float)hero.width / 6 + 10;
			fpscouter = 0;
		}
		if (HeroClip.x <= 0)
		{
			HeroClip.x = hero.width;
		}
	}
	void UpdateRight()
	{
		fpscouter++;
		if (fpscouter == 10)
		{
			HeroClip.x += hero.width / 6 + 10;
			fpscouter = 0;
		}
		if (HeroClip.x >= hero.width)
		{
			HeroClip.x = 0;
		}
	}
	//UP
	void DrawUp()
	{
		hero = LoadTexture("../images/heroBack.png");
		
		DrawTextureRec(hero, HeroClip, HeroPos, WHITE);


	}
	void UpdateUp()
	{
		fpscouter++;
		if (fpscouter == 10)
		{
			HeroClip.x -= (float)hero.width / 3;
			fpscouter = 0;
		}
		if (HeroClip.x <= 0)
		{
			HeroClip.x = hero.width;
		}
	}
	//Down
	void DrawDown()
	{
		hero = LoadTexture("../images/heroFront.png");
		DrawTextureRec(hero, HeroClip, HeroPos, WHITE);


	}
	void UnloadHero()
	{
		UnloadTexture(hero);
	}
};