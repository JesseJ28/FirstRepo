#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Texture.h"
#include "dot.h"
#include "GameWindow.h"
#include "Button.h"
#include "ButtonActions.h"


int main(int argc, char* args[])
{
    // Initialize window
    GameWindow window;
    // window.SetWindowResizeable(true);

    // Generic SDL event
    SDL_Event event;

    // Initialize quit flag
    bool quit = false;

    // TODO: Fix this so that don't have to use absolute path
    // TTF_Font *font = TTF_OpenFont("C:/Repos/FirstRepo/Firmware/Fonts/OpenSans-Regular.ttf", 28);
    // if(font == NULL)
    // {
    //     printf("Font failed");
    // }

    // White
    SDL_Color color = {255,255,255};

    // Initialize Moving Dot
    Dot dot;
    dot.init(window.GetRenderer(), "bulbasaur.png");

    Button button;
    button.Init(window.GetRenderer(), 200, 380, 200, 100, Button_DoStuff);
    // button.text.LoadTextFromString(font, "button pressed", color);

    // Texture text;
    // text.Init(window.GetRenderer());
    // text.LoadTextFromString(font, "hello", color);

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
            button.handleEvent(event);
        }

        // Change positions
        dot.move();
                    
        // Clear the window
        window.Clear();
        
        // Render Objects
        button.render();
        dot.render();
        //text.Render(200,400);

        // Update Window
        window.Update();
    }


    //Destroy window
    window.Close();

    return 0;
}