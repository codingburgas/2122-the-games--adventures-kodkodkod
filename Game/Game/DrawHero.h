#pragma once
#include "raylib.h"
using namespace std;
class Hero {
private:
	int fpscouter = 0;
	//textures for hero looking side
	Texture2D heroDown = LoadTexture("../images/Hero/heroFront.png");
	Texture2D heroLeft = LoadTexture("../images/Hero/heroLeft.png");
	Texture2D heroRight = LoadTexture("../images/Hero/heroRight.png");
	Texture2D heroUp = LoadTexture("../images/Hero/heroBack.png");

	//idle textures
	Texture2D heroDownIdle = LoadTexture("../images/idles/backIdle.png");
	Texture2D heroLeftIdle = LoadTexture("../images/idles/leftIdle.png");
	Texture2D heroRightIdle = LoadTexture("../images/idles/rightIdle.png");
	Texture2D heroUpIdle = LoadTexture("../images/idles/frontIdle.png");
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
	
	void UpdateLeft();
	void UpdateRight();
	void UpdateUp();
	void UpdateDown();

	void DrawLeft();
	void DrawRight();
	void DrawUp();
	void DrawDown();

	void IdleDown();
	void IdleLeft();
	void IdleUp();
	void IdleRight();

	void UpdateRightIdle();
	void UpdateUpIdle();
	void UpdateDownIdle();
	void UpdateLeftIdle();

	void UnloadHero();
};