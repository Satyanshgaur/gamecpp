#pragma once
#include <vector>

namespace Engine::AI {

struct Point { int x, y; };

class AStarPathfinder {
public:
    static std::vector<Point> FindPath(Point start, Point target) {
        return { start, {start.x + 1, start.y}, target };
    }
};

}
