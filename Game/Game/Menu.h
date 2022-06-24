#pragma once
#include "include.h"
class Menu
{

public:
    
    bool checker = 1;
    bool checker2 = 1;
    bool Music_checker = 1;
    bool Music_checker2 = 0;
    bool Skin_checker = 1;
    bool Skin_checker2 = 0;
    bool Skin_checker3 = 0;
    bool Skin_checker4 = 0;
    //bool checker4 = 1;
    //bool checker5 = 1;
    Vector2 Close;
    Vector2 Skin1_Circle;
    Vector2 Skin2_Circle;
    Vector2 Skin3_Circle;
    Vector2 Skin4_Circle;
    Vector2 Music_Yes_Circle;
    Vector2 Music_No_Circle;
    Vector2 mousePoint;
    Texture2D Rules = LoadTexture("../images/Rules.png");
    Texture2D bgimg = LoadTexture("../images/Menu_Background.png");
    Texture2D Check = LoadTexture("../images/check.png");
    Texture2D set_bg = LoadTexture("../images/Settings_bg.png");
    Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };
    Rectangle back = { 850,950, 165,50 };
    Rectangle skins[4];
    bool menuZero = 0, menuOne = 0, menuTwo = 0, menuThree = 0;
    int MusicArr[2];
    void SetMenuSize()
    {
        bgimg.width = GetScreenWidth();
        bgimg.height = GetScreenHeight();

        set_bg.width = GetScreenWidth();
        set_bg.height = GetScreenHeight();
    }
    void UpdateMenu()
    {

        mousePoint = GetMousePosition();
        Rectangle options[4];

        Vector2 Rules_line_1_start = { 1540,88 };
        Vector2 Rules_line_1_end = { 1560,112 };
        Vector2 Rules_line_2_start = { 1560,88 };
        Vector2 Rules_line_2_end = { 1540,112 };

        Vector2 right_check = { 1027.5, 327.5 };
        Vector2 skins_check = { 392.5, 907.5 };

        Vector2 LineOfPlayStart = { 460,495 };
        Vector2 LineOfSettingsStart = { 17.5,100 };
        Vector2 LineOfRulesStart = { 1670,975 };
        Vector2 LineOfExitStart = { 1160, 495 };

        Vector2 LineOfPlayEnd = { 675,495 };
        Vector2 LineOfSettingsEnd = { 400,100 };
        Vector2 LineOfRulesEnd = { 1870,975 };
        Vector2 LineOfExitEnd = { 1375, 495 };

        Check.width = 45;
        Check.height = 45;

        Close.x = 1550;
        Close.y = 75;

        Music_Yes_Circle.x = 850;
        Music_Yes_Circle.y = 350;

        Music_No_Circle.x = 1050;
        Music_No_Circle.y = 350;

        Skin1_Circle.x = 392.5 + 22.5;
        Skin1_Circle.y = 907.5 + 22.5;

        Skin2_Circle.x = 742.5 + 22.5;
        Skin2_Circle.y = 907.5 + 22.5;

        Skin3_Circle.x = 1092.5 + 22.5;
        Skin3_Circle.y = 907.5 + 22.5;

        Skin4_Circle.x = 1442.5 + 22.5;
        Skin4_Circle.y = 907.5 + 22.5;

        options[0] = { 470, 400, 185, 85 };
        options[1] = { 17.5, 12, 382.5, 91 };
        options[2] = { 1660, 895, 225, 85 };
        options[3] = { 1170, 400, 185, 85 };
        if (checker2)
        {
            for (int i = 0; i < 4; i++)
            {
                DrawRectangleRec(options[i], GREEN);
            }

            DrawTexture(bgimg, 0, 0, WHITE);

            DrawLineEx(LineOfPlayStart, LineOfPlayEnd, 7, DARKPURPLE);
            DrawLineEx(LineOfSettingsStart, LineOfSettingsEnd, 7, DARKPURPLE);
            DrawLineEx(LineOfRulesStart, LineOfRulesEnd, 7, DARKPURPLE);
            DrawLineEx(LineOfExitStart, LineOfExitEnd, 7, DARKPURPLE);

            DrawText("PLAY", 500, 425, 50, ORANGE);
            DrawText("SETTINGS", 30, 50, 50, ORANGE);
            DrawText("RULES", 1700, 922.5, 50, ORANGE);
            DrawText("EXIT", 1200.5, 425, 50, ORANGE);

            DrawText("THE LAST SWORDSMAN", 290, 250, 100, ORANGE);

            

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, options[0]) && checker)
            {

                menuZero = true;
                menuOne = 0;
                menuTwo = 0;
                menuThree = 0;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, options[1]) && checker)
            {

                menuOne = true;
                menuZero = 0;
                menuTwo = 0;
                menuThree = 0;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, options[2]) && checker)
            {
                menuTwo = true;
                menuOne = 0;
                menuZero = 0;
                menuThree = 0;
            }
            else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, options[3]) && checker)
            {
                menuThree = true;
                menuOne = 0;
                menuZero = 0;
                menuTwo = 0;
            }
        }
        if (menuOne)
        {
            checker2 = 0;
            DrawTexture(set_bg, 0, 0, WHITE);
            DrawText("Settings", 700, 25, 125, LIGHTGRAY);
            DrawText("Music", 850, 185, 75, LIGHTGRAY);
            DrawText("Yes", 820, 275, 35, LIGHTGRAY);
            DrawText("No", 1030, 275, 35, LIGHTGRAY);

            for (int i = 0; i < 2; i++)
            {
                DrawCircle(850 + i * 200, 350, 31.5, BLACK);
                DrawCircle(850.5 + i * 200, 350.5, 27.5, LIGHTGRAY);
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Music_Yes_Circle, 31.5))
            {
                Music_checker2 = 1;
            }
            if (Music_checker2)
            {
                right_check.x = right_check.x - 200;
                //needs to be added music here
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Music_No_Circle, 31.5))
                {
                    //stop the music here
                    Music_checker2 = 0;
                }
            }

            DrawTexture(Check, right_check.x, right_check.y, GREEN);
            DrawText("Choose a skin", 770, 400, 50, GRAY);

            for (int i = 0; i < 4; i++)
            {
                skins[i].width = 250;
                skins[i].height = 400;
                skins[i].x = 285 + (i * 350);
                skins[i].y = 475;
                DrawRectangleRec(skins[i], BLACK);
                DrawCircle(415 + (i * 350), 925, 31.5, BLACK);
                DrawCircle(415 + (i * 350), 925.5, 27.5, LIGHTGRAY);
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Skin1_Circle, 31.5))
            {
                Skin_checker = 1;
                Skin_checker3 = 0;
                Skin_checker4 = 0;
                Skin_checker2 = 0;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Skin2_Circle, 31.5))
            {
                Skin_checker = 0;
                Skin_checker3 = 0;
                Skin_checker4 = 0;
                Skin_checker2 = 1;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Skin3_Circle, 31.5))
            {
                Skin_checker = 0;
                Skin_checker2 = 0;
                Skin_checker4 = 0;
                Skin_checker3 = 1;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Skin4_Circle, 31.5))
            {
                Skin_checker = 0;
                Skin_checker2 = 0;
                Skin_checker3 = 0;
                Skin_checker4 = 1;
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, back))
            {
                menuOne = 0;
                checker2 = 1;
            }
            if (Skin_checker)
            {
                skins_check.x = 415;
                skins_check.y = 925;

                DrawCircle(415, 925, 27.5, DARKGRAY);
                DrawCircle(765, 925, 27.5, LIGHTGRAY);
                DrawCircle(1115, 925, 27.5, LIGHTGRAY);
                DrawCircle(1465, 925.5, 27.5, LIGHTGRAY);

                //apply this skin
            }
            if (Skin_checker2)
            {
                skins_check.x = 765;
                skins_check.y = 925;
                DrawCircle(415, 925, 27.5, LIGHTGRAY);
                DrawCircle(765, 925, 27.5, DARKGRAY);
                DrawCircle(1115, 925, 27.5, LIGHTGRAY);
                DrawCircle(1465, 925.5, 27.5, LIGHTGRAY);
                //apply this skin
            }
            if (Skin_checker3)
            {
                skins_check.x = 1115;
                skins_check.y = 907.5;
                DrawCircle(415, 925, 27.5, LIGHTGRAY);
                DrawCircle(765, 925, 27.5, LIGHTGRAY);
                DrawCircle(1115, 925, 27.5, DARKGRAY);
                DrawCircle(1465, 925.5, 27.5, LIGHTGRAY);
                //apply this skin
            }
            if (Skin_checker4)
            {
                skins_check.x = 1465;
                skins_check.y = 925;
                DrawCircle(415, 925, 27.5, LIGHTGRAY);
                DrawCircle(765, 925, 27.5, LIGHTGRAY);
                DrawCircle(1115, 925, 27.5, LIGHTGRAY);
                DrawCircle(1465, 925.5, 27.5, DARKGRAY);
                //apply this skin
            }



            DrawRectangleRec(back, DARKGRAY);
            DrawText("Back", 885, 957.5, 40, WHITE);
        }
        if (menuTwo)
        {
            Rules.width = 1600;
            Rules.height = 850;
            DrawRectangleRec(hide, Fade(BLACK, 0.79999999));
            DrawTexture(Rules, 150, 100, WHITE);
            DrawCircle(1550, 100, 32.5, RED);
            DrawLineEx(Rules_line_1_start, Rules_line_1_end, 6, WHITE);
            DrawLineEx(Rules_line_2_start, Rules_line_2_end, 6, WHITE);
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Close, 32.5))
            {
                menuTwo = 0;

            }
        }
        if (menuThree)
        {
            exit(0);

        }
    }

};