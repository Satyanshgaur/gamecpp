#pragma once
#include "engine/core/Logger.hpp"
#include <string>
#include <unordered_map>
#include <memory>

namespace Engine::Resources {

template <typename T>
class ResourceManager {
public:
    std::shared_ptr<T> Load(const std::string& filepath) {
        auto it = m_cache.find(filepath);
        if (it != m_cache.end()) {
            Core::Logger::Info("Cache hit for resource: " + filepath);
            return it->second;
        }

        Core::Logger::Info("Loading resource into cache: " + filepath);
        auto resource = std::make_shared<T>(filepath);
        m_cache[filepath] = resource;
        return resource;
    }

    void UnloadUnused() {
        for (auto it = m_cache.begin(); it != m_cache.end(); ) {
            if (it->second.use_count() == 1) {
                Core::Logger::Info("Purging unused cached resource: " + it->first);
                it = m_cache.erase(it);
            } else {
                ++it;
            }
        }
    }

    size_t GetCount() const { return m_cache.size(); }

private:
    std::unordered_map<std::string, std::shared_ptr<T>> m_cache;
};

}
