#include "engine/audio/Audio.hpp"
#include "engine/core/Logger.hpp"

namespace Engine::Audio {

SoundEffect::SoundEffect(const std::string& filepath) : m_filepath(filepath), m_audioBufferID(42) {
    Core::Logger::Info("Loaded Audio RAII: " + filepath);
}

SoundEffect::~SoundEffect() {
    Core::Logger::Info("Released Audio RAII buffer: " + m_filepath);
}

void SoundEffect::Play() {
    Core::Logger::Info("Playing SoundEffect: " + m_filepath);
}

}
