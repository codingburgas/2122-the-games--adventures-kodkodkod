#pragma once
#include "include.h"
#include "Menu.h"
using namespace std;
class Gameover {
public:
    Menu menu_obj;

    bool not_play_again=1;

	Texture2D GameOver_img= LoadTexture("../images/GameOver.png");

    Vector2 Close;
    Vector2 mousePoint;

    Vector2 X_line_1_start = { 1540,88 };
    Vector2 X_line_1_end = { 1560,112 };
    Vector2 X_line_2_start = { 1560,88 };
    Vector2 X_line_2_end = { 1540,112 };

    Rectangle PlayAgain = { 750,850, 275, 150 };

    Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };
    
    void GameOver()
    {
        if (not_play_again)
        {
            mousePoint = GetMousePosition();

            GameOver_img.width = 1600;
            GameOver_img.height = 850;

            Close.x = 1550;
            Close.y = 75;

            DrawRectangleRec(hide, Fade(BLACK, 0.79999999));

            DrawTexture(GameOver_img, 150, 100, WHITE);

            DrawCircle(1550, 100, 32.5, RED);
            DrawLineEx(X_line_1_start, X_line_1_end, 6, WHITE);
            DrawLineEx(X_line_2_start, X_line_2_end, 6, WHITE);

            DrawRectangleRounded(PlayAgain, 7, 7, DARKGRAY);
            DrawText("Play Again", 785, 857.5, 70, WHITE);

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, PlayAgain))
            {
                menu_obj.If_it_is_not_chosen_an_option = 1;
                not_play_again = 0;
            }

            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Close, 32.5))
            {
                exit(0);
            }
        }
    }
};