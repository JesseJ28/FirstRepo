#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Texture.h"
#include "dot.h"
#include "GameWindow.h"
#include "Button.h"
#include "ButtonActions.h"
#include "Map.h"
#include "Camera.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480


int main(int argc, char* args[])
{
    // Initialize window
    GameWindow window;
    window.Init(WINDOW_WIDTH, WINDOW_HEIGHT);

    // Generic SDL event
    SDL_Event event;

    // Initialize quit flag
    bool quit = false;

    // TODO: Fix this so that don't have to use absolute path
    TTF_Font *font = TTF_OpenFont("C:/Projects/Personal/FirstRepo/Firmware/Fonts/OpenSans-Regular.ttf", 28);
    if(font == NULL)
    {
        printf("Font failed");
    }

    // White
    SDL_Color color = {255,255,255};

    // Initialize Moving Dot
    Dot dot;
    dot.init(window.GetRenderer(), "bulbasaur.png");

    Button button;
    button.Init(window.GetRenderer(), 200, 380, 200, 100, Button_DoStuff);
    button.text.LoadTextFromString(font, "button pressed", color);

    Texture text;
    text.Init(window.GetRenderer());
    text.LoadTextFromString(font, "hello", color);

    Map map(window.GetRenderer(), "Map/tiles.png", 80, 80);

    SDL_Rect camera_rect;
    camera_rect.x = 0;
    camera_rect.y = 0;
    camera_rect.w = 640;
    camera_rect.h = 320;

    Camera camera(camera_rect);

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
            camera.handleEvent(event);
        }

        // Change positions
        dot.move();
                    
        // Clear the window
        window.Clear();
        
        // Render Objects
        button.render();
        dot.render();
        text.Render(200,400);
        map.Render(camera.GetCameraRect());

        // Update Window
        window.Update();
    }


    //Destroy window
    window.Close();

    return 0;
}