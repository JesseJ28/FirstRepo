#ifndef MAP_H
#define MAP_H

#include <SDL.h>
#include <string>

#include "Texture.h"

class Map
{
    public:
        Map(SDL_Renderer *renderer, std::string tile_sheet_file_path, int tile_width, int tile_height);
        ~Map();

        void Render(SDL_Rect camera);

    private:
        Texture _tile_sheet;
        int _tile_width;
        int _tile_height;
        int _map_layout[2][2];
};

#endif // MAP_H