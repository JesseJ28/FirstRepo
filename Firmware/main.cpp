#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "dot.h"


int main(int argc, char* args[])
{
    SDL_Window *window = NULL;

    SDL_Surface *surface = NULL;

    SDL_Renderer *gRenderer;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    }
    else
    {
        window = SDL_CreateWindow("First window", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

        gRenderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );

                //Get window surface
        surface = SDL_GetWindowSurface( window );

        //Fill the surface white
        SDL_FillRect( surface, NULL, SDL_MapRGB( surface->format, 0xFF, 0xFF, 0xFF ) );
        
        //Update the surface
        SDL_UpdateWindowSurface( window );

        // //Wait two seconds
        // SDL_Delay( 2000 );
    }

    // Generic sdl event
    SDL_Event event;

    bool quit = false;

    Dot dot;

    // Game loop
    while (!quit)
    {
        // Process events until event queue is empty
        while (SDL_PollEvent(&event) != 0)
        {
            // Quit Event
            if (event.type == SDL_QUIT)
                quit = true;

            // Key Pressed Event
            if (event.type == SDL_KEYDOWN)
            {

            }

            dot.handleEvent(event);
        }
        dot.move();
        
        //Clear screen
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );

        //Render objects
        dot.render();

        //Update screen
        SDL_RenderPresent( gRenderer );
    }
        //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}