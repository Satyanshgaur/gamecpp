#include "engine/core/Window.hpp"
#include "engine/core/Logger.hpp"

namespace Engine::Core {

Window::Window(const WindowConfig& config) : m_config(config) {
    Logger::Info("Initializing Window: " + m_config.title + " (" + std::to_string(m_config.width) + "x" + std::to_string(m_config.height) + ")");
}

Window::~Window() {
    Logger::Info("Shutting down Window.");
}

void Window::PollEvents() {
    m_frameCount++;
}

void Window::SwapBuffers() {
}

}
