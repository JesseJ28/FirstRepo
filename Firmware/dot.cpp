#include "dot.h"
#include <SDL.h>


Dot::Dot()
{
    //Initialize the offsets
    _pos_x = 0;
    _pos_y = 0;

    //Initialize the velocity
    _vel_x = 0;
    _vel_y = 0;
}

void Dot::init(SDL_Renderer *renderer, std::string file_path)
{
    _texture.Init(renderer);

    _texture.LoadTextureFromString(file_path);

}

void Dot::handleEvent( SDL_Event& e )
{
    //If a key was pressed
    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: _vel_y -= DOT_VEL; break;
            case SDLK_DOWN: _vel_y += DOT_VEL; break;
            case SDLK_LEFT: _vel_x -= DOT_VEL; break;
            case SDLK_RIGHT: _vel_x += DOT_VEL; break;
        }
    }
        //If a key was released
    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        //Adjust the velocity
        switch( e.key.keysym.sym )
        {
            case SDLK_UP: _vel_y += DOT_VEL; break;
            case SDLK_DOWN: _vel_y -= DOT_VEL; break;
            case SDLK_LEFT: _vel_x += DOT_VEL; break;
            case SDLK_RIGHT: _vel_x -= DOT_VEL; break;
        }
    }
}


void Dot::move()
{
    //Move the dot left or right
    _pos_x += _vel_x;

    //If the dot went too far to the left or right
    if( ( _pos_x < 0 ) || ( _pos_x + DOT_WIDTH > SCREEN_WIDTH ) )
    {
        //Move back
        _pos_x -= _vel_x;
    }
        //Move the dot up or down
    _pos_y += _vel_y;

    //If the dot went too far up or down
    if( ( _pos_y < 0 ) || ( _pos_y + DOT_HEIGHT > SCREEN_HEIGHT ) )
    {
        //Move back
        _pos_y -= _vel_y;
    }
}

void Dot::render()
{
    _texture.Render(_pos_x, _pos_y, NULL, 0.0, NULL, SDL_FLIP_NONE);
}