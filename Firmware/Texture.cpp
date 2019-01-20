
#include <SDL.h>
#include <SDL_Image.h>
#include <SDL_ttf.h>
#include <string>
#include "Texture.h"



void Texture::Init(SDL_Renderer *renderer)
{
    _renderer = renderer;
	_texture = NULL;
    _width = 0;
    _height = 0;
}


bool Texture::IsInitialized()
{
	return !(_texture == NULL);
}


bool Texture::LoadTextureFromString(std::string file_path)
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


bool Texture::LoadTextFromString( TTF_Font *font, std::string textureText, SDL_Color textColor )
{
    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid( font, textureText.c_str(), textColor );
    if( textSurface == NULL )
    {
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        _texture = SDL_CreateTextureFromSurface( _renderer, textSurface );
        if( _texture == NULL )
        {
            printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
        }
        else
        {
            //Get image dimensions
            _width = textSurface->w;
            _height = textSurface->h;
        }

        //Get rid of old surface
        SDL_FreeSurface( textSurface );
    }
    
    //Return success
    return _texture != NULL;
}

void Texture::Render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
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

int Texture::getWidth()
{
    return _width;
}


int Texture::getHeight()
{
    return _height;
}