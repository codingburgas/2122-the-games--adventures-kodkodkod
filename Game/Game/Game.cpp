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
    int counterBg = 0;
    int counterBg3 = 0;
    InitWindow(screenWidth, screenHeight, "The Last Swordsman");
    InitAudioDevice();
    SetTargetFPS(60);
    
    Menu menu_obj;
    Arrows arrow_obj;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing();

        ClearBackground(DARKPURPLE);  
        
       

        menu_obj.SetMenuSize();
        menu_obj.UpdateMenu();
        if (menu_obj.Play)
        {
            arrow_obj.MakeChests();
            menu_obj.If_it_is_not_chosen_an_option = 0;
            DrawRectangleRec(menu_obj.hide, LIGHTGRAY);
            //change backgrounds
            if (arrow_obj.Is_hero_passed_the_first_door)
            {
                counterBg3 = 0;
                counterBg++;
                if (counterBg == 1)
                {
                    arrow_obj.pressed_key_checker = 1;
                    arrow_obj.SetRandomPosKey();
                }

                if (arrow_obj.counterArea == 1)
                {
                    arrow_obj.pressed_key_checker = 1;
                    arrow_obj.Door = {0,0,0,0};//Namesti doora
                    arrow_obj.moveBG.DrawBackground3();

                }
                else if (arrow_obj.counterArea == 2)
                {
                    arrow_obj.pressed_key_checker = 1;
                    arrow_obj.Door = {0,0 ,0,0 };//Namesti doora
                    arrow_obj.moveBG.DrawBackground4();

                }
            }
            else if (arrow_obj.Key_is_pressed)
            {
                if (arrow_obj.counterDoor == 1)
                {

                arrow_obj.moveBG.DrawBackground2();
                }
                else if (arrow_obj.counterDoor == 2)
                {
                    arrow_obj.moveBG.DrawBackground3_Opened();
                }
                else if (arrow_obj.counterDoor == 3)
                {
                    arrow_obj.moveBG.DrawBackground4_Opened();
                }
            }
            else
            {
                counterBg = 0;
                counterBg3++;
                if (counterBg3 == 1)
                {

                    arrow_obj.SetRandomPosKey();
                }

                arrow_obj.moveBG.DrawBackground();

            }

            

            arrow_obj.checkArrows();
            if (arrow_obj.diagonal && arrow_obj.checkInput[0])
            {
                arrow_obj.Hero_obj.DrawLeft();
                arrow_obj.Hero_obj.UpdateLeft();

            }
            else if (arrow_obj.diagonal && arrow_obj.checkInput[1])
            {
                arrow_obj.Hero_obj.DrawRight();
                arrow_obj.Hero_obj.UpdateRight();

            }
            else if (arrow_obj.checkInput[0] && arrow_obj.diagonal == 0)
            {
                arrow_obj.Hero_obj.DrawLeft();
                arrow_obj.Hero_obj.UpdateLeft();

            }
            else if (arrow_obj.checkInput[1] && arrow_obj.diagonal == 0)
            {
                arrow_obj.Hero_obj.DrawRight();
                arrow_obj.Hero_obj.UpdateRight();

            }
            else if (arrow_obj.checkInput[2] && arrow_obj.diagonal == 0)
            {
                arrow_obj.Hero_obj.DrawUp();
                arrow_obj.Hero_obj.UpdateUp();


            }
            else if (arrow_obj.checkInput[3] && arrow_obj.diagonal == 0)
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
                                    if (!(IdleCount == 2))
                                    {

                                    arrow_obj.Hero_obj.IdleLeft();
                                    arrow_obj.Hero_obj.UpdateLeftIdle();
                                    }
                                    else
                                        IdleCount = 0;
                                    break;
                                }
                                case 1:
                                {
                                    if (!(IdleCount == 2))
                                    {

                                    arrow_obj.Hero_obj.IdleRight();
                                    arrow_obj.Hero_obj.UpdateRightIdle();
                                    }
                                    else
                                        IdleCount = 0;
                                    break;
                                }
                                case 2:
                                {
                                    if (!(IdleCount == 2))
                                    {

                                    

                                    arrow_obj.Hero_obj.IdleDown();
                                    arrow_obj.Hero_obj.UpdateDownIdle();
                                    }
                                    else
                                        IdleCount = 0;
                                    break;
                                }
                                case 3:
                                {
                                    if (!(IdleCount == 2))
                                    {

                                        arrow_obj.Hero_obj.IdleUp();
                                        arrow_obj.Hero_obj.UpdateUpIdle();
                                    }
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
                        arrow_obj.Hero_obj.UpdateDownIdle();
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