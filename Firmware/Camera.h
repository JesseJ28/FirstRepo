#ifndef CAMERA_H
#define CAMERA_H

#include <SDL.h>

class Camera
{
    public:

    Camera(SDL_Rect camera);

    void SetCameraRect(SDL_Rect camera);
    SDL_Rect GetCameraRect();
    void handleEvent(SDL_Event &event);

    private:

    SDL_Rect _camera_rect;
    
};

#endif // CAMERA_H