#include "camera.h"

camera::camera(grid* grd)
{
    this->grd = grd;
    window = SDL_CreateWindow("game of life" , SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,wx,wy,0);
    render = SDL_CreateRenderer(window , - 1 , 0);
}

camera::~camera()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
}

point camera::cameraToWorldCoordinate(int x , int y)
{
    float rx = 0;
    float ry = 0;
    rx = x / (wx /scf);
    ry = y / (wy / scf);

    rx -= px;
    ry -= py;

   
    return point(int(rx) , int(ry));
}

void camera::move(float x , float y)
{
    px += x * scf / 20;
    py += y * scf / 20;
}

void camera::scale(float factor)
{
    scf *= factor;
}

void camera::draw()
{
    SDL_RenderClear(render);
    SDL_SetRenderDrawColor(render , 255 , 255 , 255 , 255);
    for(auto it = grd->data.begin(); it != grd->data.end(); ++it)
    {
        SDL_FRect* r = new SDL_FRect{(float)wx*(it->x+px) / scf,(float)wy*(it->y+py) / scf,(float)wx/scf,(float)wy/scf};
        SDL_RenderFillRectF(render , r);
        delete r;
    }
    SDL_SetRenderDrawColor(render,0,0,0,0);
    SDL_RenderPresent(render);
}