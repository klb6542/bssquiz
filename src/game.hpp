#pragma once
#include <raylib.h>

class Game {
    public:
        Game(const char* title, int width, int height);
        ~Game();
        void Start();
        void Stop();
    private:
        bool m_isRunning;
};
