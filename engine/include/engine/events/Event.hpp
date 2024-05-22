#pragma once
#include <string>

namespace Engine::Events {

class Event {
public:
    virtual ~Event() = default;
    virtual std::string GetName() const = 0;
};

struct WindowResizeEvent : public Event {
    int width, height;
    WindowResizeEvent(int w, int h) : width(w), height(h) {}
    std::string GetName() const override { return "WindowResizeEvent"; }
};

struct KeyPressEvent : public Event {
    int keyCode;
    KeyPressEvent(int key) : keyCode(key) {}
    std::string GetName() const override { return "KeyPressEvent"; }
};

}
