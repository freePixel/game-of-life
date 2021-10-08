#ifndef GRID_H
#define GRID_H

#include <array>
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#define SIZE 40

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

        void fill_random(int alive_probability);

        void update();
        void draw();
    private:
        std::array<std::array<bool,SIZE>,SIZE> data;

        SDL_Window* window = nullptr;
        SDL_Renderer* render = nullptr;
        std::vector<cell> changes;
        int neightbour_count(int x , int y);

        int wx = 800;
        int wy = 800;
};


#endif