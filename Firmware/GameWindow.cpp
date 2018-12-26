#include "GameWindow.h"
#include <stdio.h>
#include <SDL.h>




bool GameWindow::Init()
{
    _window = NULL;
    _surface = NULL;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 0;    
    }

    _surface = SDL_GetWindowSurface( _window );

    return 1;
}

void GameWindow::Update()
{
    SDL_UpdateWindowSurface( _window );
}