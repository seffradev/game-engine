#include <iostream>

#include "graphics/sprite/Sprite.hpp"
#include "graphics/window/Window.hpp"
#include "math/Vector2D.hpp"

using namespace Engine;

int main(int argc, char* argv[]) {
    const char* path = "assets/duck.bmp";
    bool running     = true;

    Window* window = new Window("Test", 640, 480);
    Sprite* sprite = new Sprite();

    switch (window->init()) {
        case Window::Status::InitError:
            std::cout << window->error() << std::endl;
            return 1;
        case Window::Status::CreateError:
            std::cout << window->error() << std::endl;
            return 2;
        default:
            break;
    }

    switch (sprite->load(path)) {
        case Sprite::Status::LoadError:
            std::cout << "Couldn't load sprite at (" << path << ")" << std::endl;
            break;
        default:
            break;
    }

    while (running) {
        switch (window->render(sprite->surface())) {
            case Window::Status::DrawError:
                std::cout << "Something went wrong with drawing!" << std::endl;
                break;
            case Window::Status::UpdateError:
                std::cout
                    << "Something went wrong when updating the window!" << std::endl;
                break;
            case Window::Status::Close:
                running = false;
                break;
            default:
                break;
        }
    }

    return 0;
}
