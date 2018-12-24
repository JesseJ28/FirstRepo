#include <stdio.h>
#include <SDL.h>




class GameWindow
{
    public:
    bool Init();
    void Update();


    private:
    SDL_Window *_window;


}