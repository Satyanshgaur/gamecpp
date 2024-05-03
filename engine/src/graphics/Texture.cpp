#include "engine/graphics/Texture.hpp"
#include "engine/core/Logger.hpp"

namespace Engine::Graphics {

Texture::Texture(const std::string& filepath) : m_filepath(filepath), m_width(512), m_height(512), m_textureID(1) {
    Core::Logger::Info("Loaded Texture RAII wrapper: " + filepath);
}

Texture::~Texture() {
    Core::Logger::Info("Destroyed Texture RAII resource: " + m_filepath);
}

}
