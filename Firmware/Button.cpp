
#include "Button.h"
#include <SDL.h>
#include <string>


void Button::Init(SDL_Renderer *renderer, int x, int y, int w, int h, void (*DoSomethingFunction)())
{
    _renderer = renderer;
    text.Init(renderer);
    _size.x = x;
    _size.y = y;
    _size.w = w;
    _size.h = h;
    DoSomething = DoSomethingFunction;
}


void Button::handleEvent(SDL_Event &event)
{
    // If button is released
    if(event.type == SDL_MOUSEBUTTONUP)
    {
        //Get mouse position
        int x, y;
        SDL_GetMouseState( &x, &y );
    
        //Check if mouse is in button
        bool inside = true;

        //Mouse is left of the button
        if( x < _size.x )
        {
            inside = false;
        }
        //Mouse is right of the button
        else if( x > (_size.w + _size.x) )
        {
            inside = false;
        }
        //Mouse above the button
        else if( y < _size.y )
        {
            inside = false;
        }
        //Mouse below the button
        else if( y > (_size.y + _size.h) )
        {
            inside = false;
        }

        if(inside)
        {
            DoSomething();
        }
    }
}


void Button::render()
{
    // Just make it black for now
    SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderDrawRect(_renderer, &_size);
    SDL_RenderFillRect(_renderer, &_size);

    if (text.IsInitialized())
        text.Render(_size.x, _size.y);
}


int Button::GetWidth()
{
    return _size.w;
}


int Button::GetHeight()
{
    return _size.h;
}


int Button::GetX()
{
    return _size.x;
}


int Button::GetY()
{
    return _size.y;
}