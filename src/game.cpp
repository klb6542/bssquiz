#include "game.hpp"
#include "gameasset.hpp"
#include "textlabel.hpp"
#include "timer.hpp"
#include <memory>
#include <raylib.h>
#include <string>

Game::Game(const char* title, int width, int height) {
    InitWindow(width, height, title);
    InitAudioDevice();
}

Game::~Game() {
    std::cout << "Unloading all assets!" << "\n";
    AssetManager::GetInstance().UnloadAllAssets();
    CloseAudioDevice();
    CloseWindow();
}

void Game::Start() {
    this->m_isRunning = true;

    GameAsset<Image>* windowIcon = new GameAsset<Image>(LoadImage("resources/bee_icon.png"), UnloadImage);
    SetWindowIcon(windowIcon->GetAsset());

    Font hwyGothFont = LoadFontEx("resources/HWYGOTH.ttf", 26, NULL, 256);
    SetTextLineSpacing(16);

    Music music = LoadMusicStream("resources/drone.mp3");
    PlayMusicStream(music);

    // unsafe
    TextLabel* header = new TextLabel("Welcome to the Bee Swarm Simulator Quiz!", hwyGothFont, 26.0f, RED);
    TextLabel* ingameTime = new TextLabel("Time: ", hwyGothFont, 21, BLACK);

    std::unique_ptr<Timer> timer(new Timer());

    timer->Start(4.5, [header]() {
        header->SetText("Are you ready to begin?");
    });

    while (!WindowShouldClose() && this->m_isRunning) {
        UpdateMusicStream(music);

        BeginDrawing();
            ClearBackground(RAYWHITE);
            header->Draw(WindowPosition::CENTER_CENTER);

            ingameTime->SetText(("Time: " + std::to_string(GetTime())).c_str());
            ingameTime->Draw(WindowPosition::CENTER_BOTTOM);
        EndDrawing();
    }

    /*
    UnloadMusicStream(music);
    UnloadFont(hwyGothFont);
    UnloadImage(windowIcon);
    */

    this->Stop();
}

void Game::Stop() {
    this->m_isRunning = false;
}
