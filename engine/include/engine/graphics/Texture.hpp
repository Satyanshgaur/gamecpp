#pragma once
#include <string>

namespace Engine::Graphics {

class Texture {
public:
    Texture(const std::string& filepath);
    ~Texture();

    int GetWidth() const { return m_width; }
    int GetHeight() const { return m_height; }
    const std::string& GetPath() const { return m_filepath; }

private:
    std::string m_filepath;
    int m_width = 0;
    int m_height = 0;
    unsigned int m_textureID = 0;
};

}
