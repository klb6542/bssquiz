#include "game.hpp"
#include <cmath>
#include <cstring>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450

int main(void) {
    Game* game = new Game("Bee Swarm Simulator Quiz", SCREEN_WIDTH, SCREEN_HEIGHT);
    game->Start();
    delete game;
    return 0;
}
