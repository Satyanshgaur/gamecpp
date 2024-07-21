#pragma once
#include <vector>

namespace Engine::ECS {

class ParticleSystemSoA {
public:
    void Resize(size_t count) {
        posX.resize(count, 0.0f);
        posY.resize(count, 0.0f);
        velX.resize(count, 1.0f);
        velY.resize(count, 1.0f);
    }

    void Update(float dt) {
        size_t n = posX.size();
        for (size_t i = 0; i < n; ++i) {
            posX[i] += velX[i] * dt;
            posY[i] += velY[i] * dt;
        }
    }

    std::vector<float> posX;
    std::vector<float> posY;
    std::vector<float> velX;
    std::vector<float> velY;
};

}
