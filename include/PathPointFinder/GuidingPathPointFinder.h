/**
 * @file GuidingPathPointFinder.h
 * @brief Class with algorithm that finds guiding path point to given car state.
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
     * @details Find guiding point in path for given car state.
     * @param[in] state Current car state (x, y, yaw, speed).
     * @param[in] path Path points vector. 
     * @return size_t Index of guiding point from path points vector. 
     */
    [[nodiscard]] size_t pathPointIndex(const CarState &state, const std::vector<PathPoint> &path) const noexcept 
                                                                                                         override;
};

} // namespace path_reference_point_calculator::path_point_finder