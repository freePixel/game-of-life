#include "grid.h"



grid::grid()
{
    window = SDL_CreateWindow("game of life" , SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,400,400,0);
    render = SDL_CreateRenderer(window , - 1 , 0);
    for(int i=0;i<20;i++)
    {
        data[i].fill(0);
    }
}

void grid::update()
{
    for(int y=0;y<20;y++)
    {
        for(int x=0;x<20;x++)
        {
            int c = neightbour_count(x,y);
            if(data[y][x])
            {
                if(c < 2 || c > 3) changes.push_back({x,y,false});
            }
            else{
                if(c == 3) changes.push_back({x,y,true});
            }
        }
    }
    for(int i=0;i<changes.size();i++)
    {
        cell s = changes[i];
        data[s.y][s.x] = s.status;
    }
    changes.clear();
}

int grid::neightbour_count(int x , int y)
{
    int c = 0;
    for(int dy=-1;dy<=1;dy++)
    {
        for(int dx=-1;dx<=1;dx++)
        {
            if(dx != 0 && dy != 0)
            {
                if(get(x+dx , y+dy)) c++;
            }
        }
    }


    return c;
}

grid::~grid()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(render);
}

void grid::set(int x , int y , bool alive)
{
    data[y][x] = alive;
}

bool grid::get(int x , int y)
{
    if(x < 0 || x > 20) return false;
    if(y < 0 || y > 20) return false;

    return data[y][x];
}

void grid::draw()
{
    SDL_RenderClear(render);
    SDL_SetRenderDrawColor(render , 255 , 255 , 255 , 255);
    for(int y=0;y<20;y++)
    {
        for(int x=0;x<20;x++)
        {
            if(data[y][x])
            {
                SDL_Rect* r = new SDL_Rect{20*x,20*y,20,20};
                SDL_RenderFillRect(render , r);
                delete r;
            }
        }
    }
    SDL_SetRenderDrawColor(render,0,0,0,0);
    SDL_RenderPresent(render);
}