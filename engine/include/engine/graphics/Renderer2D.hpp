#pragma once
#include "engine/graphics/Camera2D.hpp"
#include "engine/graphics/Texture.hpp"
#include <memory>

namespace Engine::Graphics {

struct QuadDrawCall {
    float x, y, width, height;
    float rotation;
    std::shared_ptr<Texture> texture;
};

class Renderer2D {
public:
    static void Init();
    static void Shutdown();

    static void BeginScene(const Camera2D& camera);
    static void EndScene();

    static void DrawQuad(float x, float y, float w, float h, std::shared_ptr<Texture> texture = nullptr, float rotation = 0.0f);
    static uint32_t GetDrawCallCount() { return s_drawCalls; }

private:
    static uint32_t s_drawCalls;
};

}
