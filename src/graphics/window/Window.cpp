#include "Window.hpp"

namespace Engine {

Window::Window(const char* title, int width, int height) : title(title), width(width), height(height) {
}

Window::~Window() {
    if (_window != NULL)
        SDL_DestroyWindow(_window);

    SDL_Quit();
}

Window::Status Window::init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return Window::Status::InitError;

    _window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if (_window == NULL)
        return Window::Status::CreateError;

    return Window::Status::Success;
}

Window::Status Window::render(SDL_Surface* surf) {
    SDL_Event e;
    auto* _surface = surface();

    // Fill the surface white
    if (SDL_FillRect(_surface, NULL, SDL_MapRGB(_surface->format, 0xFF, 0xFF, 0xFF)))
        return Window::Status::DrawError;

    SDL_BlitSurface(surf, NULL, _surface, NULL);

    // Update the surface
    if (SDL_UpdateWindowSurface(_window))
        return Window::Status::UpdateError;

    while (SDL_PollEvent(&e) != 0) {
        // User requests quit
        if (e.type == SDL_QUIT) {
            return Window::Status::Close;
        }
    }

    return Window::Status::Success;
}

SDL_Window* Window::window() {
    return _window;
}

SDL_Surface* Window::surface() {
    return SDL_GetWindowSurface(_window);
}

const char* Window::error() {
    return SDL_GetError();
}

}  // namespace Engine
