#include "engine/graphics/Renderer2D.hpp"
#include "engine/core/Logger.hpp"

namespace Engine::Graphics {

uint32_t Renderer2D::s_drawCalls = 0;

void Renderer2D::Init() {
    Core::Logger::Info("Initializing Renderer2D batch pipeline.");
}

void Renderer2D::Shutdown() {
    Core::Logger::Info("Shutting down Renderer2D.");
}

void Renderer2D::BeginScene(const Camera2D& camera) {
    s_drawCalls = 0;
}

void Renderer2D::EndScene() {
}

void Renderer2D::DrawQuad(float x, float y, float w, float h, std::shared_ptr<Texture> texture, float rotation) {
    s_drawCalls++;
}

}
