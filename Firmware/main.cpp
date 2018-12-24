#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>



int main(int argc, char* args[])
{
    SDL_Window *window = NULL;

    SDL_Surface *surface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        window = SDL_CreateWindow("first window", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

                    //Get window surface
            surface = SDL_GetWindowSurface( window );

            //Fill the surface white
            SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ) );
            
            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 2000 );
    }

        //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}