#include "PerpendicularLinesCrossingPointCalculator.h"

using namespace path_reference_point_calculator;
using namespace crossing_point_calculator;

PathPoint PerpendicularLinesCrossingPointCalculator::crossingPoint(const CarState &carState, 
                         const PathPoint &segmentStartPoint, const PathPoint &segmentFinishPoint) const noexcept {
    auto pathSegmentLineCoeff = lineCoefficients(segmentStartPoint, segmentFinishPoint);       
    auto perpendicularLineCoeff = perpendicularLineCoefficients(pathSegmentLineCoeff, carState);
    return crossingPoint(pathSegmentLineCoeff, perpendicularLineCoeff);
}

std::pair<float, float> PerpendicularLinesCrossingPointCalculator::lineCoefficients(const PathPoint &linePoint1, 
                                                                     const PathPoint &linePoint2) const noexcept {
    std::pair<float, float> lineCoefficients;
    lineCoefficients.first = (linePoint1.y - linePoint2.y) / (linePoint1.x - linePoint2.x);
    lineCoefficients.second = linePoint1.y - lineCoefficients.first * linePoint1.x;
    return lineCoefficients;
}

std::pair<float, float> PerpendicularLinesCrossingPointCalculator::perpendicularLineCoefficients(
                       const std::pair<float, float> &lineCoefficients, const CarState &carState) const noexcept {
    std::pair<float, float> perpendicularLineCoefficients;
    perpendicularLineCoefficients.first = 1.0f / lineCoefficients.first;
    perpendicularLineCoefficients.second = - (carState.x + carState.y * lineCoefficients.first);
    return perpendicularLineCoefficients;
}

PathPoint PerpendicularLinesCrossingPointCalculator::crossingPoint(const std::pair<float, float> &lineCorfficients, 
                                    const std::pair<float, float> &perpendicularLineCorfficients) const noexcept {
    PathPoint crossingPoint; 
    crossingPoint.x = (lineCorfficients.second - perpendicularLineCorfficients.second) / 
                                                   (lineCorfficients.first - perpendicularLineCorfficients.first);
    crossingPoint.y = lineCorfficients.first * crossingPoint.x + lineCorfficients.second;                                                                 
    return crossingPoint;
}