#pragma once
#include <functional>

namespace Engine::Core {

template <typename T, typename Deleter>
class ScopedResource {
public:
    ScopedResource(T resource, Deleter deleter)
        : m_resource(resource), m_deleter(deleter) {}
    
    ~ScopedResource() {
        if (m_valid) {
            m_deleter(m_resource);
        }
    }

    ScopedResource(const ScopedResource&) = delete;
    ScopedResource& operator=(const ScopedResource&) = delete;

    ScopedResource(ScopedResource&& other) noexcept
        : m_resource(other.m_resource), m_deleter(std::move(other.m_deleter)), m_valid(other.m_valid) {
        other.m_valid = false;
    }

    T Get() const { return m_resource; }

private:
    T m_resource;
    Deleter m_deleter;
    bool m_valid = true;
};

}
