#include "engine/core/Logger.hpp"

namespace Engine::Core {

void Logger::Log(LogLevel level, const std::string& message) {
    const char* prefix = "[INFO]";
    switch (level) {
        case LogLevel::Warning: prefix = "[WARN]"; break;
        case LogLevel::Error:   prefix = "[ERROR]"; break;
        case LogLevel::Debug:   prefix = "[DEBUG]"; break;
        default: break;
    }
    std::cout << prefix << " " << message << std::endl;
}

}
