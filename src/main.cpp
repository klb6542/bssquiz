#include "textlabel.hpp"
#include "raylib.h"
#include "window.hpp"
#include <cmath>
#include <cstddef>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bee Swarm Simulator Quiz");

    Image windowIcon = LoadImage("resources/bee_icon.png");
    SetWindowIcon(windowIcon);

    Font hwyGothFont = LoadFontEx("resources/HWYGOTH.ttf", 27, NULL, 256);
    SetTextLineSpacing(16);

    TextLabel* label = new TextLabel("Welcome to the Bee Swarm Simulator Quiz!", hwyGothFont, 26.0f, RED);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            label->Draw(WindowPosition::CENTER_TOP);
        EndDrawing();
    }

    UnloadFont(hwyGothFont);
    UnloadImage(windowIcon);
    CloseWindow();
}
