#pragma once
#include <iostream>
#include <vector>
#include <map>
#include "raylib.h"

namespace Monopoly {
    enum LocationID {
        GO,
        OLD_KENT_ROAD,
        COMMUNITY_CHEST,
        WHITECHAPEL_ROAD,
        INCOME_TAX,
        KINGS_CROSS_STATION,
        THE_ANGEL_ISLINGTON,
        CHANCE,
        EUSTON_ROAD,
        PENTONVILLE_ROAD,
        JAIL,
        PALL_MALL,
        ELECTRIC_COMPANY,
        WHITEHALL,
        NORTHUMBERLAND_AVENUE,
        MARYLEBONE_STATION,
        BOW_STREET,
        MARLBOROUGH_STREET,
        VINE_STREET,
        PARKING,
        STRAND,
        FLEET_STREET,
        TRAFALGAR_SQUARE,
        FENCHURCH_ST_STATION,
        LEICESTER_SQUARE,
        COVENTRY_STREET,
        WATER_WORKS,
        PICADILLY,
        GO_JAIL,
        REGENT_STREET,
        OXFORD_STREET,
        BOND_STREET,
        LIVERPOOL_ST_STATION,
        PARK_LANE,
        SUPER_TAX,
        MAYFAIR
    };

    enum LocationType {
        STREET_TYPE,
        CHANCE_TYPE,
        COMMUNITY_CHEST_TYPE,
        TRAIN_STATION_TYPE,
        UTILITIES_TYPE,
        GO_TYPE,
        JAIL_TYPE,
        PARKING_TYPE,
        GO_JAIL_TYPE,
        TAX_TYPE
    };

    enum ColourSet {
        BROWN_M,
        LIGHT_BLUE_M,
        PINK_M,
        ORANGE_M,
        RED_M,
        YELLOW_M,
        GREEN_M,
        DARK_BLUE_M,
        NA_M
    };

    enum direction {
        NORTH,
        EAST,
        SOUTH,
        WEST
    };

    struct Location {
        LocationID id;
        LocationType type;
        ColourSet colour;
        std::string name;
        int cost;
        int house_price;
    };
    
    class Player {
        public:
        Player() {

        }

        int getBoardLocation() {
            return board_location;
        }

        private:
        int funds;
        std::vector<Location> locations_bought;
        int board_location;
    };

