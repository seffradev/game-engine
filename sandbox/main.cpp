#include <stop_token>

import window;
import log;

int main(int, char **) {
    auto logger = Logger{Logger::Options{Logger::Level::Trace}};
    logger.info("Hello, world!");

    auto window = Window::create({640, 480}, "Test");
    if (!window) {
        logger.fatal("Could not create window");
        return 1;
    }

    logger.trace("Successfully created window");

    std::stop_source stop_source;

    while (!stop_source.stop_requested()) {
        window->clear();
        window->swapBuffers();
        window->pollEvents();
    }

    return 0;
}
