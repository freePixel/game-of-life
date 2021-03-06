
#include "camera.h"

int main(int argc ,char* argv[])
{
    grid* grd = new grid();
    camera cam(grd);
    SDL_Event* e = new SDL_Event();
    bool running = true;
    bool mouse = false;
    point last_mouse(0,0);
    point u(0,0);
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
                int x , y;
                SDL_GetMouseState(&x,&y);
                u = cam.cameraToWorldCoordinate(x,y);
                    switch(e->key.keysym.sym)
                    {
                        case SDLK_r:
                        grd->update();
                        break;
                        case SDLK_o:
                        grd->setf(u.x,u.y,false);
                        break;
                        case SDLK_p:
                        grd->setf(u.x,u.y, true);
                        break;
                        case SDLK_m:
                        cam.change_color_mode();
                        break;
                    }
                break;
                case SDL_MOUSEWHEEL:
                if(e->wheel.y > 0) cam.scale(0.9f);
                if(e->wheel.y < 0) cam.scale(1.1f);
                break;
                case SDL_MOUSEBUTTONDOWN:
                    mouse = true;
                    last_mouse.x = e->motion.x;
                    last_mouse.y = e->motion.y;
                    break;
                case SDL_MOUSEBUTTONUP:
                mouse = false;
                break;
                case SDL_MOUSEMOTION:
                if(mouse)
                {
                    point diff(e->motion.x - last_mouse.x ,e->motion.y - last_mouse.y);
                    cam.move(0.01f * diff.x , 0.01f * diff.y);
                    last_mouse.x = e->motion.x;
                    last_mouse.y = e->motion.y;
                    break;
                }
            }
            
        }

        cam.draw();
        SDL_Delay(16);

        
    }

    delete grd;
    SDL_Quit();
    


    return 0;
}