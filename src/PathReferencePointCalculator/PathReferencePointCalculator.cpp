#include <math.h>
#include "GuidingPathPointFinder.h"
#include "PathReferncePointCalculator.h"
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
        if (pointOutOfSegment(referencePoint.value(), mPath.at(gPointIndex - 1), mPath.at(gPointIndex))) {
            if (squareDistanceToPoint(referencePoint.value(), mPath.at(gPointIndex - 1)) < 
                squareDistanceToPoint(referencePoint.value(), mPath.at(gPointIndex))) {
                referencePoint = mPath.at(gPointIndex - 1);
            } else {
                referencePoint = mPath.at(gPointIndex);
            }
        }
    }
    return referencePoint;
}

bool PathReferncePointCalculator::pointOutOfSegment(const PathPoint &point, const PathPoint &sStartPoint, 
                                                    const PathPoint &sFinishPoint) const noexcept {
    if (point.x > std::max(sStartPoint.x, sFinishPoint.x) || point.x < std::min(sStartPoint.x, sFinishPoint.x) ||
        point.y > std::max(sStartPoint.y, sFinishPoint.y) || point.y < std::min(sStartPoint.y, sFinishPoint.y)) {
        return true;
    }
    return false;
}

float PathReferncePointCalculator::squareDistanceToPoint(const PathPoint &point1, 
                                                         const PathPoint &point2) const noexcept {
    return pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2);
}