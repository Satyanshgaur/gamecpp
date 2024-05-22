#pragma once
#include "engine/events/Event.hpp"
#include <functional>
#include <vector>
#include <typeindex>
#include <unordered_map>

namespace Engine::Events {

class EventDispatcher {
public:
    template <typename T>
    using EventCallback = std::function<void(const T&)>;

    template <typename T>
    void Subscribe(EventCallback<T> callback) {
        auto typeIdx = std::type_index(typeid(T));
        m_listeners[typeIdx].push_back([callback](const Event& event) {
            callback(static_cast<const T&>(event));
        });
    }

    template <typename T>
    void Dispatch(const T& event) {
        auto typeIdx = std::type_index(typeid(T));
        if (m_listeners.find(typeIdx) != m_listeners.end()) {
            for (auto& listener : m_listeners[typeIdx]) {
                listener(event);
            }
        }
    }

private:
    std::unordered_map<std::type_index, std::vector<std::function<void(const Event&)>>> m_listeners;
};

}
