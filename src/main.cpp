
#include "grid.h"

int main(int argc ,char* argv[])
{
    grid* grd = new grid();
    grd->fill_random(20);
    SDL_Event* e = new SDL_Event();
    bool running = true;
    while(running)
    {
        while(SDL_PollEvent(e))
        {
            switch(e->type)
            {
                case SDL_QUIT:
                running = false;
                break;
                case SDL_KEYDOWN:
                grd->update();
                break;
            }
        }

        grd->draw();
        SDL_Delay(50);

        
    }

    delete grd;
    SDL_Quit();
    


    return 0;
}