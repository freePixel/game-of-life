#ifndef GRID_H
#define GRID_H

#include <array>
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

struct cell
{
    int x , y;
    bool status;
};

class grid
{
    public:
        grid();
        ~grid();
        void set(int x , int y , bool alive);
        bool get(int x , int y);

        void update();
        void draw();
    private:
        std::array<std::array<bool,20>,20> data;

        SDL_Window* window = nullptr;
        SDL_Renderer* render = nullptr;
        std::vector<cell> changes;
        int neightbour_count(int x , int y);
};


#endif