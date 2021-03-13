/**
 * @file GuidingPathPointFinder.h
 * @brief Class with simple least squares algorithm that calculates nearest path point to given car state.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include "PathPointFinderInterface.h"

#pragma once

namespace path_reference_point_calculator::path_point_finder {
/**
 * @brief GuidingPathPointFinder class.
 * @details Class with algorithm that finds guiding point (nearest point in front of the car) in path 
 * for given car state.
 */
class GuidingPathPointFinder : public PathPointFinderInterface {
public:
    /**
     * @brief GuidingPathPointFinder class constructor.
     */
    GuidingPathPointFinder() = default;
    /**
     * @brief pathPointIndex functrion
     * @details Find nearest path point in front of the car.
     * @param[in] state Current car state (x, y, yaw, speed).
     * @param[in] path Path points vector. 
     * @return size_t Index of nearest path point from path points vector to given car state. 
     */
    [[nodiscard]] size_t pathPointIndex(const CarState &state, const std::vector<PathPoint> &path) const noexcept 
                                                                                                         override;
};

} // namespace path_reference_point_calculator::path_point_finder