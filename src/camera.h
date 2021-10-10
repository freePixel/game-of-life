#ifndef CAMERA_H
#define CAMERA_H

#include "grid.h"

enum MODE
{
    DARK = 0, WHITE , BLUE
};

enum FIGURE
{
    BACKGROUND = 0, LINE , CELL
};

class camera
{
    public:
    point cameraToWorldCoordinate(int x , int y);
    camera(grid* grd);
    ~camera();
    void draw();
    void change_color_mode();
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

    void set_object_color(MODE mode , FIGURE figure);
    MODE mode = MODE::DARK;
};

#endif