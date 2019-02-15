#include "MainCharacter.h"
#include <SDL.h>


MainCharacter::MainCharacter()
{

}

void MainCharacter::init(SDL_Renderer *renderer, std::string file_path)
{
    _texture.Init(renderer);

    _texture.LoadTextureFromString(file_path);

}

void MainCharacter::handleEvent( SDL_Event& e )
{

}


void MainCharacter::render()
{
    // TODO: window.GetHeight() and window.GetWidth - character texture width/height
    _texture.Render(310, 230);
}