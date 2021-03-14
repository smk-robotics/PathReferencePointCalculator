/**
 * @file CrossingPointCalculatorInterface.h
 * @brief Class with algorithm that calculates crossing point between two perpendicular lines.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include <utility>
#include "Line.h"
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
                                                              const PathPoint &segmentFinishPoint) noexcept;
protected:
    /**
     * @brief lineCoefficients function.
     * @details Calculates equation coefficients for line that goes through given points.
     * @param[in] linePoint1 First point from desired line.
     * @param[in] linePoint2 Second point from desired line.
     * @return Line Custom structure contains line equation coefficients.
     */
    [[nodiscard]] Line lineCoefficients(const PathPoint &linePoint1, const PathPoint &linePoint2) noexcept;
    /**
     * @brief perpendicularLineCoefficients function.
     * @details Calculates equation coefficients of perpendicular line for linear path segment.
     * @param[in] Line Custom line structure contains line equation coefficients.
     * @param[in] carState Car state for which the perpendicular line will be calculated.
     * @return Line Custom structure contains line equation coefficients.
     */
    [[nodiscard]] Line perpendicularLineCoefficients(const Line &line, const CarState &carState) const noexcept;
    /**
     * @brief crossingPoint function.
     * @param[in] Line1 Custom line structure contains equation coefficients for first line.
     * @param[in] Line2 Custom line structure contains equation coefficients for second line.
     * @return PathPoint Crossing point between two lines.
     */
    [[nodiscard]] PathPoint crossingPoint(const Line &Line1, const Line &Line2) const noexcept;

    void normalizeAngle(float &angle);
};

} // path_reference_point_calculator::crossing_point_calculator