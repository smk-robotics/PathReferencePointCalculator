#include <cmath>
#include "PerpendicularLinesCrossingPointCalculator.h"

using namespace path_reference_point_calculator;
using namespace crossing_point_calculator;

PathPoint PerpendicularLinesCrossingPointCalculator::crossingPoint(const CarState &carState, 
                         const PathPoint &segmentStartPoint, const PathPoint &segmentFinishPoint) noexcept {
    auto pathSegmentLineCoeff = lineCoefficients(segmentStartPoint, segmentFinishPoint);       
    auto perpendicularLineCoeff = perpendicularLineCoefficients(pathSegmentLineCoeff, carState);
    return crossingPoint(pathSegmentLineCoeff, perpendicularLineCoeff);
}

Line PerpendicularLinesCrossingPointCalculator::lineCoefficients(const PathPoint &segmentStartPoint, 
                                                                 const PathPoint &segmentFinishPoint) noexcept {
    if (segmentStartPoint.x == segmentFinishPoint.x) { // Vertical line check.
        return Line(segmentStartPoint.x);
    } else {
        float k = (segmentFinishPoint.y - segmentStartPoint.y) / (segmentFinishPoint.x - segmentStartPoint.x);
        normalizeAngle(k);
        auto b = segmentFinishPoint.y - k * segmentFinishPoint.x;
        return Line(k, b);
    }
}

Line PerpendicularLinesCrossingPointCalculator::perpendicularLineCoefficients(const Line &line, 
                                                                        const CarState &carState) const noexcept {
    if (line.vertical == true) {
        return Line(0.0, carState.y);
    } else {
        auto k = -1.0f / line.k;
        auto b = carState.y - k * carState.x;
        return Line(k, b);
    }
}

PathPoint PerpendicularLinesCrossingPointCalculator::crossingPoint(const Line &Line1, const Line &Line2) const noexcept {
    PathPoint crossingPoint; 
    if (Line1.vertical == false && Line2.vertical == false) {
        crossingPoint.x = (Line2.b - Line1.b) / (Line1.k - Line2.k);
        crossingPoint.y = Line2.k * crossingPoint.x + Line2.b;   
    } else if (Line1.vertical == true) {
        crossingPoint.x = Line1.x0;
        crossingPoint.y = Line2.k * crossingPoint.x + Line2.b;                                                                 
    } else {
        crossingPoint.x = Line2.x0;
        crossingPoint.y = Line1.k * crossingPoint.x + Line1.b;
    }                                                       
    return crossingPoint;
}

void PerpendicularLinesCrossingPointCalculator::normalizeAngle(float &angle) {
    while (angle > M_PI && angle < -M_PI) {
        if (angle > M_PI) angle -= 2 * M_PI;  
        if (angle < -M_PI) angle += 2 * M_PI;
    }
}