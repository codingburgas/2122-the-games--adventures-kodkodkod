#pragma once
#include "Namespace.h"
#include "DrawHero.h"
#include "Background.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using namespace std;
using namespace help;
class Arrows {
public:
    Hero Hero_obj;
    Background moveBG;
    bool checker = 1;
    int LimitA = 320;
    int LimitD = 320;
    int LimitS = 120;
    int LimitW = 120;
    bool checker2 = 0;
    bool checker3 = 0;
    bool checker4 = 0;
    bool checker5 = 0;
    bool checker6 = 0;
    bool checker7 = 0;
    bool checker8 = 0;
    bool checkInput[4] = { 0, 0, 0, 0 };
    int speedBG = 100;
    int speedHero = 5;
    bool RandomKey[4] = { 0, 0, 0, 0 };
    
    
    Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };
    Texture2D Chest = LoadTexture("../images/chest.png");
    Texture2D Opened_Chest = LoadTexture("../images/opened_chest.png");
    Texture2D Key = LoadTexture("../images/Key.png");
    Rectangle Border;
    Rectangle KeyRec;
    Rectangle Door;
    Vector2 mousePoint;
    Vector2 Circlee;
    bool dia = 0;
    bool wrong_chest1 = 0, wrong_chest2 = 0, wrong_chest3 = 0, right_chest = 0;
    Rectangle chests[4];

    void SetRandomPosKey()
    {
        srand(time(0));
        int Rand = rand() % 4;
        RandomKey[Rand] = 1;
        switch (Rand)
        {
            case 0:
            {

                RandomKey[1] = 0;
                RandomKey[2] = 0;
                RandomKey[3] = 0;
                break;
            }
            case 1:
            {
                RandomKey[0] = 0;
                RandomKey[2] = 0;
                RandomKey[3] = 0;
                break;
            }
            case 2:
            {
                RandomKey[0] = 0;
                RandomKey[1] = 0;
                RandomKey[3] = 0;
                break;
            }
            case 3:
            {
                RandomKey[1] = 0;
                RandomKey[2] = 0;
                RandomKey[0] = 0;
                break;
            }
        }

    }

    void MakeChests()
    {
        mousePoint = GetMousePosition();
        chests[0] = { 320,100, 500, 350 };
        chests[1] = { (float)GetScreenWidth() - 800, 100, 500, 350 };
        chests[2] = { 200, (float)GetScreenHeight() - 450, 500, 350 };
        chests[3] = { (float)GetScreenWidth() - 800, (float)GetScreenHeight() - 450, 500, 350 };
        Door = { 450,0, 550, 150 };
        Opened_Chest.width = 1800;
        Opened_Chest.height = 850;
        Key.width = 100;
        Key.height = 200;
        
        for (int i = 0; i < 4; i++)
        {
            DrawRectangleLinesEx(chests[i], 7.5, BLANK);
        }
    }
    void checkArrows()
    {
        int count = 0;
        for (int i = 0; i < 4; i++)
        {
            if (checkInput[i])
            {
                count++;
                if (count == 2)
                {
                    speedHero = 2;
                    speedBG = 150;
                    dia = 1;
                    break;
                }
                else {
                    dia = 0;
                    speedHero = 5;
                    speedBG = 100;
                    for (int i = 0; i < 4; i++)
                    {
                        if (checkInput[i])
                            idleAnims[i] = 1;
                        else
                            idleAnims[i] = 0;
                    }
                }
            }
        }
        if (IsKeyDown(KEY_A) or IsKeyDown(KEY_LEFT))
        {
            checkInput[1] = 0;
            checkInput[0] = 1;
            if (!(Hero_obj.HeroPos.x <= LimitA))
            {
                Hero_obj.HeroPos.x -= speedHero;
            }
            if (!(moveBG.bg_pos.x <= 0) && Hero_obj.HeroPos.x < (GetScreenWidth() - Hero_obj.HeroClipLeft.width) - 200)
            {
                moveBG.bg_pos.x -= GetScreenWidth() / speedBG;
            }
        }
        else
        {
            checkInput[0] = 0;
        }
        if (IsKeyDown(KEY_D) or IsKeyDown(KEY_RIGHT))
        {
            checkInput[1] = 1;
            checkInput[0] = 0;
            if (!(Hero_obj.HeroPos.x >= (GetScreenWidth() - Hero_obj.HeroClipRight.width) - LimitD))
            {
                Hero_obj.HeroPos.x += speedHero;
            }
            if (!(moveBG.bg_pos.x >= GetScreenWidth()) && Hero_obj.HeroPos.x > 200)
            {
                moveBG.bg_pos.x += GetScreenWidth() / speedBG;
            }
        }
        else
        {
            checkInput[1] = 0;
        }
        if (IsKeyDown(KEY_W) or IsKeyDown(KEY_UP))
        {
            checkInput[3] = 0;
            checkInput[2] = 1;
            if (!(Hero_obj.HeroPos.y <= LimitW))
            {
                Hero_obj.HeroPos.y -= speedHero;
            }
            if (!(moveBG.bg_pos.y <= 0) && Hero_obj.HeroPos.y < (GetScreenHeight() - Hero_obj.HeroClipUp.height) - 200)
            {
                moveBG.bg_pos.y -= GetScreenHeight() / speedBG;
            }
        }
        else
        {
            checkInput[2] = 0;
        }
        if (IsKeyDown(KEY_S) or IsKeyDown(KEY_DOWN))
        {
            checkInput[3] = 1;
            checkInput[2] = 0;
            if (!(Hero_obj.HeroPos.y >= (GetScreenHeight() - Hero_obj.HeroClipDown.height) - LimitS))
            {
                Hero_obj.HeroPos.y += speedHero;
            }
            if (!(moveBG.bg_pos.y >= GetScreenHeight()) && Hero_obj.HeroPos.y > 200)
            {
                moveBG.bg_pos.y += GetScreenHeight() / speedBG;
            }
        }
        else
        {
            checkInput[3] = 0;
        }
        if (!(IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_S) || IsKeyDown(KEY_W) || IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_UP)))
        {
            checkInput[0] = 0;
            checkInput[1] = 0;
            checkInput[2] = 0;
            checkInput[3] = 0;
        }
        if (chests[0].width - Hero_obj.HeroPos.x > Hero_obj.HeroClipLeft.width / 2 && chests[0].height - Hero_obj.HeroPos.y > Hero_obj.HeroClipLeft.height / 2)
        {
            if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[0]))
            {
                DrawText("Press 'E' to open the chest", 10, 10, 35, WHITE);
                if (IsKeyPressed(KEY_E))
                {
                    checker2 = 1;
                }
            }
        }
        else
        {
            checker2 = 0;
        }
        if (checker6)
        {
            DrawRectangleLinesEx(Door, 7.5, BLACK);
            if (CheckCollisionPointRec(Hero_obj.HeroPos, Door) && moveBG.bg_pos.x < 450 && moveBG.bg_pos.x > 200)
            {
                Hero_obj.HeroPos = { KeyRec.x + 150, (float)GetScreenHeight() - 300 };
                moveBG.bg_pos.y = GetScreenHeight() + 200;
                moveBG.bg_pos.x = KeyRec.x - 100;
                checker5 = 1;
                checker6 = 0;
            }
        }
        Border.x = 420;
        Border.y = 60;
        Border.width = 1300;
        Border.height = 800;
        KeyRec.x = 590;
        KeyRec.y = 350;
        KeyRec.width = 125;
        KeyRec.height = 225;
        if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[1]))
        {
            DrawText("Press 'E' to open the chest", 1380, 10, 35, WHITE);
            if (IsKeyPressed(KEY_E))
            {
                checker7 = 1;
            }
        }
        else
        {
            checker7 = 0;
        }
        if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[2]))
        {
            DrawText("Press 'E' to open the chest", 10, 620, 35, WHITE);
            if (IsKeyPressed(KEY_E))
            {
                checker3 = 1;
            }
        }
        else
        {
            checker3 = 0;
        }
        if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[3]))
        {
            DrawText("Press 'E' to open the chest", 1380, 620, 35, WHITE);
            if (IsKeyPressed(KEY_E))
            {
                checker8 = 1;
            }
        }
        else
        {
            checker8 = 0;
        }
        if (checker2)
        {
            DrawTexture(Opened_Chest, 30, 30, WHITE);
            if (RandomKey[0])
            {

                DrawTexture(Key, 600, 360, WHITE);
                DrawRectangleLinesEx(KeyRec, 6, BLANK);
            }
            DrawCircle(1650, 125, 20, RED);
            DrawRectangleLinesEx(Border, 7.5, BLACK);
            DrawLine(1640, 108, 1660, 142, WHITE);
            DrawLine(1660, 108, 1640, 142, WHITE);
            Circlee.x = 1650;
            Circlee.y = 125;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Circlee, 20))
            {
                checker2 = 0;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, KeyRec))
            {
                checker6 = 1;
                checker2 = 0;
            }
        }
        if (checker7)
        {
            DrawTexture(Opened_Chest, 30, 30, WHITE);
            if (RandomKey[1])
            {

                DrawTexture(Key, 600, 360, WHITE);
                DrawRectangleLinesEx(KeyRec, 6, BLANK);
            }
            DrawCircle(1650, 125, 20, RED);
            DrawRectangleLinesEx(Border, 7.5, BLACK);
            DrawLine(1640, 108, 1660, 142, WHITE);
            DrawLine(1660, 108, 1640, 142, WHITE);
            Circlee.x = 1650;
            Circlee.y = 125;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Circlee, 20))
            {
                checker7 = 0;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, KeyRec))
            {
                checker6 = 1;
                checker7 = 0;
            }
        }
        if (checker8)
        {
            DrawTexture(Opened_Chest, 30, 30, WHITE);
            if (RandomKey[2])
            {
                
                DrawRectangleLinesEx(KeyRec, 6, BLANK);
                DrawTexture(Key, 600, 360, WHITE);
            }
            DrawCircle(1650, 125, 20, RED);
            DrawRectangleLinesEx(Border, 7.5, BLACK);
            DrawLine(1640, 108, 1660, 142, WHITE);
            DrawLine(1660, 108, 1640, 142, WHITE);
            Circlee.x = 1650;
            Circlee.y = 125;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Circlee, 20))
            {
                checker8 = 0;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, KeyRec))
            {
                checker6 = 1;
                checker8 = 0;
            }
        }
        if (checker3)
        {
            DrawTexture(Opened_Chest, 30, 30, WHITE);
            if (RandomKey[3])
            {

                DrawTexture(Key, 600, 360, WHITE);
                DrawRectangleLinesEx(KeyRec, 6, BLANK);
            }
            DrawRectangleLinesEx(Border, 7.5, BLACK);
            DrawCircle(1650, 125, 20, RED);
            DrawLine(1640, 108, 1660, 142, WHITE);
            DrawLine(1660, 108, 1640, 142, WHITE);
            Circlee.x = 1650;
            Circlee.y = 125;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, KeyRec))
            {
                checker6 = 1;
                checker3 = 0;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Circlee, 20))
            {
                checker3 = 0;
            }
        }
        
    }
};