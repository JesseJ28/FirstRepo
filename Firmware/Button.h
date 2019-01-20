#ifndef BUTTON_H
#define BUTTON_H

#include "Texture.h"
#include <string>

// TODO: not doing anything with name

class Button
{
    public:
        void Init(SDL_Renderer *renderer, int x, int y, int w, int h, void (*DoSomethingFunction)());

        void handleEvent(SDL_Event &event);
        void render();

        int GetWidth();
        int GetHeight();
        int GetX();
        int GetY();

        Texture text;

    private:

        SDL_Renderer *_renderer;
        SDL_Rect _size;

        void (*DoSomething)();



};



#endif