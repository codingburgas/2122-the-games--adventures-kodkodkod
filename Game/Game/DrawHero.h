#pragma once
using namespace std;
class Hero {
private:
	int fpscouter = 0;
	Texture2D heroDown = LoadTexture("../images/heroFront.png");
	Texture2D heroLeft = LoadTexture("../images/heroLeft.png");
	Texture2D heroRight = LoadTexture("../images/heroRight.png");
	Texture2D heroUp = LoadTexture("../images/heroBack.png");
public:
	Rectangle HeroClipLeft = { (float)heroLeft.width, 0, (float)heroLeft.width / 6, (float)heroLeft.height };
	Rectangle HeroClipRight = { 0, 0, (float)heroRight.width / 6, (float)heroRight.height };
	Rectangle HeroClipUp = { (float)heroUp.width, 0, (float)heroUp.width / 3, (float)heroUp.height };
	Rectangle HeroClipDown = { (float)heroDown.width, 0, (float)heroDown.width / 3, (float)heroDown.height };
	
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
		HeroClipUp.width = heroUp.width / 2.9;
		DrawTextureRec(heroUp, HeroClipUp, HeroPos, WHITE);


	}
	void UpdateUp()
	{
		if (fpscouter == 10)
		{
			HeroClipUp.x -= (float)heroUp.width / 2.9;
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

		DrawTextureRec(heroDown, HeroClipDown, HeroPos, WHITE);


	}
	void UpdateDown()
	{
		if (fpscouter == 10)
		{
			HeroClipDown.x -= (float)heroDown.width / 2.9;
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
		DrawTextureRec(heroDown, {0, 0, (float)heroDown.width / 3, (float)heroDown.height}, HeroPos, WHITE);

	}
	void IdleLeft()
	{
		DrawTextureRec(heroLeft, { 0, 0, (float)heroLeft.width / 6, (float)heroLeft.height }, HeroPos, WHITE);

	}
	void IdleUp()
	{
		DrawTextureRec(heroUp, { 0, 0, (float)heroUp.width / 3, (float)heroUp.height }, HeroPos, WHITE);

	}
	void IdleRight()
	{
		DrawTextureRec(heroRight, { 0, 0, (float)heroRight.width / 6, (float)heroRight.height }, HeroPos, WHITE);

	}
	void UnloadHero()
	{
		UnloadTexture(heroLeft);
		UnloadTexture(heroRight);
		UnloadTexture(heroUp);
		UnloadTexture(heroDown);
	}
};