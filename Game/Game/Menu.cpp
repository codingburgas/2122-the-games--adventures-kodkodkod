#include"Menu.h"
void Menu::SetMenuSize() //sets size of menu
{
    bgimg.width = GetScreenWidth();
    bgimg.height = GetScreenHeight();

    set_bg.width = GetScreenWidth();
    set_bg.height = GetScreenHeight();
}
void Menu::UpdateMenu()
{

    SetSoundVolume(music, 0.75696969); //make volume specific
    mousePoint = GetMousePosition(); // gets position of mouse
    Rectangle options[4]; // array for options in menu

    Vector2 Rules_line_1_start = { 1540,88 }; // position of point of line in rules
    Vector2 Rules_line_1_end = { 1560,112 }; // position of point of line in rules
    Vector2 Rules_line_2_start = { 1560,88 }; // position of point of line in rules
    Vector2 Rules_line_2_end = { 1540,112 }; // position of point of line in rules

    Vector2 right_check = { 1027.5, 327.5 }; //checker position 
    Vector2 skins_check = { 392.5, 907.5 }; //checker position

    Vector2 LineOfPlayStart = { 460,495 }; // position of point of line
    Vector2 LineOfSettingsStart = { 17.5,100 }; // position of point of line
    Vector2 LineOfRulesStart = { 1670,975 }; // position of point of line
    Vector2 LineOfExitStart = { 1160, 495 };// position of point of line

    Vector2 LineOfPlayEnd = { 675,495 }; // position of point of line
    Vector2 LineOfSettingsEnd = { 400,100 }; // position of point of line
    Vector2 LineOfRulesEnd = { 1870,975 }; // position of point of line
    Vector2 LineOfExitEnd = { 1375, 495 }; // position of point of line
     //setes sizes and positions
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
    if (Menu_checker)
    {
        for (int i = 0; i < 4; i++)
        {
            DrawRectangleRec(options[i], GREEN);
        }

        DrawTexture(bgimg, 0, 0, WHITE);
        //draws lines
        DrawLineEx(LineOfPlayStart, LineOfPlayEnd, 7, DARKPURPLE);
        DrawLineEx(LineOfSettingsStart, LineOfSettingsEnd, 7, DARKPURPLE);
        DrawLineEx(LineOfRulesStart, LineOfRulesEnd, 7, DARKPURPLE);
        DrawLineEx(LineOfExitStart, LineOfExitEnd, 7, DARKPURPLE);
        //draw texts for options
        DrawText("PLAY", 500, 425, 50, BEIGE);
        DrawText("SETTINGS", 30, 50, 50, BEIGE);
        DrawText("RULES", 1700, 922.5, 50, BEIGE);
        DrawText("EXIT", 1200.5, 425, 50, BEIGE);
        //draws our NAME
        DrawText("THE LAST SWORDSMAN", 290, 250, 100, BEIGE);


        //checks if option was chosen
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, options[0]) && If_it_is_not_chosen_an_option)
        {

            Play = true;
            Settings_option = 0;
            Rules_option = 0;
            Exit = 0;
        }
        else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, options[1]) && If_it_is_not_chosen_an_option)
        {

            Settings_option = true;
            Play = 0;
            Rules_option = 0;
            Exit = 0;
        }
        else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, options[2]) && If_it_is_not_chosen_an_option)
        {
            Rules_option = true;
            Settings_option = 0;
            Play = 0;
            Exit = 0;
        }
        else if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, options[3]) && If_it_is_not_chosen_an_option)
        {
            Exit = true;
            Settings_option = 0;
            Play = 0;
            Rules_option = 0;
        }
    }
    if (Settings_option) //the settings option
    {
        Menu_checker = 0;
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
            if (!Music_checker3)
            {
                PlaySoundMulti(music);
                Music_checker3 = 1;
            }
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Music_No_Circle, 31.5))
            {
                StopSoundMulti();
                Music_checker2 = 0;
                Music_checker3 = 0;
            }
        }


        DrawTexture(Check, right_check.x, right_check.y, GREEN);
        DrawText("Choose a skin", 770, 400, 50, GRAY);

        for (int i = 0; i < 4; i++)
        {
            skins_rectangles[i].width = 250;
            skins_rectangles[i].height = 400;

            skins[i].width = 153;
            skins[i].height = 351;
            skins_rectangles[i].x = 285 + (i * 350);
            skins_rectangles[i].y = 475;
            skins_rectangles[1].x = 285 + 375;
            skins_rectangles[2].y = 470;//x = 985 y = 470 width = 153 heigth = 351 

            if (i == 0)
            {
                skins[i].width = 320;
                skins[i].height = 320;
                skins_rectangles[i].x = 305 + (i * 350);
                skins_rectangles[i].y = 501;
            }
            else
            {
                //x = 985 y = 470 width = 153 heigth = 351
                DrawRectangleRec(skins_rectangles[1], Fade(DARKGRAY, 0.39999999));
                DrawRectangle(1010, 470, 240, 400, Fade(DARKGRAY, 0.39999999));

            }
            if (i == 2)
            {
                skins[i].width = 200;
                skins[i].height = 320;
                skins_rectangles[i].x = 305 + (i * 350);
                skins_rectangles[i].y = 501;
            }
            DrawTexture(skins[i], skins_rectangles[i].x + 50, skins_rectangles[i].y + 20, WHITE);
            DrawCircle(415 + (i * 350), 925, 31.5, BLACK);
            DrawCircle(415 + (i * 350), 925.5, 27.5, LIGHTGRAY);
        }
        DrawRectangleRec(skins_rectangles[3], Fade(DARKGRAY, 0.79999999));
        DrawText("Will be", 710, 575, 50, WHITE);
        DrawText("avaliable", 680, 625, 50, WHITE);
        DrawText("soon", 730, 675, 50, WHITE);

        DrawText("Will be", 1050, 575, 50, WHITE);
        DrawText("avaliable", 1020, 625, 50, WHITE);
        DrawText("soon", 1070, 675, 50, WHITE);

        DrawText("Will be", 1385, 575, 50, WHITE);
        DrawText("avaliable", 1355, 625, 50, WHITE);
        DrawText("soon", 1405, 675, 50, WHITE);
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
            Settings_option = 0;
            Menu_checker = 1;
        }
        DrawCircle(415, 925, 27.5, DARKGRAY);
        DrawCircle(765, 925, 27.5, LIGHTGRAY);
        DrawCircle(1115, 925, 27.5, LIGHTGRAY);
        DrawCircle(1465, 925.5, 27.5, LIGHTGRAY);
        DrawRectangleLinesEx(skins_rectangles[1], 5, BLACK);
        DrawRectangleLinesEx(skins_rectangles[2], 5, BLACK);
        DrawRectangleLinesEx(skins_rectangles[3], 5, BLACK);
        if (Skin_checker2)
        {
            //this will be avaliable soon
        }
        if (Skin_checker3)
        {
            //this will be avaliable soon
        }
        if (Skin_checker4)
        {
            //this will be avaliable soon
        }



        DrawRectangleRounded(back, 7, 7, DARKGRAY);
        DrawText("Back", 885, 957.5, 40, WHITE);
    }
    if (Rules_option) // rules option
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
            Rules_option = 0;

        }
    }
    if (Exit) //exit
    {

        exit(0);

    }
}