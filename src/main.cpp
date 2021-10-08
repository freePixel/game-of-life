
#include "grid.h"

int main(int argc ,char* argv[])
{
    grid* grd = new grid();
    grd->set(0 , 0 , true);
    grd->set(0 , 2 , true);
    grd->set(1 , 1 , true);
    grd->set(1 , 2 , true);
    grd->set(2 , 1 , true);
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
                std::cout << "key_pressed" << "\n";
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