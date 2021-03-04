
/**
 * @file NearestPathPointFinderInterface.h
 * @brief Abstract class for algorithm that finds nearest path point to given car state.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include <vector>
#include "CarState.h"
#include "PathPoint.h"

#pragma once 

namespace path_reference_point_calculator::nearest_path_point_finder {
/**
 * @brief AbstractNearestPathPointFinder class.
 * @details Abstract class for algorithm that finds nearest path point to given car state.
 */
class NearestPathPointFinderInterface {
public:
    /**
     * @brief nearestPathPointIndex functrion
     * @param[in] state Current car state (x, y, yaw, speed).
     * @param[in] path Path points vector. 
     * @return size_t Index of nearest path point from path points vector to given car state. 
     */
    virtual size_t nearestPathPointIndex(const CarState &state, const std::vector<PathPoint> &path) const noexcept = 0;
    /**
     * @brief Virtual class destructor.
     */
    virtual ~NearestPathPointFinderInterface() = default;
};

} // namespace path_reference_point_calculator::nearest_path_point_finder