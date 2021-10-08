#include <SDL2/SDL.h>

int main(int argc ,char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* w = SDL_CreateWindow("game-of-life",500,500,500,500,0);
    SDL_Renderer* r = SDL_CreateRenderer(w , -1 , 0);
    SDL_Delay(3000);
    return 0;
}