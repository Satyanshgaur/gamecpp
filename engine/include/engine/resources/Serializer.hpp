#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace Engine::Resources {

class BinarySerializer {
public:
    template <typename T>
    void Write(const T& data) {
        const char* bytes = reinterpret_cast<const char*>(&data);
        m_stream.write(bytes, sizeof(T));
    }

    std::string GetBytes() const { return m_stream.str(); }

private:
    std::stringstream m_stream;
};

}
