#include <iostream>
#include <vector>
#include <map>
#include "raylib.h"
#include "monopoly.hpp"
#include "gui.hpp"
#include "misc.hpp"

int main() {
    locationVectors locations = Monopoly::setupBoard();

    //Board Settings
    // App might crash if params incorrect
    const int screenWidth  = 1920;
    const int screenHeight = 1080;
    
    const int fontsize            = 16;
    const int poundsymbolfontsize = 14;
    const int GUIfonttitlesize    = 76;
    const int GUIfontbodysize     = 16;

    const int rowHeight = 170;
    const int unitsPerSide = 9;

    Monopoly::padding padding = {10, 10, 10, 700};


    // Set up window
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_VSYNC_HINT);
    SetConfigFlags(FLAG_FULLSCREEN_MODE);
    InitWindow(screenWidth, screenHeight, "Monopoly");


    // Load fonts
    Font txtFont      = LoadFontEx("fonts/monopolyfont.ttf", fontsize, 0, 0);
    Font GUIfontTitle = LoadFontEx("fonts/roboto_bold.ttf", GUIfonttitlesize, 0, 0);
    Font GUIfontBody  = LoadFontEx("fonts/roboto_bold.ttf", GUIfontbodysize, 0, 0);


    // Images & Textures
    Image trainicon = LoadImage("assets/trainstation.png");
    Texture2D trainicontex = LoadTextureFromImage(trainicon);
    Monopoly::TextureStruct texstruct = {trainicontex, 40.0f};

    LocationTextureMap locationTextures = {
        {Monopoly::LocationTextures::TRAIN_TEXTURE, texstruct}
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


    // GUI
    GUI::Label TitleLabel("MONOPOLY", 10.0f, 10.0f, GUIfonttitlesize, GUIfontTitle, BLACK);


    // Game loop
    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(background);
            // Monopoly board draw
            Monopoly::drawBoard(locations, stripColours, screenWidth, screenHeight, padding, rowHeight, unitsPerSide, txtFont, fontsize, txtFont, poundsymbolfontsize, (Monopoly::frac){1, 20}, locationTextures);
            
            //GUI draw calls
            TitleLabel.draw();
        EndDrawing();
    }


    // Unload things
    UnloadFont(txtFont);
    UnloadFont(GUIfontTitle);
    UnloadFont(GUIfontBody);

    UnloadImage(trainicon);
    UnloadTexture(trainicontex);
    CloseWindow();


    // Exit program
    return 0;
}