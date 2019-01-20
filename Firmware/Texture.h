#ifndef CHAR_TEXTURE_H
#define CHAR_TEXTURE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>



class Texture
{
    public:
    
        void Init(SDL_Renderer *renderer);
        bool IsInitialized();
        bool LoadTextureFromString(std::string file_path);
        bool LoadTextFromString(TTF_Font *font, std::string textureText, SDL_Color textColor);
        void Render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

        int getWidth();
        int getHeight();

    private:

        SDL_Texture *_texture;
        SDL_Renderer *_renderer;

        int _width;
        int _height;

};




#endif