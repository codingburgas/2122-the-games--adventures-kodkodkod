#include"DrawHero.h"

void Hero::DrawLeft()
{

	DrawTextureRec(heroLeft, HeroClipLeft, HeroPos, WHITE);

}
void Hero::DrawRight()
{

	DrawTextureRec(heroRight, HeroClipRight, HeroPos, WHITE);


}
void Hero::UpdateLeft()
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
void Hero::UpdateRight()
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
void Hero::DrawUp()
{
	HeroClipUp.width = heroUp.width / 3;
	DrawTextureRec(heroUp, HeroClipUp, HeroPos, WHITE);


}
void Hero::UpdateUp()
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
void Hero::DrawDown()
{
	HeroClipUp.width = heroUp.width / 3;
	DrawTextureRec(heroDown, HeroClipDown, HeroPos, WHITE);


}
void Hero::UpdateDown()
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
void Hero::IdleDown()
{
	DrawTextureRec(heroDownIdle, HeroClipDownIdle, HeroPos, WHITE);

}
void Hero::IdleLeft()
{
	DrawTextureRec(heroLeftIdle, HeroClipLeftIdle, HeroPos, WHITE);

}
void Hero::IdleUp()
{
	DrawTextureRec(heroUpIdle, HeroClipUpIdle, HeroPos, WHITE);

}
void Hero::IdleRight()
{
	DrawTextureRec(heroRightIdle, HeroClipRightIdle, HeroPos, WHITE);

}
void Hero::UpdateRightIdle()
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
void Hero::UpdateUpIdle()
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
void Hero::UpdateDownIdle()
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
void Hero::UpdateLeftIdle()
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
void Hero::UnloadHero()
{
	//unload everything
	UnloadTexture(heroLeft);
	UnloadTexture(heroRight);
	UnloadTexture(heroUp);
	UnloadTexture(heroDown);

	UnloadTexture(heroLeftIdle);
	UnloadTexture(heroRightIdle);
	UnloadTexture(heroUpIdle);
	UnloadTexture(heroDownIdle);
}