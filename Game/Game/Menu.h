#pragma once
#include "include.h"
class Menu
{
    // music load
    Sound music = LoadSound("../Music/music.mp3");
public:
    bool If_it_is_not_chosen_an_option = 1;
    //checker for option in menu
    bool menu_checker = 1;
    bool Menu_checker = 1;
    //checker for option in settings
    bool Music_checker = 1;
    bool Music_checker2 = 0;
    bool Music_checker3 = 0;
    bool Skin_checker = 1;
    bool Skin_checker2 = 0;
    bool Skin_checker3 = 0;
    bool Skin_checker4 = 0;

    //position of something which closes the page
    Vector2 Close;
    //position of option in settings
    Vector2 Skin1_Circle;
    Vector2 Skin2_Circle;
    Vector2 Skin3_Circle;
    Vector2 Skin4_Circle;
    Vector2 Music_Yes_Circle;
    Vector2 Music_No_Circle;
    //position of mouse
    Vector2 mousePoint;
    //texture loading
    Texture2D Rules = LoadTexture("../images/Rules.png");
    Texture2D bgimg = LoadTexture("../images/backgrounds/Menu_Background.png");
    Texture2D Check = LoadTexture("../images/check.png");
    Texture2D set_bg = LoadTexture("../images/backgrounds/Settings_bg.png");
    Texture2D skins[4] = { LoadTexture("../images/Skins/red-skin.png"), LoadTexture("../images/Skins/green-skin.png"), LoadTexture("../images/Skins/purple-skin.png"), LoadTexture("../images/Skins/black-skin.png") };
    Rectangle skins_rectangles[4];
    Rectangle hide = { 0,0,(float)GetScreenWidth(),(float)GetScreenHeight() };
    Rectangle back = { 850,950, 165,50 };
    //options in menu checkers
    bool Play = 0, Settings_option = 0, Rules_option = 0, Exit = 0;
    //arr for music
    int MusicArr[2];
    void SetMenuSize();
    void UpdateMenu();

};