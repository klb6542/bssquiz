#include "imagebutton.hpp"
#include <raylib.h>

ImageButton::ImageButton(const char* imagePath, Vector2 position, Size2 size) {
    Image image = LoadImage(imagePath);
    ImageResize(&image, static_cast<int>(size.width), static_cast<int>(size.height));

    m_position = position;
    m_texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

ImageButton::ImageButton(const char* imagePath, Vector2 position, float scale) {
    Image image = LoadImage(imagePath);
    Size2 size{image.width * scale, image.height * scale};

    UnloadImage(image);
    ImageButton(imagePath, position, size);
}

ImageButton::~ImageButton() {
    UnloadTexture(m_texture);
}

void ImageButton::Draw() const {
    DrawTextureV(m_texture, m_position, WHITE);
}
