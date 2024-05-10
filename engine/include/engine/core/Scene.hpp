#pragma once
#include "engine/core/Entity.hpp"
#include <memory>
#include <string>

namespace Engine::Core {

class Scene {
public:
    Scene(const std::string& sceneName);
    ~Scene();

    std::shared_ptr<Entity> CreateEntity(const std::string& name);
    std::shared_ptr<Entity> GetRoot() const { return m_root; }

private:
    std::string m_name;
    std::shared_ptr<Entity> m_root;
};

}
