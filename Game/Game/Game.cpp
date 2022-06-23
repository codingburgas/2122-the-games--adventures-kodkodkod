#include "include.h"
#include "DrawHero.h"
#include "CheckArrow.h"
#include "Background.h"
#include "Menu.h"
#include "Namespace.h"
using namespace std;
using namespace help;
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
            //change backgrounds
            if (arrow_obj.checker5)
            {
                arrow_obj.moveBG.DrawBackground3();

            }
            else
            {
                arrow_obj.moveBG.DrawBackground();

            }

            arrow_obj.MakeChests();
            arrow_obj.CheckChests();

            arrow_obj.checkArrows();
            if (arrow_obj.dia && arrow_obj.checkInput[0])
            {
                arrow_obj.Hero_obj.DrawLeft();
                arrow_obj.Hero_obj.UpdateLeft();

            }
            else if (arrow_obj.dia && arrow_obj.checkInput[1])
            {
                arrow_obj.Hero_obj.DrawRight();
                arrow_obj.Hero_obj.UpdateRight();

            }
            else if (arrow_obj.checkInput[0] && arrow_obj.dia == 0)
            {
                arrow_obj.Hero_obj.DrawLeft();
                arrow_obj.Hero_obj.UpdateLeft();

            }
            else if (arrow_obj.checkInput[1] && arrow_obj.dia == 0)
            {
                arrow_obj.Hero_obj.DrawRight();
                arrow_obj.Hero_obj.UpdateRight();

            }
            else if (arrow_obj.checkInput[2] && arrow_obj.dia == 0)
            {
                arrow_obj.Hero_obj.DrawUp();
                arrow_obj.Hero_obj.UpdateUp();


            }
            else if (arrow_obj.checkInput[3] && arrow_obj.dia == 0)
            {
                arrow_obj.Hero_obj.DrawDown();
                arrow_obj.Hero_obj.UpdateDown();

            }
            else
            {
                bool fourth = 0;
                bool idleChek = 0;
                int IdleCount = 0;
                for (int i = 0; i < 4; i++)
                {
                    if (arrow_obj.checkInput[i])
                        
                    fourth = 1;
                }
                if (fourth == 0)
                {

                    for (int i = 0;i< 4; i++)
                    {
                        if(idleAnims[i])
                        {
                            idleChek = 1;
                            IdleCount++;
                            switch (i)
                            {
                                case 0:
                                {
                                    if(!(IdleCount == 2))
                                    arrow_obj.Hero_obj.IdleLeft();
                                    else
                                        IdleCount = 0;
                                    break;
                                }
                                case 1:
                                {
                                    if (!(IdleCount == 2))
                                    arrow_obj.Hero_obj.IdleRight();
                                    else
                                        IdleCount = 0;
                                    break;
                                }
                                case 2:
                                {
                                    if (!(IdleCount == 2))
                                    arrow_obj.Hero_obj.IdleUp();
                                    else
                                        IdleCount = 0;
                                    break;
                                }
                                case 3:
                                {
                                    if (!(IdleCount == 2))
                                        arrow_obj.Hero_obj.IdleDown();
                                    else
                                        IdleCount = 0;
                                    break;
                                }
                            }
                        }
                    }
                    if (idleChek == 0)
                    {
                        arrow_obj.Hero_obj.IdleDown();
                    }
                }
            }
              
                
            
        }
        
        EndDrawing();
        /*system("CLS");*/
        
    }
    arrow_obj.Hero_obj.UnloadHero();
    arrow_obj.moveBG.UnloadBG();

    CloseWindow();        // Close window and OpenGL context
    
}