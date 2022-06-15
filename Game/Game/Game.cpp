#include "include.h"
#include "DrawHeroRight.h"
#include "DrawHeroLeft.h"
#include "CheckArrow.h"
#include "Jump.h"
#include "Background.h"
#include "Menu.h"
using namespace std;
int main()
{
    // Initialization
    const int screenWidth = 1915;
    const int screenHeight = 1025;


    InitWindow(screenWidth, screenHeight, "The last swordsman");

    SetTargetFPS(90);      

   
    Menu menu_obj;
   Arrows arrow_obj;
   Jump jump_obj;
   Background Drawbg;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
       
        BeginDrawing();

        ClearBackground(DARKPURPLE);

        menu_obj.SetMenuSize();
        menu_obj.UpdateMenu();
        if (menu_obj.menuZero)
        {
            menu_obj.checker = 0;
            DrawRectangleRec(menu_obj.hide, LIGHTGRAY);

            Drawbg.DrawBackground();

            arrow_obj.checkArrows();

            jump_obj.GetObject(arrow_obj);

            arrow_obj.StartMovement();
        }
        
        EndDrawing();
        
    }

   arrow_obj.Hero_obj_right.UnloadHeroRight();
   arrow_obj.Hero_obj_left.UnloadHeroLeft();
   Drawbg.UnloadBG();

    CloseWindow();        // Close window and OpenGL context
    
}