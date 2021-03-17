/**
 * @file PathReferncePointCalculator.h
 * @brief Path reference point calculator.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#pragma once

#include <memory>
#include <optional>
#include "PathPointFinderInterface.h"
#include "CrossingPointCalculatorInterface.h"

namespace path_reference_point_calculator {
using namespace path_point_finder;
using namespace crossing_point_calculator;
/**
 * @brief PathReferncePointCalculator class.
 * @details Calculates reference point on path for given car state.
 */
class PathReferncePointCalculator {
public:
    /**
     * @brief PathReferncePointCalculator constructor.
     * @param[in] path Path on which will be find refernce point.
     * @param[in] maxSearchAngle Maximum angle for guiding point search on path (in front on the car).
     */
    PathReferncePointCalculator(std::vector<PathPoint> &path, const float &maxSearchAngle);
    /**
     * @brief pathReferencePoint function.
     * @param[in] carState Current car state for which will be calculated refernce point. 
     * @return PathPoint Refernce point on given path. 
     */
    [[nodiscard]] std::optional<PathPoint> pathReferencePoint(const CarState &carState) noexcept;
    /**
     * @brief pointOutOfSegment function.
     * @param[in] point Point that need to be checked.
     * @param[in] sStartPoint Path segment start point.
     * @param[in] sFinishPoint Path segment finish point.
     * @return true If point is out of given path segment.
     * @return false It point is part of given path segment.
     */
    [[nodiscard]] bool pointOutOfSegment(const PathPoint &point, const PathPoint &sStartPoint, 
                                         const PathPoint &sFinishPoint) const noexcept;
    /**
     * @brief squareDistanceToPoint function.
     * @param[in] point1 First point for distance calculation.
     * @param[in] point2 Second point for distance calculation.
     * @return float Square distance between given points.
     */
    [[nodiscard]] float squareDistanceToPoint(const PathPoint &point1, const PathPoint &point2) const noexcept;

private:
    std::shared_ptr<PathPointFinderInterface> mPathPointFinder; /**< Finds guiding point on given path. */
    std::shared_ptr<CrossingPointCalculatorInterface> mCrossingPointCalculator; /**< Finds crossing point between path 
    segment and line that goes through given car state. */
    std::vector<PathPoint> mPath; /**< Path on which will be find reference point.*/
};

} // path_reference_point_calculator