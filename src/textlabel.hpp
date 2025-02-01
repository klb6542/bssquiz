#pragma once
#include "window.hpp"
#include <raylib.h>

class TextLabel {
    public:
        TextLabel(const char* text, Font& font, float fontSize, float fontSpacing, Color tint);
        TextLabel(const char* text, Font& font, float fontSize, Color tint);
        void Draw(WindowPosition windowPosition, Vector2 offset) const;
        void Draw(WindowPosition windowPosition) const;
        void Draw(Vector2 position) const;
        int GetWidth() const;
        int GetHeight() const;
    private:
        const char* m_text;
        Font* m_font;
        float m_fontSize;
        float m_fontSpacing;
        Color m_tint;
};
