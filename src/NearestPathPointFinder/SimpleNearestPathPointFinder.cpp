
#include <limits>
#include <math.h>
#include "SimpleNearestPathPointFinder.h"

using namespace path_reference_point_calculator;
using namespace nearest_path_point_finder;

size_t SimpleNearestPathPointFinder::nearestPathPointIndex(const CarState &state, 
                                                           const std::vector<PathPoint> &path) const noexcept {
    size_t nearestPathPointIndex = 0;
    long double currentSquares = 0;
    long double minSquares = std::numeric_limits<long double>::max();
    for (auto i = 0; i < path.size(); i++) {
        currentSquares = pow(state.x - path.at(i).x, 2) + pow(state.y - path.at(i).y, 2);
        if (currentSquares <= minSquares) {
            minSquares = currentSquares;
            nearestPathPointIndex = i;
        }
    }
    return nearestPathPointIndex;
}