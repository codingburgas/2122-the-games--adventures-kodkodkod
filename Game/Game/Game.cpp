#include "include.h"
#include "DrawHero.h"
#include "CheckArrow.h"
#include "Background.h"
#include "Menu.h"
using namespace std;
int main()
{
    // Initialization
    const int screenWidth = 1915;
    const int screenHeight = 1025;

    
    InitWindow(screenWidth, screenHeight, "The last swordsman");

    SetTargetFPS(60);      

    Menu menu_obj;
    Arrows arrow_obj;
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

            arrow_obj.moveBG.DrawBackground();

            arrow_obj.MakeChests();
            arrow_obj.CheckChests();

            arrow_obj.checkArrows();
            arrow_obj.Hero_obj.DrawLeft();
            arrow_obj.Hero_obj.UpdateLeft();
        }
        
        EndDrawing();
        arrow_obj.Hero_obj.UnloadHero();
        /*system("CLS");*/
        
    }
    arrow_obj.Hero_obj.UnloadHero();
    arrow_obj.moveBG.UnloadBG();

    CloseWindow();        // Close window and OpenGL context
    
}