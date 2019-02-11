#include "Map.h"

#define TEST_MAP_WIDTH  9
#define TEST_MAP_HEIGHT 5


static int test_map[TEST_MAP_HEIGHT][TEST_MAP_WIDTH] = 
{
    {8, 0, 0, 4, 0, 1, 2, 3, 4},
    {0, 5, 4, 0, 0, 1, 2, 3, 4},
    {8, 0, 0, 4, 0, 1, 2, 3, 4},
    {0, 5, 4, 0, 0, 1, 2, 8, 4},
    {8, 8, 8, 8, 8, 8, 8, 8, 8}
};


Map::Map(SDL_Renderer *renderer, std::string tile_sheet_file_path, int tile_width, int tile_height)
{
    _tile_sheet.Init(renderer);

    _tile_width = tile_width;
    _tile_height = tile_height;

    _tile_sheet.LoadTextureFromString(tile_sheet_file_path);

    // _map_layout = test_map;

}

Map::~Map()
{

}

void Map::Render(SDL_Rect camera)
{
    for (int i = camera.x / _tile_width; i < (camera.x + camera.w) / _tile_width ; i++)
    {
        for (int j = camera.y / _tile_height; j < (camera.y + camera.h) / _tile_height; j++)
        {
            int tile_type = test_map[j][i];

            SDL_Rect tile;
            tile.w = _tile_width;
            tile.h = _tile_height;
            // TODO: Add some error checking here
            tile.x = (tile_type * _tile_width) % _tile_sheet.getWidth();
            tile.y = (tile_type * _tile_height) / _tile_sheet.getWidth() * _tile_height;

            _tile_sheet.Render(_tile_width * (i - (camera.x / _tile_width)), _tile_height * (j - (camera.y / _tile_height)), &tile);
        }
    }
}