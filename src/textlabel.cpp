#include "textlabel.hpp"
#include "window.hpp"
#include <cmath>
#include <raylib.h>

TextLabel::TextLabel(const char* text, Font& font, float fontSize, float fontSpacing, Color tint)
    : m_text(text), m_font(&font), m_fontSize(fontSize), m_fontSpacing(fontSpacing), m_tint(tint) {}

TextLabel::TextLabel(const char* text, Font& font, float fontSize, Color tint)
    : TextLabel(text, font, fontSize, 1.0f, tint) {}

void TextLabel::Draw(WindowPosition windowPosition, Vector2 offset) const {
    Vector2 position = ConvertToPosition(windowPosition) + offset;

    if (IsCentered(windowPosition))
        position.x -= GetWidth() / 2.0f;

    DrawTextEx(*m_font, m_text, position, m_fontSize, m_fontSpacing, m_tint);
}

void TextLabel::Draw(WindowPosition windowPosition) const {
    Draw(windowPosition, Vector2{});
}

void TextLabel::Draw(Vector2 position) const {
    Draw(WindowPosition::null, position);
}

int TextLabel::GetWidth() const {
    return std::round(MeasureTextEx(*m_font, m_text, m_fontSize, 1.0f).x);
}
