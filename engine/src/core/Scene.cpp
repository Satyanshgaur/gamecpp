#include "engine/core/Scene.hpp"
#include "engine/core/Logger.hpp"

namespace Engine::Core {

Scene::Scene(const std::string& sceneName) : m_name(sceneName) {
    m_root = std::make_shared<Entity>("Root_" + sceneName);
    Logger::Info("Initialized Scene graph: " + m_name);
}

Scene::~Scene() {
    Logger::Info("Destroyed Scene graph: " + m_name);
}

std::shared_ptr<Entity> Scene::CreateEntity(const std::string& name) {
    auto ent = std::make_shared<Entity>(name);
    m_root->AddChild(ent);
    return ent;
}

}
