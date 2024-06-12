#include "engine/events/InputManager.hpp"

namespace Engine::Events {

std::unordered_map<KeyCode, bool> InputManager::s_keyState;
float InputManager::s_mouseX = 0.0f;
float InputManager::s_mouseY = 0.0f;

void InputManager::SetKeyPressed(KeyCode key, bool pressed) {
    s_keyState[key] = pressed;
}

bool InputManager::IsKeyPressed(KeyCode key) {
    auto it = s_keyState.find(key);
    return (it != s_keyState.end()) ? it->second : false;
}

void InputManager::SetMousePosition(float x, float y) {
    s_mouseX = x;
    s_mouseY = y;
}

void InputManager::GetMousePosition(float& outX, float& outY) {
    outX = s_mouseX;
    outY = s_mouseY;
}

}
