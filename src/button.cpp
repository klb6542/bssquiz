#include "button.hpp"
#include <raylib.h>

Button::Button(const char* imagePath, Vector2 position, Size2 size) {
    Image image = LoadImage(imagePath);
    ImageResize(&image, static_cast<int>(size.width), static_cast<int>(size.height));

    m_position = position;
    m_texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Button::Button(const char* imagePath, Vector2 position, float scale) {
    Image image = LoadImage(imagePath);
    Size2 size{image.width * scale, image.height * scale};

    UnloadImage(image);
    Button(imagePath, position, size);
}

Button::Button(const char* imagePath, Vector2 position)
    : Button(imagePath, position, 1.0f) {
}

Button::~Button() {
    UnloadTexture(m_texture);
}

void Button::Draw() {
    DrawTextureV(m_texture, m_position, WHITE);
}
