#include "window.hpp"
#include <raylib.h>

Vector2 operator +(const Vector2& other, const Vector2& other2) {
    return Vector2{other.x + other2.x, other.y + other2.y};
}

bool IsCentered(WindowPosition windowPosition) {
    switch (windowPosition) {
        case CENTER_TOP:
        case CENTER_CENTER:
        case CENTER_BOTTOM:
            return true;
        default:
            return false;
    }
}

bool IsOnBottom(WindowPosition windowPosition) {
    switch (windowPosition) {
        case CENTER_BOTTOM:
            return true;
        default:
            return false;
    }
}

Vector2 ConvertToPosition(WindowPosition windowPosition) {
    switch (windowPosition) {
        case CENTER_TOP:
            return Vector2{GetScreenWidth() / 2.0f, 0.0f};
        case CENTER_CENTER:
            return Vector2{GetScreenWidth() / 2.0f, GetScreenHeight() / 2.0f};
        case CENTER_BOTTOM:
            return Vector2{GetScreenWidth() / 2.0f, static_cast<float>(GetScreenHeight())};
        case null:
        default:
            return Vector2{};
    }
}
