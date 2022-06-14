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
    Image background = LoadImage("pixilart-drawing.png");
    Texture2D backgroundTexture = LoadTextureFromImage(background);
    SetTargetFPS(90);

    Arrows arrow_obj;

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();
        DrawTexture(backgroundTexture, screenWidth / 2, screenHeight / 2, WHITE);
    
        arrow_obj.checkArrows();
        
        arrow_obj.StartMovement();

        EndDrawing();

    }

    arrow_obj.Hero_obj_right.UnloadHeroRight();
    arrow_obj.Hero_obj_left.UnloadHeroLeft();
    CloseWindow();        // Close window and OpenGL context

}