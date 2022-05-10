#pragma once

#include <SDL.h>

namespace Engine {

class Window {
   public:
    enum Status {
        Success,
        Close,
        InitError,
        CreateError,
        UpdateError,
        DrawError,
    };

   private:
    const char* title;
    int width, height;

    SDL_Window* _window;
    SDL_Surface* _surface;

   public:
    Window(const char* title, int width, int height);
    ~Window();

    Window::Status init();
    Window::Status render(SDL_Surface* surface);

    SDL_Window* window();
    SDL_Surface* surface();
    const char* error();
};

}  // namespace Engine
