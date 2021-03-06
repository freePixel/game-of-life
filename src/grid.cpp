#include "grid.h"


void grid::update()
{
    changes.clear();
    for(int i=0;i<data.size();i++){
        int x = data[i].x;
        int y = data[i].y;
        for(int dx=-1;dx<=1;dx++)
        {

            for(int dy=-1;dy<=1;dy++)
            {
                next_state(x + dx , y + dy);
            }
        }
        
    }
    for(int i=0;i<changes.size();i++)
    {
        setf(changes[i].p.x, changes[i].p.y , changes[i].status);
    }
}


void grid::next_state(int x , int y)
{
    int c = neightbour_count(x , y);
    bool st = get(x,y);
    if(st == false && c == 3)
    {
        changes.push_back(cell{point(x,y),true});
    }
    if(st == true && (c < 2 || c > 3))
    {
        changes.push_back(cell{point(x,y),false});
    }
}


int grid::neightbour_count(int x , int y)
{
    int c = 0;
    for(int dy=-1;dy<=1;dy++)
    {
        for(int dx=-1;dx<=1;dx++)
        {
            if(dx != 0 || dy != 0)
            {
                if(get(x+dx , y+dy)) c++;
            }
        }
    }
    return c;
}

void grid::fill_random(int alive_probability , int length)
{
    for(int y=0;y<length;y++)
    {
        for(int x=0;x<length;x++)
        {
            int r = rand() % 100;
            if(alive_probability > r)
            {
                setf(x , y , true);
            }
        }
    }
}

void grid::setf(int x , int y , bool alive)
{
    if(alive == false)
    {
        for(int i=0;i<data.size();i++)
        {
            if(data[i].x == x && data[i].y == y) data.erase(data.begin() + i);
        }
    }
    else{
        for(int i=0;i<data.size();i++)
        {
            if(data[i].x == x && data[i].y == y) return;
        }
        data.push_back({x,y});
    }
}

bool grid::get(int x , int y)
{
    for(int i=0;i<data.size();i++)
    {
        if(data[i].x == x && data[i].y == y) return true;
    }
    return false;
}


