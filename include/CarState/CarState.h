/**
 * @file CarState.h
 * @brief Custom car state structure.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#pragma once
namespace path_reference_point_calculator {
/**
 * @brief CarState structure.
 * @details Custom car state structure contains x,y coordinates, yaw angle and speed.
 */
struct CarState {
    float x = 0.0f;     /**< Car x coordinate [meters].*/
    float y = 0.0f;     /**< Car y coordinate [meters]. */
    float yaw = 0.0f;   /**< Car heading angle [radians].*/
    float speed = 0.0f; /**< Car linear speed [m/s]. */
    /**
     * @brief Construct a new Car State struct.
     * @details Default constructor for new Car State struct.
     */
    CarState() = default;
    /**
     * @brief Constructor for new Car State struct.
     * @param[in] carX Current car x coordinate [meters].
     * @param[in] carY Current car y coordinate [meters].
     * @param[in] carYaw Current car yaw angle [radians].
     * @param[in] carSpeed Current car linear speed [m/s].
     */
    CarState(const float carX, const float carY, const float carYaw, const float carSpeed) 
    : x(carX), y(carY), yaw(carYaw), speed(carSpeed) {};
};

} // namespace path_reference_point_calculator