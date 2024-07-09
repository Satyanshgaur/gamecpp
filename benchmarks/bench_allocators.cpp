#include "engine/core/ArenaAllocator.hpp"
#include <iostream>
#include <chrono>

int main() {
    constexpr int N = 100000;
    
    auto t0 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        int* p = new int(i);
        delete p;
    }
    auto t1 = std::chrono::high_resolution_clock::now();

    Engine::Core::ArenaAllocator arena(1024 * 1024);
    auto t2 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < N; ++i) {
        int* p = static_cast<int*>(arena.Allocate(sizeof(int)));
        *p = i;
    }
    arena.Reset();
    auto t3 = std::chrono::high_resolution_clock::now();

    double mallocTime = std::chrono::duration<double, std::milli>(t1 - t0).count();
    double arenaTime = std::chrono::duration<double, std::milli>(t3 - t2).count();

    std::cout << "[Benchmark] malloc/free: " << mallocTime << " ms | ArenaAllocator: " << arenaTime << " ms\n";
    return 0;
}
