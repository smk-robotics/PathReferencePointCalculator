#include "PerpendicularLinesCrossingPointCalculator.h"

using namespace path_reference_point_calculator;
using namespace crossing_point_calculator;

PathPoint PerpendicularLinesCrossingPointCalculator::crossingPoint(const CarState &carState, 
                         const PathPoint &segmentStartPoint, const PathPoint &segmentFinishPoint) const noexcept {
    auto pathSegmentLineCoeff = lineCoefficients(segmentStartPoint, segmentFinishPoint);       
    auto perpendicularLineCoeff = perpendicularLineCoefficients(pathSegmentLineCoeff, carState);
    return crossingPoint(pathSegmentLineCoeff, perpendicularLineCoeff);
}

std::pair<float, float> PerpendicularLinesCrossingPointCalculator::lineCoefficients(const PathPoint &segmentStartPoint, 
                                                             const PathPoint &segmentFinishPoint) const noexcept {
    std::pair<float, float> lineCoefficients;
    lineCoefficients.first = (segmentStartPoint.y - segmentFinishPoint.y) / 
                                                                     (segmentStartPoint.x - segmentFinishPoint.x);
    lineCoefficients.second = segmentStartPoint.y - lineCoefficients.first * segmentStartPoint.x;
    return lineCoefficients;
}

std::pair<float, float> PerpendicularLinesCrossingPointCalculator::perpendicularLineCoefficients(
                       const std::pair<float, float> &lineCoefficients, const CarState &carState) const noexcept {
    std::pair<float, float> perpendicularLineCoefficients;
    perpendicularLineCoefficients.first = 1.0f / lineCoefficients.first;
    perpendicularLineCoefficients.second = - (carState.x + carState.y * lineCoefficients.first);
    return perpendicularLineCoefficients;
}

PathPoint PerpendicularLinesCrossingPointCalculator::crossingPoint(const std::pair<float, float> &lineCorfficients1, 
                                    const std::pair<float, float> &lineCorfficients2) const noexcept {
    PathPoint crossingPoint; 
    crossingPoint.x = (lineCorfficients2.second - lineCorfficients1.second) / 
                                                              (lineCorfficients1.first - lineCorfficients2.first);
    crossingPoint.y = lineCorfficients1.first * crossingPoint.x + lineCorfficients1.second;                                                                 
    return crossingPoint;
}