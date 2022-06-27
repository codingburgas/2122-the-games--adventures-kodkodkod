#pragma once
#include "include.h"
class Menu
{

    Sound music = LoadSound("../Music/music.mp3"); // music load
    public:
    bool If_it_is_not_chosen_an_option = 1;
    bool menu_checker = 1;
    bool Menu_checker = 1; //checker for option in menu
    bool Music_checker = 1; //checker for option in settings
    bool Music_checker2 = 0; //checker for option in settings
    bool Music_checker3 = 0; //checker for option in settings
    bool Skin_checker = 1;//checker for option in settings
    bool Skin_checker2 = 0;//checker for option in settings
    bool Skin_checker3 = 0;//checker for option in settings
    bool Skin_checker4 = 0;//checker for option in settings
   
    Vector2 Close; //closes the page
    Vector2 Skin1_Circle; //position of option in settings
    Vector2 Skin2_Circle; //position of option in settings
    Vector2 Skin3_Circle; //position of option in settings
    Vector2 Skin4_Circle; //position of option in settings
    Vector2 Music_Yes_Circle; //position of option in settings
    Vector2 Music_No_Circle; //position of option in settings
    Vector2 mousePoint; //position of mouse
    //texture loading
    Texture2D Rules = LoadTexture("../images/Rules.png");
    Texture2D bgimg = LoadTexture("../images/backgrounds/Menu_Background.png");
    Texture2D Check = LoadTexture("../images/check.png");
    Texture2D set_bg = LoadTexture("../images/backgrounds/Settings_bg.png");
    Texture2D skins[4] = { LoadTexture("../images/Skins/red-skin.png"), LoadTexture("../images/Skins/green-skin.png"), LoadTexture("../images/Skins/purple-skin.png"), LoadTexture("../images/Skins/black-skin.png") };
    Rectangle skins_rectangles[4];
    Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };
    Rectangle back = { 850,950, 165,50 };
    bool Play = 0, Settings_option = 0, Rules_option = 0, Exit = 0; //options in menu checkers
    int MusicArr[2]; //arr for music
    void SetMenuSize();
    void UpdateMenu();

};