#pragma once
#include "raylib.h"

typedef struct Size2 {
    float width;
    float height;
} Size2;

class ImageButton {
    public:
        ImageButton(const char* imagePath, Vector2 position, Size2 size);
        ImageButton(const char* imagePath, Vector2 position, float scale);
        ~ImageButton();
        void Draw() const;
    private:
        Texture2D m_texture;
        Vector2 m_position;
};
