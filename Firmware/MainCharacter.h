#ifndef DOT_H
#define DOT_H

#include <SDL.h>
#include <string>
#include "Texture.h"


class MainCharacter
{
    public:
        //Initializes the variables
        MainCharacter();

        void init(SDL_Renderer *renderer, std::string file_path);

        //Takes key presses and adjusts the dot's velocity
        void handleEvent( SDL_Event& e );

        //Shows the dot on the screen
        void render();

    private:

        Texture _texture;
};

#endif