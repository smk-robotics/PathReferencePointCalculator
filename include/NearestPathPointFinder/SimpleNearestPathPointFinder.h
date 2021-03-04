/**
 * @file SimpleNearestPathPointFinder.h
 * @brief Class with simple least squares algorithm that calculates nearest path point to given car state.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include "NearestPathPointFinderInterface.h"

#pragma once

namespace path_reference_point_calculator::nearest_path_point_finder {
/**
 * @brief SimpleNearestPathPointFinder class.
 * @details Class with simple least squares algorithm.
 */
class SimpleNearestPathPointFinder : public NearestPathPointFinderInterface {
public:
    /**
     * @brief SimpleNearestPathPointFinder class constructor.
     */
    SimpleNearestPathPointFinder() = default;
    /**
     * @brief nearestPathPointIndex functrion
     * @details Use simple least squares comparison to find nearest path point to given car state.
     * @param[in] state Current car state (x, y, yaw, speed).
     * @param[in] path Path points vector. 
     * @return size_t Index of nearest path point from path points vector to given car state. 
     */
    size_t nearestPathPointIndex(const CarState &state, const std::vector<PathPoint> &path) const noexcept override;
};

} // namespace path_reference_point_calculator::nearest_path_point_finder