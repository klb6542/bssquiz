#pragma once
#include "drawable.hpp"
#include <raylib.h>

class TextLabel : public IDrawable {
    public:
        TextLabel(const char* text, Font& font, float fontSize, float fontSpacing, Color tint);
        TextLabel(const char* text, Font& font, float fontSize, Color tint);
        void SetText(const char* text);
        void Draw(WindowPosition windowPosition, Vector2 offset) const override;
        void Draw(WindowPosition windowPosition) const override;
        void Draw(Vector2 position) const override;
        int GetWidth() const override;
        int GetHeight() const override;
    private:
        const char* m_text;
        Font* m_font;
        float m_fontSize;
        float m_fontSpacing;
        Color m_tint;
};
