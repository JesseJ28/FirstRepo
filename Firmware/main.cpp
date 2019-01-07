#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
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
    window.Init();

    // Generic SDL event
    SDL_Event event;

    // Initialize quit flag
    bool quit = false;

    // Initialize Moving Dot
    Dot dot;
    dot.init(window.GetRenderer(), "bulbasaur.png");

    Button button;
    button.Init(window.GetRenderer(), 100, 100, 100, 100, Button_DoStuff);

    Button skills;
    skills.Init(window.GetRenderer(), 200, 380, 100, 100, Button_DoStuff);

    TTF_Font *font = TTF_OpenFont("Fonts/OpenSans-Italic.tff", 20);
    SDL_Color color = {0,0,0};

    Texture text;
    text.Init(window.GetRenderer());
    text.LoadTextFromString(font, "Fonts/OpenSans-Italic.tff", color);

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
            skills.handleEvent(event);
        }

        // Change positions
        dot.move();
                    
        // Clear the window
        window.Clear();
        
        // Render Objects
        button.render();
        skills.render();
        dot.render();
        //text.Render(0,0);

        // Update Window
        window.Update();
    }


    //Destroy window
    window.Close();

    return 0;
}