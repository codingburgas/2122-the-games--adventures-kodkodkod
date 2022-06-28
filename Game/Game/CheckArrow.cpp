#include"CheckArrow.h"
void Arrows::SetRandomPosKey()
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

void Arrows::MakeChests()
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
void Arrows::checkArrows()
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        if (checkInput[i])
        {
            count++;
            if (count == 2)
            {
                speedHero = 5;
                speedBG = 150;
                diagonal = 1;
                break;
            }
            else {
                diagonal = 0;
                speedHero = 10;
                speedBG = 100;
                for (int i = 0; i < 4; i++)
                {
                    if (checkInput[i])
                        help::idleAnims[i] = 1;//for static
                    else
                        help::idleAnims[i] = 0;// for static
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
        if (checkChests)
        {

            if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[0]))
            {
                DrawText("Press 'E' to open the chest", 10, 50, 35, WHITE);
                if (IsKeyPressed(KEY_E))
                {
                    Upper_left_chest = 1;
                }
            }
        }
    }
    else
    {
        Upper_left_chest = 0;
    }
    if (Key_is_pressed)
    {
        if (CheckCollisionPointRec(Hero_obj.HeroPos, Door) && moveBG.bg_pos.x < LimitR && moveBG.bg_pos.x > 150)
        {
            Hero_obj.HeroPos = { KeyRec.x + 150, (float)GetScreenHeight() - 200/*change where to spawn */ };
            moveBG.bg_pos.y = GetScreenHeight();
            moveBG.bg_pos.x = 0;
            Is_hero_passed_the_first_door = 1;
            counterArea++;
            Key_is_pressed = 0;
        }
        else
        {
            Is_hero_passed_the_first_door = 0;
        }
    }
    KeyRec.x = 590;
    KeyRec.y = 350;
    KeyRec.width = 125;
    KeyRec.height = 225;
    if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[1]))
    {
        if (checkChests)
        {

            DrawText("Press 'E' to open the chest", 1380, 50, 35, WHITE);
            if (IsKeyPressed(KEY_E))
            {
                Upper_right_chest = 1;
            }
        }
    }
    else
    {
        Upper_right_chest = 0;
    }
    if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[2]))
    {
        if (checkChests)
        {

            DrawText("Press 'E' to open the chest", 10, 620, 35, WHITE);
            if (IsKeyPressed(KEY_E))
            {
                Lower_leFt_chest = 1;
            }
        }
    }
    else
    {
        Lower_leFt_chest = 0;
    }
    if (CheckCollisionPointRec(Hero_obj.HeroPos, chests[3]))
    {
        if (checkChests)
        {

            DrawText("Press 'E' to open the chest", 1380, 620, 35, WHITE);
            if (IsKeyPressed(KEY_E))
            {
                Lower_right_chest = 1;
            }
        }
    }
    else
    {
        Lower_right_chest = 0;
    }
    if (Upper_left_chest)
    {
        DrawTexture(Opened_Chest, 30, 30, WHITE);
        if (RandomKey[0] && pressed_key_checker)
        {


            DrawTexture(Key, 600, 360, WHITE);
            DrawRectangleLinesEx(KeyRec, 6, BLANK);
        }
        DrawCircle(1550, 135, 32.5, RED);
        DrawLineEx(Close_line_1_start, Close_line_1_end, 6, WHITE);
        DrawLineEx(Close_line_2_start, Close_line_2_end, 6, WHITE);
        Close.x = 1550;
        Close.y = 115;

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, KeyRec) or IsKeyPressed(KEY_R)&& RandomKey[0])
        {
            Key_is_pressed = 1;
            Upper_left_chest = 0;
            pressed_key_checker = 0;
            counterDoor++;

        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Close, 32.5))
        {
            Upper_left_chest = 0;
        }
    }

    if (Upper_right_chest)
    {
        DrawTexture(Opened_Chest, 30, 30, WHITE);
        if (RandomKey[1] && pressed_key_checker)
        {


            DrawTexture(Key, 600, 360, WHITE);
            DrawRectangleLinesEx(KeyRec, 6, BLANK);
        }
        DrawCircle(1550, 135, 32.5, RED);
        DrawLineEx(Close_line_1_start, Close_line_1_end, 6, WHITE);
        DrawLineEx(Close_line_2_start, Close_line_2_end, 6, WHITE);
        Close.x = 1550;
        Close.y = 115;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Close, 32.5))
        {
            Upper_right_chest = 0;
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, KeyRec) or IsKeyPressed(KEY_R))
        {
            Key_is_pressed = 1;
            Upper_right_chest = 0;
            pressed_key_checker = 0;

            counterDoor++;

        }
    }
    if (Lower_right_chest)
    {
        DrawTexture(Opened_Chest, 30, 30, WHITE);
        if (RandomKey[2] && pressed_key_checker)
        {


            DrawRectangleLinesEx(KeyRec, 6, BLANK);
            DrawTexture(Key, 600, 360, WHITE);
        }
        DrawCircle(1550, 135, 32.5, RED);
        DrawLineEx(Close_line_1_start, Close_line_1_end, 6, WHITE);
        DrawLineEx(Close_line_2_start, Close_line_2_end, 6, WHITE);
        Close.x = 1550;
        Close.y = 115;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Close, 32.5))
        {
            Lower_right_chest = 0;
        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, KeyRec) or IsKeyPressed(KEY_R))
        {
            Key_is_pressed = 1;
            Lower_right_chest = 0;
            pressed_key_checker = 0;

            counterDoor++;

        }
    }
    if (Lower_leFt_chest)
    {
        DrawTexture(Opened_Chest, 30, 30, WHITE);
        if (RandomKey[3] && pressed_key_checker)
        {


            DrawTexture(Key, 600, 360, WHITE);
            DrawRectangleLinesEx(KeyRec, 6, BLANK);
        }
        DrawCircle(1550, 135, 32.5, RED);
        DrawLineEx(Close_line_1_start, Close_line_1_end, 6, WHITE);
        DrawLineEx(Close_line_2_start, Close_line_2_end, 6, WHITE);
        Close.x = 1550;
        Close.y = 115;
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointRec(mousePoint, KeyRec) or IsKeyPressed(KEY_R))
        {
            Key_is_pressed = 1;
            Lower_leFt_chest = 0;
            pressed_key_checker = 0;

            counterDoor++;

        }
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && CheckCollisionPointCircle(mousePoint, Close, 32.5))
        {
            Lower_leFt_chest = 0;
        }
    }
}