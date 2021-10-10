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
    float f = scf * factor;
    if(f >= 1 && f < 800) scf = f;
}

void camera::set_object_color(MODE mode , FIGURE figure)
{
    SDL_Color color;
    if(mode == MODE::DARK)
    {
        if(figure == FIGURE::BACKGROUND) color = {0,0,0,0};
        if(figure == FIGURE::LINE) color = {23,32,23,11};
        if(figure == FIGURE::CELL) color = {255,255,255,255};
    }
    if(mode == MODE::WHITE)
    {
        if(figure == FIGURE::BACKGROUND) color = {255,255,255,255};
        if(figure == FIGURE::LINE) color = {255,0,255,255};
        if(figure == FIGURE::CELL) color = {0,0,0,0};
    }
    if(mode == MODE::BLUE)
    {
        if(figure == FIGURE::BACKGROUND) color = {0,0,127,0};
        if(figure == FIGURE::LINE) color = {255,255,255,255};
        if(figure == FIGURE::CELL) color = {255,255,255,255};
    }
    SDL_SetRenderDrawColor(render , color.r , color.g , color.b , color.a);

}

void camera::change_color_mode()
{
    if(int(mode) >= 2) mode = MODE::DARK;
    else{
        mode = MODE(int(mode)+1);
    }
}

void camera::draw()
{
    SDL_RenderClear(render);

    if(scf < 100) //only render line in small zoom
    {

        set_object_color(mode , FIGURE::LINE);

        float dx = int(px*wx/scf) % int(wx/scf);
        float dy = int(py*wy/scf) % int(wy/scf);

        for(int i=0;i<scf;i++)
        {
            SDL_RenderDrawLineF(render,dx+wx*i/scf,0,dx+wx*i/scf,wy);
            SDL_RenderDrawLineF(render,0,dy+wx*i/scf,wx,dy+wx*i/scf);
        }
    }
    set_object_color(mode , FIGURE::CELL);
    for(auto it = grd->data.begin(); it != grd->data.end(); ++it)
    {
        SDL_FRect* r = new SDL_FRect{(float)wx*(it->x+px) / scf,(float)wy*(it->y+py) / scf,(float)wx/scf,(float)wy/scf};
        SDL_RenderFillRectF(render , r);
        delete r;
    }
    //Draw lines
    

    set_object_color(mode , FIGURE::BACKGROUND);
    SDL_RenderPresent(render);
}