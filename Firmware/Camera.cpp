#include "Camera.h"


Camera::Camera(SDL_Rect camera)
{
    _camera_rect = camera;
}

void Camera::SetCameraRect(SDL_Rect camera)
{
    _camera_rect = camera;
}


SDL_Rect Camera::GetCameraRect()
{
    return _camera_rect;
}


void Camera::handleEvent(SDL_Event &event)
{
    if (event.type == SDL_KEYDOWN)
    {  
        switch( event.key.keysym.sym )
        {
            case SDLK_UP: _camera_rect.y = 0; break;
            case SDLK_DOWN: _camera_rect.y = 80; break;
            case SDLK_LEFT: _camera_rect.x = 0; break;
            case SDLK_RIGHT: _camera_rect.x = 80; break;
        }
    }
}