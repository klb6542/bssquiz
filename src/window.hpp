#pragma once
#include "raylib.h"

/*
Width_Height
*/
enum WindowPosition {
    null,
    CENTER_TOP,
    CENTER_CENTER,
    CENTER_BOTTOM
};

Vector2 operator +(const Vector2 other, const Vector2 other2);
bool IsCentered(WindowPosition windowPosition);
bool IsOnBottom(WindowPosition windowPosition);
Vector2 ConvertToPosition(WindowPosition windowPosition);
