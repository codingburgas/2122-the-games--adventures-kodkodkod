#pragma once
using namespace std;
class Hero {
private:
	int fpscouter = 0;
	Texture2D heroDown = LoadTexture("../images/Hero/heroFront.png");
	Texture2D heroLeft = LoadTexture("../images/Hero/heroLeft.png");
	Texture2D heroRight = LoadTexture("../images/Hero/heroRight.png");
	Texture2D heroUp = LoadTexture("../images/Hero/heroBack.png");

	//idle textures
	Texture2D heroDownIdle = LoadTexture("../images/Hero/backIdle.png");
	Texture2D heroLeftIdle = LoadTexture("../images/Hero/leftIdle.png");
	Texture2D heroRightIdle = LoadTexture("../images/Hero/rightIdle.png");
	Texture2D heroUpIdle = LoadTexture("../images/Hero/frontIdle.png");
public:
	Rectangle HeroClipLeft = { (float)heroLeft.width, 0, (float)heroLeft.width / 6, (float)heroLeft.height };
	Rectangle HeroClipRight = { 0, 0, (float)heroRight.width / 6, (float)heroRight.height };
	Rectangle HeroClipUp = { (float)heroUp.width, 0, (float)heroUp.width / 3, (float)heroUp.height };
	Rectangle HeroClipDown = { (float)heroDown.width, 0, (float)heroDown.width / 3, (float)heroDown.height };

	//idle rectangles
	Rectangle HeroClipLeftIdle = { (float)heroLeftIdle.width, 0, (float)heroLeftIdle.width / 3, (float)heroLeftIdle.height };
	Rectangle HeroClipRightIdle = { 0, 0, (float)heroRightIdle.width / 3, (float)heroRightIdle.height };
	Rectangle HeroClipUpIdle = { (float)heroUpIdle.width, 0, (float)heroUpIdle.width / 3, (float)heroUpIdle.height };
	Rectangle HeroClipDownIdle = { (float)heroDownIdle.width, 0, (float)heroDownIdle.width / 3, (float)heroDownIdle.height };
	
	Vector2 HeroPos = {800, 700};
	
	void DrawLeft()
	{

		DrawTextureRec(heroLeft, HeroClipLeft, HeroPos, WHITE);
		
	}
	void DrawRight()
	{
		
		DrawTextureRec(heroRight, HeroClipRight, HeroPos, WHITE);

		
	}
	void UpdateLeft()
	{
		if (fpscouter == 10)
		{
			HeroClipLeft.x -= (float)heroLeft.width / 6;
			fpscouter = 0;
		}
		if (HeroClipLeft.x <= 0)
		{
			HeroClipLeft.x = heroLeft.width;
		}
		fpscouter++;

	}
	void UpdateRight()
	{

		if (fpscouter == 10)
		{
			HeroClipRight.x += heroRight.width / 6;
			fpscouter = 0;
		}
		if (HeroClipRight.x >= heroRight.width)
		{
			HeroClipRight.x = 0;
		}
		fpscouter++;

	}
	//UP
	void DrawUp()
	{
		HeroClipUp.width = heroUp.width / 3;
		DrawTextureRec(heroUp, HeroClipUp, HeroPos, WHITE);


	}
	void UpdateUp()
	{
		if (fpscouter == 10)
		{
			HeroClipUp.x -= (float)heroUp.width / 3;
			fpscouter = 0;
		}
		if (HeroClipUp.x <= 0)
		{
			HeroClipUp.x = heroUp.width;
		}
		fpscouter++;

	}
	//Down
	void DrawDown()
	{
		HeroClipUp.width = heroUp.width / 3;
		DrawTextureRec(heroDown, HeroClipDown, HeroPos, WHITE);


	}
	void UpdateDown()
	{
		if (fpscouter == 10)
		{
			HeroClipDown.x -= (float)heroDown.width / 3;
			fpscouter = 0;
		}
		if (HeroClipDown.x <= 0)
		{
			HeroClipDown.x = heroUp.width;
		}
		fpscouter++;

	}
	void IdleDown()
	{
		DrawTextureRec(heroDownIdle, HeroClipDownIdle, HeroPos, WHITE);

	}
	void IdleLeft()
	{
		DrawTextureRec(heroLeftIdle, HeroClipLeftIdle, HeroPos, WHITE);

	}
	void IdleUp()
	{
		DrawTextureRec(heroUpIdle, HeroClipUpIdle, HeroPos, WHITE);

	}
	void IdleRight()
	{
		DrawTextureRec(heroRightIdle, HeroClipRightIdle, HeroPos, WHITE);

	}
	void UpdateRightIdle()
	{
		if (fpscouter == 10)
		{
			HeroClipRightIdle.x += (float)heroRightIdle.width / 3;
			fpscouter = 0;
		}
		if (HeroClipRightIdle.x >= heroRightIdle.width)
		{
			HeroClipRightIdle.x = 0;
		}
		fpscouter++;
	}
	void UpdateUpIdle()
	{
		if (fpscouter == 10)
		{
			HeroClipUpIdle.x -= (float)heroUpIdle.width / 3;
			fpscouter = 0;
		}
		if (HeroClipUpIdle.x <= 0)
		{
			HeroClipUpIdle.x = heroUpIdle.width;
		}
		fpscouter++;
	}
	void UpdateDownIdle()
	{
		if (fpscouter == 10)
		{
			HeroClipDownIdle.x -= (float)heroDownIdle.width / 3;
			fpscouter = 0;
		}
		if (HeroClipDownIdle.x <= 0)
		{
			HeroClipDownIdle.x = heroDownIdle.width;
		}
		fpscouter++;
	}
	void UpdateLeftIdle()
	{
		if (fpscouter == 10)
		{
			HeroClipLeftIdle.x -= (float)heroLeftIdle.width / 3;
			fpscouter = 0;
		}
		if (HeroClipLeftIdle.x <= 0)
		{
			HeroClipLeftIdle.x = heroLeftIdle.width;
		}
		fpscouter++;
	}
	void UnloadHero()
	{
		UnloadTexture(heroLeft);
		UnloadTexture(heroRight);
		UnloadTexture(heroUp);
		UnloadTexture(heroDown);

		UnloadTexture(heroLeftIdle);
		UnloadTexture(heroRightIdle);
		UnloadTexture(heroUpIdle);
		UnloadTexture(heroDownIdle);
	}
};