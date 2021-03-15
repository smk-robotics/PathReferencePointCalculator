
#include <limits>
#include <math.h>
#include <iostream>
#include "GuidingPathPointFinder.h"

using namespace path_reference_point_calculator;
using namespace path_point_finder;

size_t GuidingPathPointFinder::pathPointIndex(const CarState &state, std::vector<PathPoint> &path) const noexcept {
    size_t gPointIndex = std::numeric_limits<size_t>::max(); /**< Guiding path point index. */
    long double currentSquares = 0;
    long double minSquares = std::numeric_limits<long double>::max();
    for (auto i = 1; i < path.size(); i++) {
        if (path.at(i).passed == false) {
            auto dx = path.at(i).x - state.x;
            auto dy = path.at(i).y - state.y;
            auto deltaAngle = fabs(atan2(dy, dx) - state.yaw);
            currentSquares = pow(dx, 2) + pow(dy, 2);
            if (i < gPointIndex && currentSquares <= minSquares && deltaAngle <= mMaxSearchAngle) {
                minSquares = currentSquares;
                gPointIndex = i;
            }
        }
    }
    if (gPointIndex != std::numeric_limits<size_t>::max()) {
        markPassingPoints(path, gPointIndex);
        return gPointIndex;
    } else {
        return 0; /**< return 0 if no passable point in path found. */
    }
}

void GuidingPathPointFinder::markPassingPoints(std::vector<PathPoint> &path, const size_t pointIndex) const noexcept {
    for (auto i = 0; i < pointIndex - 1; i++) {
        path[i].passed = true;
    }
}