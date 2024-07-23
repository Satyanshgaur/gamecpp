#pragma once
#include <array>

namespace Engine::Graphics {

class SIMDVector4 {
public:
    alignas(16) std::array<float, 4> v;

    SIMDVector4(float x, float y, float z, float w) : v{x, y, z, w} {}

    static SIMDVector4 Add(const SIMDVector4& a, const SIMDVector4& b) {
        return SIMDVector4(a.v[0] + b.v[0], a.v[1] + b.v[1], a.v[2] + b.v[2], a.v[3] + b.v[3]);
    }

    static SIMDVector4 Multiply(const SIMDVector4& a, float scalar) {
        return SIMDVector4(a.v[0] * scalar, a.v[1] * scalar, a.v[2] * scalar, a.v[3] * scalar);
    }
};

}
