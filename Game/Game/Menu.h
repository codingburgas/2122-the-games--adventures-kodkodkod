#pragma once
#include "include.h"
class Menu
{

public:
    bool checker = 1;
    Vector2 mousePoint;
    Texture2D bgimg = LoadTexture("../images/Menu_Background.png");
    Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight()};
    bool menuZero = 0, menuOne = 0, menuTwo = 0, menuThree = 0;
    void SetMenuSize()
    {

    bgimg.width = GetScreenWidth();
    bgimg.height = GetScreenHeight();
    }
    void UpdateMenu()
    {
        mousePoint = GetMousePosition();
        Rectangle options[4];

        Vector2 LineOfPlayStart = { 460,495 };
        Vector2 LineOfSettingsStart = { 17.5,100 };
        Vector2 LineOfRulesStart = { 1670,975 };
        Vector2 LineOfExitStart = { 1160, 495 };

        Vector2 LineOfPlayEnd = { 675,495 };
        Vector2 LineOfSettingsEnd = { 400,100 };
        Vector2 LineOfRulesEnd = { 1870,975 };
        Vector2 LineOfExitEnd = { 1375, 495 };

        options[0] = { 470, 400, 185, 85 };;
        options[1] = { 17.5, 12, 382.5, 91 };;
        options[2] = { 1660, 895, 225, 85 };;
        options[3] = { 1170, 400, 185, 85 };;

        //DrawTexture(bgimg, 0, 0, WHITE);

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
        if (menuOne)
        {

        }
        if (menuTwo)
        {

        }
        if (menuThree)
        {
            exit(0);

        }
    }

};