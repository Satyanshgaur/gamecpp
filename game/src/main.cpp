#include "engine/core/Window.hpp"
#include "engine/core/Logger.hpp"

int main() {
    Engine::Core::Logger::Info("Starting GameApp...");
    Engine::Core::Window window({"C++ Engine Journey - v0.1", 1280, 720, true});

    int frames = 0;
    while (!window.ShouldClose() && frames < 100) {
        window.PollEvents();
        window.SwapBuffers();
        frames++;
    }

    Engine::Core::Logger::Info("GameApp exited cleanly after " + std::to_string(frames) + " frames.");
    return 0;
}
