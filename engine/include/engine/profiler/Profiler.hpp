#pragma once
#include <chrono>
#include <string>
#include <iostream>

namespace Engine::Profiler {

class ProfileScope {
public:
    ProfileScope(const std::string& name) : m_name(name), m_start(std::chrono::high_resolution_clock::now()) {}
    ~ProfileScope() {
        auto end = std::chrono::high_resolution_clock::now();
        double ms = std::chrono::duration<double, std::milli>(end - m_start).count();
        std::cout << "[Profile] " << m_name << ": " << ms << " ms\n";
    }

private:
    std::string m_name;
    std::chrono::high_resolution_clock::time_point m_start;
};

#define ENGINE_PROFILE_SCOPE(name) Engine::Profiler::ProfileScope scope##__LINE__(name)

}
