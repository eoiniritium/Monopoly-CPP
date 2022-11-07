#pragma once
#include <string>
#include <vector>
#include "raylib.h"
#include "monopoly.hpp"

namespace GUI {
    class Label {
        public:
        Label(std::string text, float x, float y, float fontsize, Font font, Color colour = WHITE) {
            this->text = text;
            this->x = x;
            this->y = y;
            this->fontsize = fontsize;
            this->font = font;
            this->colour = colour;
        }

        void changeText(std::string newText) {
            this->text = newText;
        }

        void setXY(float x, float y) {
            this->x = x;
            this->y = y;
        }

        void draw() {
            DrawTextEx(this->font, this->text.c_str(), (Vector2){x,y}, this->fontsize, 0, this->colour);
        }

        Vector2 getDimensions() {
            return MeasureTextEx(this->font, this->text.c_str(), this->fontsize, 0);
        }

        protected:
        std::string text;
        float x, y;
        float fontsize;
        Font font;
        Color colour;
    };

    class LabelWithBackground : protected Label {
        public:
        LabelWithBackground(std::string text, float x, float y, float fontsize, Font font, Color colour = WHITE, Color backgroundcolour = BLACK, Monopoly::padding padding = (Monopoly::padding){10, 10, 10, 10})
        : Label(text, x, y, fontsize, font, colour) // Inherit from Label
        {
            this->backgroundcolour = backgroundcolour;
            this->padding = padding;
            Label::setXY((Label::x + padding.left), (Label::y + padding.top)); // Shift text over

        }

        void changeText(std::string newText) {
            Label::changeText(newText);
        }

        void setXY(float x, float y) {
            Label::setXY(x, y);
        }

        void draw() {
            Vector2 measured = MeasureTextEx(Label::font, Label::text.c_str(), Label::fontsize, 0);
            DrawRectangle(Label::x - this->padding.left, Label::y - this->padding.top, measured.x + this->padding.left + this->padding.right, measured.y + this->padding.top + this->padding.bottom, this->backgroundcolour);
            Label::draw();
        }

        Vector2 getDimensions() {
            Vector2 ret = MeasureTextEx(this->font, this->text.c_str(), this->fontsize, 0);
            ret.x += this->padding.left + this->padding.right;
            ret.y += this->padding.top + this->padding.bottom;

            return ret;
        }

        private:
        Color backgroundcolour;
        Monopoly::padding padding;
    };

}