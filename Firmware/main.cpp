#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "dot.h"
#include "GameWindow.h"


int main(int argc, char* args[])
{
    // Initialize window
    GameWindow window;
    window.Init();

    // Generic SDL event
    SDL_Event event;

    // Initialize quit flag
    bool quit = false;

    // Initialize Moving Dot
    Dot dot;
    dot.init(window.GetRenderer(), "dot.bmp");

    // Game loop
    while (!quit)
    {
        // Process events until event queue is empty
        while (SDL_PollEvent(&event) != 0)
        {
            // Quit Event
            if (event.type == SDL_QUIT)
                quit = true;

            // Key Pressed Event
            if (event.type == SDL_KEYDOWN)
            {

            }

            dot.handleEvent(event);
        }
        
        dot.move();
                    
        window.Clear();
        // TODO: render objects
        dot.render();
        window.Update();
    }


    //Destroy window
    window.Close();

    return 0;
}