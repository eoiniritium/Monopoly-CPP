#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "raylib.h"

namespace misc {
    std::string wrapText(std::string txt, Font font, int fontsize, int max_width) {
        Vector2 txtLen = MeasureTextEx(font, &txt[0], fontsize, 0); // spacing always = 0
        if(txtLen.x <= max_width) {
            return txt;
        }
        std::string inp = txt;

        std::string ret = "";
        while(true) {
            int i = 0;
            while(MeasureTextEx(font, &(inp.substr(i++))[0], fontsize, 0).x < max_width) {
                ret += txt[i];
                std::cout << ret << std::endl;
            }

            if(i == 0) {
                break;
            }
            ret += '\n';
            inp.erase(0, i);
        }

        return ret;
    }
}