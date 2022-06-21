#pragma once
class Hero {
private:
	int fpscouter = 0;
	Texture2D heroDown = LoadTexture("../images/heroFront.png");
	Texture2D heroLeft = LoadTexture("../images/heroLeft.png");
	Texture2D heroRight = LoadTexture("../images/heroRight.png");
	Texture2D heroUp = LoadTexture("../images/heroBack.png");
public:
	Rectangle HeroClip = { (float)heroLeft.width, 0, (float)heroLeft.width / 6, (float)heroLeft.height };
	
	Vector2 HeroPos = {800, 700};

	
	void DrawLeft()
	{
		HeroClip.width = heroLeft.width / 6.1;
		DrawTextureRec(heroLeft, HeroClip, HeroPos, WHITE);
		
	}
	void DrawRight()
	{
		HeroClip.width = heroRight.width / 6.1;
		DrawTextureRec(heroRight, HeroClip, HeroPos, WHITE);

		
	}
	void UpdateLeft()
	{
		fpscouter++;
		if (fpscouter == 10)
		{
			HeroClip.x -= (float)heroLeft.width / 6.1;
			fpscouter = 0;
		}
		if (HeroClip.x <= 0)
		{
			HeroClip.x = heroLeft.width;
		}
	}
	void UpdateRight()
	{
		fpscouter++;
		if (fpscouter == 10)
		{
			HeroClip.x += heroRight.width / 6.1;
			fpscouter = 0;
		}
		if (HeroClip.x >= heroRight.width)
		{
			HeroClip.x = 0;
		}
	}
	//UP
	void DrawUp()
	{
		HeroClip.width = heroUp.width / 3;
		DrawTextureRec(heroUp, HeroClip, HeroPos, WHITE);


	}
	void UpdateUp()
	{
		fpscouter++;
		if (fpscouter == 10)
		{
			HeroClip.x -= (float)heroUp.width / 2.9;
			fpscouter = 0;
		}
		if (HeroClip.x <= 0)
		{
			HeroClip.x = heroUp.width;
		}
	}
	//Down
	void DrawDown()
	{
		HeroClip.width = heroUp.width / 3;
		DrawTextureRec(heroDown, HeroClip, HeroPos, WHITE);


	}
	void Idle()
	{
		DrawTextureRec(heroDown, {0, 0, (float)heroDown.width / 3, (float)heroRight.height}, HeroPos, WHITE);

	}
	void UnloadHero()
	{
		UnloadTexture(heroLeft);
		UnloadTexture(heroRight);
		UnloadTexture(heroUp);
		UnloadTexture(heroDown);
	}
};