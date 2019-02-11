#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <stdio.h>
#include <SDL.h>




class GameWindow
{
    public:

    bool Init(int window_width, int window_height);
    void Update();
    void Clear();
    SDL_Renderer *GetRenderer();
    int getHeight();
    int getWidth();
    void Close();


    private:
    int _window_width;
    int _window_height;
    SDL_Window *_window;
    SDL_Surface *_surface;
    SDL_Renderer *_renderer;

};

#endif