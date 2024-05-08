#pragma once
#include <string>

namespace Engine::Audio {

class SoundEffect {
public:
    SoundEffect(const std::string& filepath);
    ~SoundEffect();

    void Play();

private:
    std::string m_filepath;
    unsigned int m_audioBufferID = 0;
};

}
