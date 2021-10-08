#ifndef GRID_H
#define GRID_H

#include <array>
#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#define SIZE 40


struct point
{
    int x = 0;
    int y = 0;
    point(int x , int y)
    {
        this->x = x;
        this->y = y;
    }

};

struct cell
{
    point p;
    bool status;
};


class grid
{
    public:
        grid();
        ~grid();
        void setf(int x , int y , bool alive);
        bool get(int x , int y);

        void fill_random(int alive_probability , int length);

        void update();
        void draw();
    private:

        void next_state(int x , int y);

        std::vector<point> data;

        SDL_Window* window = nullptr;
        SDL_Renderer* render = nullptr;
        std::vector<cell> changes;
        int neightbour_count(int x , int y);
        int wx = 800;
        int wy = 800;
};


#endif