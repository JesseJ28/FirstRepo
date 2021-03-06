#include "GameWindow.h"
#include <stdio.h>
#include <SDL.h>
#include <SDL_Image.h>
#include <SDL_ttf.h>



GameWindow::GameWindow()
{
    //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return;    
    }
    freopen("CON", "w", stdout); // redirects stdout
    freopen("CON", "w", stderr);

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return;
    }

    if(TTF_Init() == 1)
    {
        printf("SDL_TTF could not initialize");
        return;
    }

    _window = NULL;
    _renderer = NULL;

    _window = SDL_CreateWindow("First window", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    return;
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


void GameWindow::Close()
{
    SDL_DestroyWindow(_window);
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
}


void GameWindow::Resizeable(bool resizeable)
{
    SDL_SetWindowResizable(_window, (SDL_bool)resizeable);
}


void GameWindow::GetWindowSize(int *w, int *h)
{
    SDL_GetWindowSize(_window, w, h);
}