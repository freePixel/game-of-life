#ifndef CAMERA_H
#define CAMERA_H

#include "grid.h"

class camera
{
    public:
    point cameraToWorldCoordinate(int x , int y);
    camera(grid* grd);
    ~camera();
    void draw();
    void scale(float factor);
    void move(float x,  float y);
    private:

    grid* grd = nullptr;

    SDL_Window* window = nullptr;
    SDL_Renderer* render = nullptr;
    int wx = 800;
    int wy = 800;

    float scf = 20.0f;

    float px = 0.0;
    float py = 0.0;
};

#endif