#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "raylib.h"
#include "monopoly.hpp"

namespace misc {
    std::string wrapText(std::string txt, Font font, float fontsize, float max_width) {
        
        std::string wor = txt;
        std::string ret = "";
        std::string substr;
        int i;

        while(wor.length() > 0) {
            if(MeasureTextEx(font, wor.c_str(), fontsize, 0).x >= max_width) {
                i = 0;
                do {
                    
                    substr = wor.substr(0, i++);
                } while(MeasureTextEx(font, substr.c_str(), fontsize, 0).x < max_width);
                ret += substr + "\n";
                wor.erase(0, i-1);
            }
            else{
                ret += wor;
                break;
            }
        }

        // Check if first chars are ' '
        for(i = 0; (size_t)i < ret.length(); ++i) {
            if(ret[i] == '\n' && ret[i+1] == ' ') {
                ret.erase(i+1, 1);
            }
        }
        return ret;
    }
}

template<typename T>
    bool matchList(T var, std::vector<T> matches) {
        for(auto itr : matches) {
            if(itr == var) return true;
        }
        return false;
    }