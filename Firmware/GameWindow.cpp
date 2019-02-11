#include "GameWindow.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_Image.h>
#include <SDL_ttf.h>




bool GameWindow::Init(int window_width, int window_height)
{

    //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return 0;    
    }
    // freopen("CON", "w", stdout); // redirects stdout
    // freopen("CON", "w", stderr);

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return 0;
    }

    if(TTF_Init() == 1)
    {
        printf("SDL_TTF could not initialize");
        return 0;
    }

    _window = NULL;
    _renderer = NULL;

    _window = SDL_CreateWindow("First window", 100, 100, window_width, window_height, SDL_WINDOW_SHOWN);
    _window_width = window_width;
    _window_height = window_height;
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    return 1;
}


void GameWindow::Update()
{
    SDL_RenderPresent(_renderer);
}


void GameWindow::Clear()
{
    // Clear screen to white
    SDL_SetRenderDrawColor( _renderer, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderClear( _renderer );
}


SDL_Renderer *GameWindow::GetRenderer()
{
    return _renderer;
}


int GameWindow::getHeight()
{
    return _window_height;
}


int GameWindow::getWidth()
{
    return _window_width;
}


void GameWindow::Close()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}