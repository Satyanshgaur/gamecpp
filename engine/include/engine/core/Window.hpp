#pragma once
#include <string>

namespace Engine::Core {

struct WindowConfig {
    std::string title = "C++ Systems Engine";
    int width = 1280;
    int height = 720;
    bool vsync = true;
};

class Window {
public:
    Window(const WindowConfig& config = {});
    ~Window();

    void PollEvents();
    bool ShouldClose() const { return m_shouldClose; }
    void SwapBuffers();

    int GetWidth() const { return m_config.width; }
    int GetHeight() const { return m_config.height; }
    float GetFPS() const { return m_fps; }

private:
    WindowConfig m_config;
    bool m_shouldClose = false;
    float m_fps = 60.0f;
    uint64_t m_frameCount = 0;
};

}
