/**
 * @file PathPoint.h
 * @brief Custom path point structure.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#pragma once
namespace path_reference_point_calculator {
/**
 * @brief PathPoint structure.
 * @details Custom path point structure contains point x,y coordinates.
 */
struct PathPoint {
    float x = 0.0f; /**< Path point x coordinate [meters].*/
    float y = 0.0f; /**< Path point y coordinate [meters].*/
    /**
     * @brief Construct a new Path Point struct.
     * @details Default constructor for new Path Point struct.
     */
    PathPoint() = default;
    /**
     * @brief Constructor for new Path Point struct.
     * @param[in] pointX Path point x coordinate.
     * @param[in] pointY Path point y coordinate.
     */
    PathPoint(const float pointX, const float pointY)
    : x(pointX), y(pointY) {};
};

} // namespace path_reference_point_calculator