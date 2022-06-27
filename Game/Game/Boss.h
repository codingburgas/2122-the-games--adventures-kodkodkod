#pragma once
#include "raylib.h"
#include "CheckArrow.h"
#include "Namespace.h"
#include "Menu.h"
class Boss {
	int fpscounter = 0;
	int Attack_counter = 0;
	//texture for boss
	Texture2D boss = LoadTexture("../images/boss.png");
	//texture for background
	Texture2D finalBG = LoadTexture("../images/backgrounds/finalmap.png");

public:
	//rectangle for boss
	//boss position vector
	Vector2 PosBoss = { (float)GetScreenWidth() / 2, 100 };
	float healthBarBoss = 300;
	float healthBarHero = 200;
	float AtackBoss = 1;
	float AtackHero = 25;
	bool you_win = 0;
	bool you_lose = 0;
	bool playAgain = 0;
	bool checkToStopMovement = 1;
	bool check_attack = 0;
	bool not_play_again = 1;
	bool finish_attack = 1;

	Rectangle HealthBoss = { (float)PosBoss.x, (float)PosBoss.y, (float)healthBarBoss, 10 };
	Rectangle HealthHero = { 0,0, (float)healthBarHero,10 };
	Rectangle ClipBoss = { 0,0, (float)boss.width / 3, (float)boss.height };

	Texture2D GameOver_img_lose = LoadTexture("../images/GameOver_you_lose.png");
	Texture2D GameOver_img_win = LoadTexture("../images/GameOver_you_win.png");

	Texture2D Attack_left = LoadTexture("../images/Hero/attackSprite_left.png");
	Texture2D Attack_up = LoadTexture("../images/Hero/attackSprite_up.png");
	Texture2D Attack_right = LoadTexture("../images/Hero/attackSprite_right.png");

	Rectangle RectLeft= { 0, 0, (float)Attack_left.width /3, (float)Attack_left.height };
	Rectangle RectUp = { 0, 0, (float)Attack_up.width /3, (float)Attack_up.height };
	Rectangle RectRight = { (float)Attack_right.width, 0, (float)Attack_right.width /3, (float)Attack_right.height };

	Vector2 Close;
	Vector2 mousePoint;

	Rectangle Play_Again = { 580,850, 275, 100 };
	Rectangle Exit = { 950,850, 275, 100 };

	Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };

	void Update(Arrows& object);
	void Draw(Menu& Menu_object, Arrows& hero);
	void Check(Arrows& hero);
	void Unload();
};