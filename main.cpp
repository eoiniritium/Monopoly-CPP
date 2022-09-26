#include <iostream>
#include <vector>
#include <map>
#include "raylib.h"
#include "monopoly.hpp"
#include "misc.hpp"

int main() {
    locationVectors locations = Monopoly::setupBoard();

    const int screenWidth = 1920;
    const int screenHeight = 1080;

    const int fontsize = 16;
    const int titlefontsize = 72;
    const int poundsymbolfontsize = 16;

    const int rowHeight = 120;
    const int unitsPerSide = 9;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_FULLSCREEN_MODE);

    InitWindow(screenWidth, screenHeight, "Monopoly");

    Font txtFont    = LoadFontEx("fonts/monopolyfont.ttf", fontsize, 0, 0);
    Font titleFont  = LoadFontEx("fonts/tallfancyfont.otf", titlefontsize, 0, 0);
    //Font robotoBold = LoadFontEx("fonts/roboto_bold.ttf", poundsymbolfontsize, 0, 0);

    Image trainicon = LoadImage("assets/trainstation.png");
    Texture2D trainicontex = LoadTextureFromImage(trainicon);

    LocationTextureMap locationTextures = {
        {Monopoly::LocationTextures::TRAIN_TEXTURE, trainicontex}
    };

    // Colours                                        -R-   -G-   -B-   -A-
    Color background                       = (Color){ 226 , 247 , 212 , 255 };
    std::map<Monopoly::ColourSet, Color> stripColours = {
        {Monopoly::ColourSet::BROWN_M      , (Color){ 99  , 76  , 13  , 255 }},
        {Monopoly::ColourSet::LIGHT_BLUE_M , (Color){ 149 , 211 , 232 , 255 }},
        {Monopoly::ColourSet::PINK_M       , (Color){ 194 , 14  , 131 , 255 }},
        {Monopoly::ColourSet::ORANGE_M     , (Color){ 255 , 140 , 000 , 255 }},
        {Monopoly::ColourSet::RED_M        , (Color){ 230 , 16  , 16  , 255 }},
        {Monopoly::ColourSet::YELLOW_M     , (Color){ 255 , 213 , 000 , 255 }},
        {Monopoly::ColourSet::GREEN_M      , (Color){ 59  , 130 , 61  , 255 }},
        {Monopoly::ColourSet::DARK_BLUE_M  , (Color){ 25  , 35  , 145 , 255 }},
    };

    Monopoly::padding padding = {10, 10, 10, 700};

    // Game loop
    while(!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(background);
            
            Monopoly::drawBoard(locations, stripColours, screenWidth, screenHeight, padding, rowHeight, unitsPerSide, txtFont, fontsize, txtFont, poundsymbolfontsize, (Monopoly::frac){1, 20}, locationTextures);
            DrawTextEx(titleFont, "MONOPOLY", (Vector2){10, 10}, titlefontsize, 5, BLACK);

        EndDrawing();
    }

    UnloadFont(txtFont);
    UnloadFont(titleFont);

    UnloadImage(trainicon);
    UnloadTexture(trainicontex);
    CloseWindow();
    return 0;
}