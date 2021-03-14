/**
 * @file PathPointFinderInterface.h
 * @brief Interface for algorithm that finds specific path point to given car state.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include <vector>
#include "CarState.h"
#include "PathPoint.h"

#pragma once 

namespace path_reference_point_calculator::path_point_finder {
/**
 * @brief PathPointFinderInterface class.
 * @details Interface for algorithm that finds specific path point to given car state.
 */
class PathPointFinderInterface {
public:
    /**
     * @brief pathPointIndex functrion
     * @param[in] state Current car state (x, y, yaw, speed).
     * @param[in] path Path points vector. 
     * @return size_t Index of required (depends on method) path point from path points vector to given car state. 
     */
    virtual size_t pathPointIndex(const CarState &state, const std::vector<PathPoint> &path) const noexcept = 0;
    /**
     * @brief Virtual class destructor.
     */
    virtual ~PathPointFinderInterface() = default;
};

} // namespace path_reference_point_calculator::path_point_finder