    std::vector<Location> setupBoard() {
        std::vector<Location> ret;

        //             -----Location  ID-----  ----Location type----  ----Colour----  -------Location Name-------  -Cost- -House price-
        ret.push_back({GO                    , GO_TYPE              , NA_M          , "GO"                       , 200   , 0           });
        ret.push_back({OLD_KENT_ROAD         , STREET_TYPE          , BROWN_M       , "OLD KENT ROAD"            , 60    , 0           });
        ret.push_back({COMMUNITY_CHEST       , COMMUNITY_CHEST_TYPE , NA_M          , "COMMUNITY CHEST"          , 0     , 0           });
        ret.push_back({WHITECHAPEL_ROAD      , STREET_TYPE          , BROWN_M       , "WHITE CHAPEL ROAD"        , 60    , 0           });
        ret.push_back({INCOME_TAX            , TAX_TYPE             , NA_M          , "INCOME TAX"               , 100   , 0           });
        ret.push_back({KINGS_CROSS_STATION   , TRAIN_STATION_TYPE   , NA_M          , "KING'S CROSS STATION"     , 200   , 0           });
        ret.push_back({THE_ANGEL_ISLINGTON   , STREET_TYPE          , LIGHT_BLUE_M  , "THE ANGEL ISLINGTON"      , 100   , 0           });
        ret.push_back({CHANCE                , CHANCE_TYPE          , NA_M          , "CHANCE"                   , 0     , 0           });
        ret.push_back({EUSTON_ROAD           , STREET_TYPE          , LIGHT_BLUE_M  , "EUSTON ROAD"              , 100   , 0           });
        ret.push_back({PENTONVILLE_ROAD      , STREET_TYPE          , LIGHT_BLUE_M  , "PENTONVILLE ROAD"         , 120   , 0           });
        ret.push_back({JAIL                  , JAIL_TYPE            , NA_M          , "IN JAIL\nJUST VISITING"   , 0     , 0           });
        ret.push_back({PALL_MALL             , STREET_TYPE          , PINK_M        , "PALL MALL"                , 140   , 0           });
        ret.push_back({ELECTRIC_COMPANY      , UTILITIES_TYPE       , NA_M          , "ELECTRIC COMPANY"         , 150   , 0           });
        ret.push_back({WHITEHALL             , STREET_TYPE          , PINK_M        , "WHITEHALL"                , 140   , 0           });
        ret.push_back({NORTHUMBERLAND_AVENUE , STREET_TYPE          , PINK_M        , "NORTHUMBERLAND AVENUE"    , 160   , 0           });
        ret.push_back({MARYLEBONE_STATION    , TRAIN_STATION_TYPE   , NA_M          , "MARYLEBONE STATION"       , 200   , 0           });
        ret.push_back({BOW_STREET            , STREET_TYPE          , ORANGE_M      , "BOW STREET"               , 180   , 0           });
        ret.push_back({COMMUNITY_CHEST       , COMMUNITY_CHEST_TYPE , NA_M          , "COMMUNITY CHEST"          , 0     , 0           });
        ret.push_back({MARLBOROUGH_STREET    , STREET_TYPE          , ORANGE_M      , "MARLBOROUGH STREET"       , 180   , 0           });
        ret.push_back({VINE_STREET           , STREET_TYPE          , ORANGE_M      , "VINE STREET"              , 200   , 0           });
        ret.push_back({PARKING               , PARKING_TYPE         , NA_M          , "FREE PARKING"             , 0     , 0           });
        ret.push_back({STRAND                , STREET_TYPE          , RED_M         , "STRAND"                   , 220   , 0           });
        ret.push_back({CHANCE                , CHANCE_TYPE          , NA_M          , "CHANCE"                   , 0     , 0           });
        ret.push_back({FLEET_STREET          , STREET_TYPE          , RED_M         , "FLEET STREET"             , 220   , 0           });
        ret.push_back({TRAFALGAR_SQUARE      , STREET_TYPE          , RED_M         , "TRAFALGAR SQUARE"         , 240   , 0           });
        ret.push_back({FENCHURCH_ST_STATION  , TRAIN_STATION_TYPE   , NA_M          , "FENCHURCH STREET STATION" , 200   , 0           });
        ret.push_back({LEICESTER_SQUARE      , STREET_TYPE          , YELLOW_M      , "LEICESTER SQUARE"         , 260   , 0           });
        ret.push_back({COVENTRY_STREET       , STREET_TYPE          , YELLOW_M      , "COVENTRY STREET"          , 260   , 0           });
        ret.push_back({WATER_WORKS           , UTILITIES_TYPE       , NA_M          , "WATER WORKS"              , 150   , 0           });
        ret.push_back({PICADILLY             , STREET_TYPE          , YELLOW_M      , "PICCADILLY"               , 280   , 0           });
        ret.push_back({GO_JAIL               , GO_JAIL_TYPE         , NA_M          , "GO TO JAIL"               , 0     , 0           });
        ret.push_back({REGENT_STREET         , STREET_TYPE          , GREEN_M       , "REGENT STREET"            , 300   , 0           });
        ret.push_back({OXFORD_STREET         , STREET_TYPE          , GREEN_M       , "OXFORD STREET"            , 300   , 0           });
        ret.push_back({COMMUNITY_CHEST       , COMMUNITY_CHEST_TYPE , NA_M          , "COMMUNITY CHEST"          , 0     , 0           });
        ret.push_back({BOND_STREET           , STREET_TYPE          , GREEN_M       , "BOND STREET"              , 320   , 0           });
        ret.push_back({LIVERPOOL_ST_STATION  , TRAIN_STATION_TYPE   , NA_M          , "LIVERPOOL STREET STATION" , 200   , 0           });
        ret.push_back({CHANCE                , CHANCE_TYPE          , NA_M          , "CHANCE"                   , 0     , 0           });
        ret.push_back({PARK_LANE             , STREET_TYPE          , DARK_BLUE_M   , "PARK LANE"                , 350   , 0           });
        ret.push_back({SUPER_TAX             , TAX_TYPE             , NA_M          , "SUPER TAX"                , 200   , 0           });
        ret.push_back({MAYFAIR               , STREET_TYPE          , DARK_BLUE_M   , "MAYFAIR"                  , 400   , 0           });

        return ret;
    }

    struct padding {
        int top;
        int right;
        int bottom;
        int left;
    };

    struct frac {
        float top;
        float bottom;
    };

    namespace drawing {
        void drawCorner(int row_height, std::string txt, int x, int y, Color col, Font font, int fs) {
            DrawRectangle(x, y, row_height, row_height, col);
            DrawTextEx(font, &txt[0], (Vector2){(float)(x+5), (float)(y+5)}, fs, 0, WHITE);
        }

        float getWidthNS(int units_per_side, int screenwidth, padding pad, int rowHeight) {
            float range = screenwidth - pad.right - pad.left - 2*(rowHeight);
            return range / units_per_side;
        }

        float getWidthWE(int units_per_side, int screenheight, padding pad, int rowHeight) {
            float range = screenheight - pad.top - pad.bottom - 2*(rowHeight);
            return range / units_per_side;
        }

        float resolveFraction(frac fraction) {
            float resolved = fraction.top / fraction.bottom;
            return resolved;
        }

