#ifndef DOT_H
#define DOT_H

#include <SDL.h>
#include <string>
#include "CharTexture.h"


class Dot
{
    public:
        //The dimensions of the dot
        static const int DOT_WIDTH = 20;
        static const int DOT_HEIGHT = 20;
        static const int SCREEN_WIDTH = 640;
        static const int SCREEN_HEIGHT = 480; 

        //Maximum axis velocity of the dot
        static const int DOT_VEL = 10;

        //Initializes the variables
        Dot();

        void init(SDL_Renderer *renderer, std::string file_path);

        //Takes key presses and adjusts the dot's velocity
        void handleEvent( SDL_Event& e );

        //Moves the dot
        void move();

        //Shows the dot on the screen
        void render();

    private:
        //The X and Y offsets of the dot
        int _pos_x, _pos_y;

        //The velocity of the dot
        int _vel_x, _vel_y;

        CharTexture _texture;
};

#endif