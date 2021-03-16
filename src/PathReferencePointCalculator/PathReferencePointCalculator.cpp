#include "PathReferncePointCalculator.h"
#include "GuidingPathPointFinder.h"
#include "PerpendicularLinesCrossingPointCalculator.h"

using namespace path_reference_point_calculator;

PathReferncePointCalculator::PathReferncePointCalculator(std::vector<PathPoint> &path, const float &maxSearchAngle) 
    : mPath(path) {
    mPathPointFinder = std::make_shared<GuidingPathPointFinder>(maxSearchAngle);
    mCrossingPointCalculator = std::make_shared<PerpendicularLinesCrossingPointCalculator>();
}

std::optional<PathPoint> PathReferncePointCalculator::pathReferencePoint(const CarState &carState) noexcept {
    std::optional<PathPoint> referencePoint;
    auto gPointIndex = mPathPointFinder->pathPointIndex(carState, mPath);
    if (gPointIndex != 0) {
        referencePoint = mCrossingPointCalculator->crossingPoint(carState, mPath.at(gPointIndex - 1), mPath.at(gPointIndex));
    }
    return referencePoint;
}