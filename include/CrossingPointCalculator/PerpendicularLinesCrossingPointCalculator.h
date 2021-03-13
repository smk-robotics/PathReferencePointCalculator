/**
 * @file CrossingPointCalculatorInterface.h
 * @brief Class with algorithm that calculates crossing point between two perpendicular lines.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include <utility>
#include "CrossingPointCalculatorInterface.h"

#pragma once

namespace path_reference_point_calculator::crossing_point_calculator {
/**
 * @brief PerpendicularLinesCrossingPointCalculator class.
 * @details Class with algorithm that calculates crossing point between approximated to line path segment and
 * perpendicular line from given car state.
 */
class PerpendicularLinesCrossingPointCalculator : public CrossingPointCalculatorInterface {
public:
    /** 
     * @brief PerpendicularLinesCrossingPointCalculator class constructor.
     */
    PerpendicularLinesCrossingPointCalculator() = default;
    /**
     * @brief crossingPoint function.
     * @details Calculate crossing point between linear path segment and perpendicular from given car state.
     * @param[in] carState Car state for which will be calculating crossing (refernce) point.  
     * @param segmentStartPoint Start point for path segment for which will be calculating crossing point. 
     * @param segmentFinishPoint Finish point for path segment for which will be calculating crossing point.
     * @return PathPoint 
     */
    [[nodiscard]] PathPoint crossingPoint(const CarState &carState, const PathPoint &segmentStartPoint, 
                            const PathPoint &segmentFinishPoint) const noexcept;
private:
    /**
     * @brief calculateLineCoefficients function.
     * @details Calculates k and b coefficients from line equation (y = k*x + b).
     * @param[in] linePoint1 First point from desired line.
     * @param[in] linePoint2 Second point from desired line.
     * @return std::pair<float, float> Line coefficients (first - k, second - b).
     */
    [[nodiscard]] std::pair<float, float> lineCoefficients(const PathPoint &linePoint1, 
                                                                      const PathPoint &linePoint2) const noexcept; 
    [[nodiscard]] std::pair<float, float> perpendicularLineCoefficients(const std::pair<float, float> &lineCoefficients, 
                                                                         const CarState &carState) const noexcept;
    [[nodiscard]] PathPoint crossingPoint(const std::pair<float, float> &lineCorfficients, 
                                     const std::pair<float, float> &perpendicularLineCorfficients) const noexcept;
};
} // path_reference_point_calculator::crossing_point_calculator