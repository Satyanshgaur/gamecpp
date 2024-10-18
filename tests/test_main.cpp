#include "engine/core/ArenaAllocator.hpp"
#include "engine/ecs/ECSManager.hpp"
#include <iostream>
#include <cassert>

void TestArenaAllocator() {
    Engine::Core::ArenaAllocator arena(1024);
    int* val = static_cast<int*>(arena.Allocate(sizeof(int)));
    *val = 42;
    assert(*val == 42);
    std::cout << "[Test] ArenaAllocator passed.\n";
}

void TestECS() {
    Engine::ECS::ECSManager ecs;
    auto entity = ecs.CreateEntity();
    ecs.AddComponent(entity, Engine::ECS::TransformComponent{10.0f, 20.0f});
    auto* transform = ecs.GetComponent<Engine::ECS::TransformComponent>(entity);
    assert(transform != nullptr);
    assert(transform->x == 10.0f);
    std::cout << "[Test] ECSManager passed.\n";
}

int main() {
    std::cout << "--- Running Engine Suite Unit Tests ---\n";
    TestArenaAllocator();
    TestECS();
    std::cout << "All engine unit tests passed successfully!\n";
    return 0;
}
