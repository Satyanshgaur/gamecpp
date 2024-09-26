#pragma once
#include <vector>
#include <memory>

namespace Engine::AI {

enum class NodeState { Success, Failure, Running };

class BTNode {
public:
    virtual ~BTNode() = default;
    virtual NodeState Tick() = 0;
};

class SequenceNode : public BTNode {
public:
    void AddChild(std::shared_ptr<BTNode> child) { m_children.push_back(child); }

    NodeState Tick() override {
        for (auto& child : m_children) {
            if (child->Tick() == NodeState::Failure) return NodeState::Failure;
        }
        return NodeState::Success;
    }

private:
    std::vector<std::shared_ptr<BTNode>> m_children;
};

}
