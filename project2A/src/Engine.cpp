
#include "../include/Engine.h" // project2A include
#include <SDL2/SDL.h>
#include <iostream>

void Engine::init() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    std::cout << "Engine initialized!\n";
}

void Engine::update() {
    // Placeholder update loop
}

void Engine::shutdown() {
    SDL_Quit();
    std::cout << "Engine shut down!\n";
}
