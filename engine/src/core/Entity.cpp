#include "engine/core/Entity.hpp"
#include "engine/core/Logger.hpp"

namespace Engine::Core {

Entity::Entity(const std::string& name) : m_name(name) {
    Logger::Info("Created Entity: " + m_name);
}

Entity::~Entity() {
    Logger::Info("Destroyed Entity: " + m_name);
}

void Entity::AddChild(std::shared_ptr<Entity> child) {
    child->m_parent = shared_from_this();
    m_children.push_back(child);
    Logger::Info("Attached child '" + child->GetName() + "' to parent '" + m_name + "'");
}

}
