#include "Sprite.hpp"

namespace Engine {

Sprite::Sprite() {}

Sprite::~Sprite() {
    if (_surface != NULL)
        SDL_FreeSurface(_surface);
}

Sprite::Status Sprite::load(const char* path) {
    _surface = SDL_LoadBMP(path);

    if (_surface == NULL)
        return Sprite::Status::LoadError;
    return Sprite::Status::Success;
}

SDL_Surface* Sprite::surface() {
    return _surface;
}

}  // namespace Engine
