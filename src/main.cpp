#include "types.h"

int main(int argc, char** argv) {
    std::cout << "rTech : ";
    std::cout << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;

    //The window we'll be rendering to
    SDL_Window* window = NULL;
    
    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    }
    else
    {
        int flags = SDL_WINDOW_OPENGL;
        //Create window
        window = SDL_CreateWindow( "rTech Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, flags);
        if( window == NULL )
        {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            //Fill the surface black
            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0x00, 0x00 ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );
            SDL_Event e;
            bool quit = false;
            while (!quit){
                while (SDL_PollEvent(&e)){
                    if (e.type == SDL_QUIT){
                        quit = true;
                    }
                    if (e.type == SDL_KEYDOWN){
                        quit = true;
                    }
                    if (e.type == SDL_MOUSEBUTTONDOWN){
                        quit = true;
                    }
                    SDL_UpdateWindowSurface(window);
                }
            }
        }
    }
    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();
    return 0;
}