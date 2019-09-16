#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <stdio.h>
#include <SDL.h>




class GameWindow
{
public:
    GameWindow();

    void Update();
    void Clear();
    SDL_Renderer* GetRenderer();
    void Close();

    void Resizeable(bool resizeable);


private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;

};

#endif