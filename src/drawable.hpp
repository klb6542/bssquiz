#pragma once
#include "window.hpp"

class IDrawable {
    public:
        virtual void Draw(WindowPosition windowPosition, Vector2 offset) const = 0;
        virtual void Draw(WindowPosition windowPosition) const = 0;
        virtual void Draw(Vector2 position) const = 0;
        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;
};
