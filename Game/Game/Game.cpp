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
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1900;
    const int screenHeight = 1025;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(90);          
    
    Arrows arrow_obj;
    Jump jump_obj;
    Background Drawbg;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        BeginDrawing();

        ClearBackground(RAYWHITE);

        Drawbg.DrawBackground();
        arrow_obj.checkArrows();
        jump_obj.GetObject(arrow_obj);

		
        arrow_obj.StartMovement();
        
        EndDrawing();
        
    }

    arrow_obj.Hero_obj_right.UnloadHeroRight();
    arrow_obj.Hero_obj_left.UnloadHeroLeft();
    Drawbg.UnloadBG();
    CloseWindow();        // Close window and OpenGL context
    
}