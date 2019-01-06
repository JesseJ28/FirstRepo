#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <stdio.h>
#include <SDL.h>




class GameWindow
{
    public:

    bool Init();
    void Update();
    void Clear();
    SDL_Renderer *GetRenderer();
    void Close();


    private:
    SDL_Window *_window;
    SDL_Surface *_surface;
    SDL_Renderer *_renderer;

};

#endif