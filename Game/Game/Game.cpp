#include "include.h"
#include "DrawHeroRight.h"
#include "DrawHeroLeft.h"
#include "CheckArrow.h"
int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1900;
    const int screenHeight = 1025;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(90);          
    
    Arrows arrow_obj;

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        BeginDrawing();

        ClearBackground(RAYWHITE);

        arrow_obj.checkArrows();

        arrow_obj.StartMovement();

        EndDrawing();
        
    }

    arrow_obj.Hero_obj_right.UnloadHeroRight();
    arrow_obj.Hero_obj_left.UnloadHeroLeft();
    CloseWindow();        // Close window and OpenGL context
    
}