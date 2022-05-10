#pragma once

#include <SDL.h>

namespace Engine {

class Sprite {
   public:
    enum Status {
        Success,
        LoadError,
    };

   private:
    SDL_Surface* _surface;

   public:
    Sprite();
    ~Sprite();

    Sprite::Status load(const char* path);

    SDL_Surface* surface();
};

}  // namespace Engine
