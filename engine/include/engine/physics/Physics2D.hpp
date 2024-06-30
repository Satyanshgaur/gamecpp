#pragma once

namespace Engine::Physics {

struct AABB {
    float minX, minY;
    float maxX, maxY;

    static bool Overlap(const AABB& a, const AABB& b) {
        return (a.minX <= b.maxX && a.maxX >= b.minX) &&
               (a.minY <= b.maxY && a.maxY >= b.minY);
    }
};

class PhysicsWorld {
public:
    PhysicsWorld(float gravityY = -9.81f) : m_gravityY(gravityY) {}

    void Step(float deltaTime) {
    }

private:
    float m_gravityY;
};

}
