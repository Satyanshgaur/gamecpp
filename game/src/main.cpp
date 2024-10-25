#include "engine/core/Window.hpp"
#include "engine/core/Logger.hpp"
#include "engine/graphics/Renderer2D.hpp"
#include "engine/graphics/Camera2D.hpp"
#include "engine/events/InputManager.hpp"
#include "engine/ecs/ECSManager.hpp"
#include "engine/physics/Physics2D.hpp"
#include "engine/profiler/Profiler.hpp"
#include "engine/ai/AStar.hpp"
#include "engine/network/StateSync.hpp"
#include <iostream>

int main() {
    using namespace Engine;
    
    Core::Logger::Info("=================================================");
    Core::Logger::Info("   C++ Systems Engine v1.0 (26-Week Journey)    ");
    Core::Logger::Info("=================================================");

    Core::Window window({"Complete C++ Real-Time Engine v1.0", 1280, 720, true});
    Graphics::Renderer2D::Init();
    Graphics::Camera2D camera(1280.0f, 720.0f);

    ECS::ECSManager ecs;
    auto player = ecs.CreateEntity();
    ecs.AddComponent(player, ECS::TransformComponent{640.0f, 360.0f, 1.0f, 1.0f});
    ecs.AddComponent(player, ECS::VelocityComponent{0.0f, 0.0f});

    Physics::PhysicsWorld physicsWorld(-9.81f);

    Core::Logger::Info("Engine subsystems initialized successfully. Entering main loop...");

    int frameCount = 0;
    while (!window.ShouldClose() && frameCount < 180) {
        ENGINE_PROFILE_SCOPE("MainFrameLoop");

        window.PollEvents();
        
        if (Events::InputManager::IsKeyPressed(Events::KeyCode::W)) {
            auto* vel = ecs.GetComponent<ECS::VelocityComponent>(player);
            if (vel) vel->vy = 5.0f;
        }

        physicsWorld.Step(0.016f);

        Graphics::Renderer2D::BeginScene(camera);
        auto* transform = ecs.GetComponent<ECS::TransformComponent>(player);
        if (transform) {
            Graphics::Renderer2D::DrawQuad(transform->x, transform->y, 32.0f, 32.0f);
        }
        Graphics::Renderer2D::EndScene();

        window.SwapBuffers();
        frameCount++;
    }

    Graphics::Renderer2D::Shutdown();
    Core::Logger::Info("Engine shutdown complete. Thank you for following the 26-week journey!");
    return 0;
}
