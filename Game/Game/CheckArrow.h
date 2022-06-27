#pragma once
#include "DrawHero.h"
#include "Background.h"
#include "Namespace.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace help;
class Arrows {
public:
    Hero Hero_obj;
    Background moveBG;
    bool If_it_is_not_chosen_an_option = 1;
    // variable to change the limit of the hero in different areas
    int LimitA = 320;
    int LimitD = 320;
    int LimitS = 120;
    int LimitW = 120;
    int LimitR = 650;
    bool Upper_left_chest = 0;
    bool Lower_leFt_chest = 0;
    bool Is_hero_passed_the_first_door = 0;
    bool Key_is_pressed = 0;
    bool Upper_right_chest = 0;
    bool Lower_right_chest = 0;
    int counterDoor = 0;
    int counterArea = 0;
    bool checkInput[4] = { 0, 0, 0, 0 };
    int speedBG = 100;
    int speedHero = 10;
    bool RandomKey[4] = { 0, 0, 0, 0 };
    bool checkChests = 1;

    Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };
    Texture2D Opened_Chest = LoadTexture("../images/Chests/opened_chest.png");
    Texture2D Key = LoadTexture("../images/Key.png");
    Rectangle Border;
    Rectangle KeyRec;
    Rectangle Door;
    Vector2 Close;
    Vector2 mousePoint;
    Vector2 Close_line_1_start = { 1540,118 };
    Vector2 Close_line_1_end = { 1560,152 };
    Vector2 Close_line_2_start = { 1560,118 };
    Vector2 Close_line_2_end = { 1540,152 };

    bool diagonal = 0;
    bool pressed_key_checker = 1;
    bool wrong_chest1 = 0, wrong_chest2 = 0, wrong_chest3 = 0, right_chest = 0;
    Rectangle chests[4];

    void SetRandomPosKey();
    void MakeChests();
    void checkArrows();
};