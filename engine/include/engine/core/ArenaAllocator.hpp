#pragma once
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <stdexcept>

namespace Engine::Core {

class ArenaAllocator {
public:
    ArenaAllocator(size_t capacityBytes) : m_capacity(capacityBytes) {
        m_buffer = static_cast<uint8_t*>(std::malloc(capacityBytes));
        m_offset = 0;
    }

    ~ArenaAllocator() {
        std::free(m_buffer);
    }

    void* Allocate(size_t size, size_t alignment = 8) {
        size_t currentPtr = reinterpret_cast<size_t>(m_buffer + m_offset);
        size_t alignedPtr = (currentPtr + (alignment - 1)) & ~(alignment - 1);
        size_t newOffset = (alignedPtr - reinterpret_cast<size_t>(m_buffer)) + size;

        if (newOffset > m_capacity) {
            throw std::bad_alloc();
        }

        m_offset = newOffset;
        return reinterpret_cast<void*>(alignedPtr);
    }

    void Reset() {
        m_offset = 0;
    }

    size_t GetUsedMemory() const { return m_offset; }

private:
    uint8_t* m_buffer;
    size_t m_capacity;
    size_t m_offset;
};

}
