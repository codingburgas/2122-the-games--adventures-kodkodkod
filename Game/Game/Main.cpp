#include "include.h" // includes additional library
#include "DrawHero.h" // includes additional library
#include "CheckArrow.h" // includes additional library
#include "Background.h" // includes additional library
#include "Menu.h" // includes additional library
#include "Boss.h" // includes additional library


using namespace std; // add namespace
using namespace help; // add namespace

int main() //main function
{
    const int screenWidth = 1915; //sets width of the screen window
    const int screenHeight = 1025; //sets heigth of the screen window

    int counterBg = 0; // counter for the background
    int counterBg2 = 0; // counter for the background 
    int counterBg3 = 0; // counter for the background
    int counterBg4 = 0; // counter for the background
    bool checkBoss = 0;
    InitWindow(screenWidth, screenHeight, "The Last Swordsman"); // initialise window and add tittle to it
    InitAudioDevice(); // initialise audio device
    SetTargetFPS(60); // set fps to the game
    
    Menu menu_obj; // add object from class
    Arrows arrow_obj; // add object from class
    Boss boss_obj; // add object from class
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        BeginDrawing(); // starts drawing the widnow

        ClearBackground(DARKPURPLE);  

        menu_obj.SetMenuSize(); // uses function from different class 
        menu_obj.UpdateMenu(); // uses function from different class
        if (menu_obj.Play) //check for option in different class
        {
           
            arrow_obj.MakeChests(); // uses function from different class
            
            menu_obj.If_it_is_not_chosen_an_option = 0; // uses variable from different class and sets it to false
            DrawRectangleRec(menu_obj.hide, LIGHTGRAY); //hides everything

            //this if changes the backgrounds
            if (arrow_obj.Is_hero_passed_the_first_door)
            {
                counterBg3 = 0;
                counterBg++;
                if (counterBg == 1 || counterBg2 == 1 ||counterBg4 == 1)
                {
                    arrow_obj.pressed_key_checker = 1;
                    arrow_obj.SetRandomPosKey();
                }
                if (arrow_obj.counterArea == 1)
                {
                    arrow_obj.pressed_key_checker = 1;
                    arrow_obj.Door.x = 550;
                    arrow_obj.LimitR = 650;
                    arrow_obj.moveBG.DrawMap1();

                }
                else if (arrow_obj.counterArea == 2)
                {
                    arrow_obj.pressed_key_checker = 1;
                    counterBg2++;
                    arrow_obj.moveBG.DrawMap2();

                }
                else if (arrow_obj.counterArea == 3)
                {
                    counterBg4++;
                    arrow_obj.moveBG.DrawMap3();

                }
                else if (arrow_obj.counterArea == 4)
                {
                    checkBoss = 1;
                    arrow_obj.checkChests = 0;
                    boss_obj.Update(arrow_obj);
                    boss_obj.Check(arrow_obj);
                    arrow_obj.LimitD = 50;
                    arrow_obj.LimitA = 50;
                    arrow_obj.LimitS = 50;
                    arrow_obj.LimitW = 50;
                    boss_obj.Draw(menu_obj, arrow_obj);

                }
            }
            else if (arrow_obj.Key_is_pressed)
            {
                if (arrow_obj.counterDoor == 1)
                {
                    arrow_obj.pressed_key_checker = 0;
                    arrow_obj.moveBG.DrawBase_Opened();
                }
                else if (arrow_obj.counterDoor == 2)
                {
                    arrow_obj.pressed_key_checker = 0;

                    arrow_obj.moveBG.DrawMap1_Opened();
                }
                else if (arrow_obj.counterDoor == 3)
                {
                    arrow_obj.pressed_key_checker = 0;

                    arrow_obj.moveBG.DrawMap2_Opened();
                }
                else if (arrow_obj.counterDoor == 4)
                {
                    arrow_obj.pressed_key_checker = 0;

                    arrow_obj.moveBG.DrawMap3_Opened();
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

                arrow_obj.moveBG.DrawBase();

            }

            
            arrow_obj.checkArrows();
            if(boss_obj.checkToStopMovement)
            { 
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
            
        }
        for (bool I : help::idleAnims)
        {
            cout << I << " ";
        }
        cout << endl;
        EndDrawing();
        /*stops drawing and system("CLS");*/
        
    }
    arrow_obj.Hero_obj.UnloadHero(); //unload textures from different class
    arrow_obj.moveBG.UnloadBG(); //unload textures from different class
    boss_obj.Unload(); //unload textures from different class
    
    CloseWindow();        // Close window 
    
}