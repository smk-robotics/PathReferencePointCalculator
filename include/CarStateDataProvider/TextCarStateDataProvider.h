/**
 * @file TextCarStateDataProvider.h
 * @brief Custom provider for car state data from txt files.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */

#include "AbstractCarStateDataProvider.h"

#pragma once 

namespace path_reference_point_calculator::car_state_data_provider { 
/**
 * @brief TextCarStateDataProvider class.
 * @details Custom provider for car state data from txt files.
 */
class TextCarStateDataProvider : public AbstractCarStateDataProvider {
public:
    /**
     * @brief TextCarStateDataProvider class constructor.
     */
    TextCarStateDataProvider() = default;
    /**
     * @brief getCarStateDataFromFile function.
     * @details Parse txt file with car state data to vector with states.
     * @return Vector with cas states.
     */
    std::vector<CarState> getCarStateDataFromFile(const std::string &fileName) const noexcept override;
};

} // namespace path_reference_point_calculator::car_state_data_provider