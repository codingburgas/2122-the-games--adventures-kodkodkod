#include "include.h"
#include "DrawHeroRight.h"
#include "DrawHeroLeft.h"
#include "CheckArrow.h"
#include "Jump.h"
#include "Background.h"
using namespace std;
int main()
{
    // Initialization
    const int screenWidth = 1900;
    const int screenHeight = 1025;

    bool checker = 1;

    InitWindow(screenWidth, screenHeight, "The last swordsman");

    SetTargetFPS(90);      

    Vector2 mousePoint;

    Texture2D bgimg = LoadTexture("../images/Menu_Background.png");

    Texture2D Hero = LoadTexture("../images/Hero.png");

    bgimg.width = GetScreenWidth();
    bgimg.height = GetScreenHeight();

    Hero.width = 450;
    Hero.height = 900;

    Rectangle hide = { 0,0,screenWidth,screenHeight };

    bool menuZero = 0, menuOne = 0, menuTwo = 0, menuThree = 0;

   Arrows arrow_obj;
   Jump jump_obj;
   Background Drawbg;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        mousePoint = GetMousePosition();
        BeginDrawing();

        ClearBackground(RAYWHITE);
        Rectangle options[4];
        Rectangle options_border[4];
        for (int i = 0; i < 4; i++)
        {
            options_border[i] = { 815,float(210 + (i * 200)), 500, 175 };;
        }
            
        for (int i = 0; i < 4; i++)
        {
            options[i] = { 825, float(220 + (i * 200)), 480, 155 };;
        }
        DrawTexture(bgimg, 10, 10, WHITE);
        DrawTexture(Hero, 100, 100, WHITE);
        for (int i = 0; i < 4; i++)
        {
            DrawRectangleRec(options_border[i], BLUE);
            DrawRectangleRec(options[i], ORANGE);
        }

        DrawText("PLAY!", 950, 265, 75, BLACK);
        DrawText("SETTINGS!", 857.5, 465, 75, BLACK);
        DrawText("RULES!", 942.5, 665, 75, BLACK);
        DrawText("EXIT!", 962.5, 865, 75, BLACK);

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
        if (menuZero)
        {
            checker = 0;
            DrawRectangleRec(hide, LIGHTGRAY);

            Drawbg.DrawBackground();

            arrow_obj.checkArrows();

            jump_obj.GetObject(arrow_obj);

            arrow_obj.StartMovement();
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
        EndDrawing();
        
    }

   arrow_obj.Hero_obj_right.UnloadHeroRight();
   arrow_obj.Hero_obj_left.UnloadHeroLeft();
   Drawbg.UnloadBG();

    CloseWindow();        // Close window and OpenGL context
    
}