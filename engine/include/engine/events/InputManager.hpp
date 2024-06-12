#pragma once
#include <unordered_map>

namespace Engine::Events {

enum class KeyCode {
    W, A, S, D, Space, Escape, Enter
};

class InputManager {
public:
    static void SetKeyPressed(KeyCode key, bool pressed);
    static bool IsKeyPressed(KeyCode key);

    static void SetMousePosition(float x, float y);
    static void GetMousePosition(float& outX, float& outY);

private:
    static std::unordered_map<KeyCode, bool> s_keyState;
    static float s_mouseX;
    static float s_mouseY;
};

}
