/**
 * @file CrossingPointCalculatorInterface.h
 * @brief Interface for algorithm that calculates crossing point for given path segment and car state.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include "CarState.h"
#include "PathPoint.h"

#pragma once

namespace path_reference_point_calculator::crossing_point_calculator {
/**
 * @brief CrossingPointCalculatorInterface class.
 * @details Interface for algorithm that that calculates crossing point for given path segment and car state.
 */
class CrossingPointCalculatorInterface {
public:
    /**
     * @brief crossingPoint function.
     * @param[in] carState Car state for which will be calculating crossing (refernce) point. 
     * @param[in] segmentStartPoint Start point for path segment for which will be calculating crossing point. 
     * @param[in] segmentFinishPoint Finish point for path segment for which will be calculating crossing point.
     * @return PathPoint Calculated crossing point for given car state and path segment.
     */
    virtual PathPoint crossingPoint(const CarState &carState, const PathPoint &segmentStartPoint, 
                                    const PathPoint &segmentFinishPoint) noexcept = 0;
    /**
     * @brief Virtual class destructor.
     */
    virtual ~CrossingPointCalculatorInterface() = default;
};

} // path_reference_point_calculator::crossing_point_calculator