        void drawCorners(std::vector<Location> boardLocations, int sw, int sh, padding pad, int rowHeight, Font font, int fs) {
            int sideL = rowHeight;
            drawCorner(sideL , boardLocations[00].name, sw - pad.right - sideL , sh - sideL - pad.bottom , RED    , font, fs);
            drawCorner(sideL , boardLocations[10].name, pad.left               , sh - sideL - pad.bottom , ORANGE , font, fs);
            drawCorner(sideL , boardLocations[20].name, pad.left               , pad.top                 , GREEN  , font, fs);
            drawCorner(sideL , boardLocations[30].name, sw - pad.right - sideL , pad.top                 , BLUE   , font, fs);
        }

        void drawLocation(direction dir, int x, int y, int width, int height, Color background, Color outline, Color banner, Location location, frac bannerHeightAsFractionOfCardHeight) {
            DrawRectangle(x, y, width, height, background);
            float fraction   = resolveFraction(bannerHeightAsFractionOfCardHeight);
            frac  unResolved = bannerHeightAsFractionOfCardHeight;
            switch(dir) {
                case NORTH:
                    //std::cout << fraction << std::endl;
                    DrawRectangle(x, y, width, height * fraction, banner);
                    break;
                case SOUTH:
                    DrawRectangle(x, y + ((unResolved.bottom - unResolved.top) * (float)height) * fraction, width, fraction * (float)height, banner);
                    break;
                case WEST:
                    DrawRectangle(x, y, (float)width * fraction, height, banner);
                    break;
                case EAST:
                    DrawRectangle(x + ((unResolved.bottom - unResolved.top) * (float)width) * fraction, y, fraction * float(width), height, banner);
                    break;
            }
            DrawRectangleLinesEx((Rectangle){(float)x, (float)y, (float)width, (float)height}, 0.75f, outline);
        }
    
        void drawSides(std::vector<Location> boardLocations, std::map<ColourSet, Color> bannerColours, int sw, int sh, padding pad, int rowHeight, int units_per_side, Font font, int fs, frac bannerHeightAsFractionOfCardHeight) {
            float NS_width  = getWidthNS(units_per_side, sw, pad, rowHeight);
            int NS_height = rowHeight;

            int EW_width  = rowHeight;
            float EW_height = getWidthWE(units_per_side, sh, pad, rowHeight);

            int side = -1;
            int topcount = 0;
            int rightcount = 0;
            int leftcount = 0;
            for(size_t i = 0; i < boardLocations.size(); ++i) {
                if((i%10) == 0) { // if it is corner
                    ++side;
                    continue;
                }
                
                switch(side) {
                    // BOTTOM
                    case 0: //        -dir-   ----------------x location-------------------    -----------------------y location------------------------   -width--   -height-    -background colour-  -outline colour-  -----------banner colour---------------   ----location-----  ----------banner height-----------
                        drawLocation( NORTH , (sw - pad.right) - (i * NS_width) - rowHeight  , (sh - pad.bottom) - NS_height                             , NS_width , NS_height , WHITE              , BLACK           , bannerColours[boardLocations[i].colour] , boardLocations[i] , bannerHeightAsFractionOfCardHeight );
                        break;
                    // LEFT
                    case 1:
                        drawLocation( EAST  , pad.left                                       , (sh - pad.bottom - rowHeight) - (++leftcount * EW_height) , EW_width , EW_height , WHITE              , BLACK           , bannerColours[boardLocations[i].colour] , boardLocations[i] , bannerHeightAsFractionOfCardHeight );
                        break;
                    // TOP
                    case 2:
                        drawLocation( SOUTH , pad.left + rowHeight + (topcount++ * NS_width) , pad.top                                                   , NS_width , NS_height , WHITE              , BLACK           , bannerColours[boardLocations[i].colour] , boardLocations[i] , bannerHeightAsFractionOfCardHeight );
                        break;
                    // RIGHT
                    case 3:
                        drawLocation( WEST  , sw - pad.right - EW_width                      , pad.top + rowHeight + (rightcount++ * EW_height)          , EW_width , EW_height , WHITE              , BLACK           , bannerColours[boardLocations[i].colour] , boardLocations[i] , bannerHeightAsFractionOfCardHeight );
                        break;
                }
            }
        }
    }

    void drawBoard(std::vector<Location> boardLocations, std::map<ColourSet, Color> stripColours, int screenwidth, int screenheight, padding pad, int row_height, int units_per_side, Font font, int fontsize, frac bannerHeight) {
        drawing::drawSides(boardLocations, stripColours, screenwidth, screenheight, pad, row_height, units_per_side, font, fontsize, bannerHeight);
        drawing::drawCorners(boardLocations, screenwidth, screenheight, pad, row_height, font, fontsize);
    }
}

typedef std::vector<Monopoly::Location> locationVectors;