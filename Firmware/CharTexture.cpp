
#include <SDL.h>
#include <SDL_Image.h>
#include <string>
#include "CharTexture.h"



void CharTexture::Init(SDL_Renderer *renderer)
{
    _renderer = renderer;
    _width = 0;
    _height = 0;
}


bool CharTexture::LoadTextureFromString(std::string file_path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( file_path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", file_path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( _renderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", file_path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			_width = loadedSurface->w;
			_height = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	_texture = newTexture;
	return _texture != NULL;
}

void CharTexture::Render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
    	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, _width, _height };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( _renderer, _texture, clip, &renderQuad, angle, center, flip );
}

int CharTexture::getWidth()
{
    return _width;
}


int CharTexture::getHeight()
{
    return _height;
}