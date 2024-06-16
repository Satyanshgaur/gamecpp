#pragma once
#include <cstdint>
#include <unordered_map>
#include <vector>
#include <memory>
#include <typeindex>

namespace Engine::ECS {

using EntityID = uint32_t;

struct TransformComponent {
    float x = 0.0f, y = 0.0f;
    float scaleX = 1.0f, scaleY = 1.0f;
};

struct VelocityComponent {
    float vx = 0.0f, vy = 0.0f;
};

class ECSManager {
public:
    EntityID CreateEntity() {
        return m_nextEntityID++;
    }

    template <typename T>
    void AddComponent(EntityID entity, T component) {
        m_components[std::type_index(typeid(T))][entity] = std::make_shared<T>(component);
    }

    template <typename T>
    T* GetComponent(EntityID entity) {
        auto typeIdx = std::type_index(typeid(T));
        if (m_components.find(typeIdx) != m_components.end()) {
            auto& map = m_components[typeIdx];
            if (map.find(entity) != map.end()) {
                return static_cast<T*>(map[entity].get());
            }
        }
        return nullptr;
    }

private:
    EntityID m_nextEntityID = 1;
    std::unordered_map<std::type_index, std::unordered_map<EntityID, std::shared_ptr<void>>> m_components;
};

}
