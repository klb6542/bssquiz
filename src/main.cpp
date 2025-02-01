#include "button.hpp"
#include "raylib.h"

int main(void) {
    InitWindow(800, 450, "Bee Swarm Simulator Quiz");

    Image image = LoadImage("resources/basic_bee.png");
    SetWindowIcon(image);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
}
