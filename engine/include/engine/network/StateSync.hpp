#pragma once
#include <cstdint>

namespace Engine::Network {

struct EntityStateSnapshot {
    uint32_t entityID;
    float posX, posY;
    uint32_t tickNumber;
};

class MultiplayerStateSync {
public:
    static EntityStateSnapshot Interpolate(const EntityStateSnapshot& a, const EntityStateSnapshot& b, float t) {
        EntityStateSnapshot res = a;
        res.posX = a.posX + (b.posX - a.posX) * t;
        res.posY = a.posY + (b.posY - a.posY) * t;
        return res;
    }
};

}
