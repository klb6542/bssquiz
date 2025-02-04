#include "textlabel.hpp"
#include "raylib.h"
#include "timer.hpp"
#include "window.hpp"
#include <cmath>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Bee Swarm Simulator Quiz");
    InitAudioDevice();

    Image windowIcon = LoadImage("resources/bee_icon.png");
    SetWindowIcon(windowIcon);

    Font hwyGothFont = LoadFontEx("resources/HWYGOTH.ttf", 26, NULL, 256);
    SetTextLineSpacing(16);

    Music music = LoadMusicStream("resources/drone.mp3");
    PlayMusicStream(music);

    // unsafe
    TextLabel* header = new TextLabel("Welcome to the Bee Swarm Simulator Quiz!", hwyGothFont, 26.0f, RED);
    TextLabel* ingameTime = new TextLabel("Time: ", hwyGothFont, 21, BLACK);

    std::unique_ptr<Timer> timer(new Timer());

    timer->Start(3.0, [header]() {
        header->SetText("Are you ready to begin?");
    });

    timer->Start(6.0, [header]() {
        header->SetText("Beginning now!");
    });

    while (!WindowShouldClose()) {
        UpdateMusicStream(music);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            header->Draw(WindowPosition::CENTER_CENTER);

            ingameTime->SetText(("Time: " + std::to_string(GetTime())).c_str());
            ingameTime->Draw(WindowPosition::CENTER_BOTTOM);
        EndDrawing();
    }

    UnloadFont(hwyGothFont);
    UnloadImage(windowIcon);

    CloseAudioDevice();
    CloseWindow();
}
