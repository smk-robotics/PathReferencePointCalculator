
#include <limits>
#include <math.h>
#include <iostream>
#include "GuidingPathPointFinder.h"

using namespace path_reference_point_calculator;
using namespace path_point_finder;

constexpr float MAX_DELTA_ANGLE = 90 * M_PI / 180.0 ;

size_t GuidingPathPointFinder::pathPointIndex(const CarState &state, 
                                                           const std::vector<PathPoint> &path) const noexcept {
    size_t guidingPathPointIndex = 0;
    long double currentSquares = 0;
    long double minSquares = std::numeric_limits<long double>::max();
    for (auto i = 1; i < path.size(); i++) {
        auto dx = path.at(i).x - state.x;
        auto dy = path.at(i).y - state.y;
        auto deltaAngle = fabs(atan2(dy, dx) - state.yaw);
        currentSquares = pow(dx, 2) + pow(dy, 2);
        if (currentSquares <= minSquares && deltaAngle <= MAX_DELTA_ANGLE) {
            minSquares = currentSquares;
            guidingPathPointIndex = i;
        }
    }
    return guidingPathPointIndex; // Will return 0 if no passable point in path found.
}