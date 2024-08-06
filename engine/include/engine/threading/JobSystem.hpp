#pragma once
#include "engine/threading/ThreadPool.hpp"
#include <vector>

namespace Engine::Threading {

class JobSystem {
public:
    JobSystem() : m_pool(std::thread::hardware_concurrency()) {}

    void ParallelFor(size_t count, const std::function<void(size_t index)>& body) {
        std::vector<std::future<void>> futures;
        for (size_t i = 0; i < count; ++i) {
            futures.push_back(m_pool.Enqueue(body, i));
        }
        for (auto& f : futures) {
            f.wait();
        }
    }

private:
    ThreadPool m_pool;
};

}
