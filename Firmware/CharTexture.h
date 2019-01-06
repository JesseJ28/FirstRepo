#ifndef CHAR_TEXTURE_H
#define CHAR_TEXTURE_H

#include <SDL.h>
#include <string>



class CharTexture
{
    public:
    
        void Init(SDL_Renderer *renderer);
        bool LoadTextureFromString(std::string file_path);

        void Render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip );

        int getWidth();
        int getHeight();

    private:

        SDL_Texture *_texture;
        SDL_Renderer *_renderer;

        int _width;
        int _height;

};




#endif