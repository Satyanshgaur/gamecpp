#pragma once
#include <string>
#include <vector>
#include <memory>

namespace Engine::Core {

class Entity : public std::enable_shared_from_this<Entity> {
public:
    Entity(const std::string& name);
    ~Entity();

    void AddChild(std::shared_ptr<Entity> child);
    const std::string& GetName() const { return m_name; }
    const std::vector<std::shared_ptr<Entity>>& GetChildren() const { return m_children; }
    std::weak_ptr<Entity> GetParent() const { return m_parent; }

private:
    std::string m_name;
    std::weak_ptr<Entity> m_parent;
    std::vector<std::shared_ptr<Entity>> m_children;
};

}
