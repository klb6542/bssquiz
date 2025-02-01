#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawFPS(50, 50);
            DrawText("Congrats! You created your first window!", 190, 200, 20, RED);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
