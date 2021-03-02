/**
 * @file AbstractCarStateDataProvider.h
 * @brief Abstract car state data provider.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include <vector>
#include <string>
#include "CarState.h"

#pragma once

namespace path_reference_point_calculator::car_state_data_provider {
/**
 * @brief AbstractCarStateDataProvider class.
 * @details Abstract base car state data provider class for any file formats.
 */
class AbstractCarStateDataProvider {
public:
    /**
     * @brief getCarStateDataFromFile function.
     * @details Parse any file with car state data to vector with car states.
     * @return Vector with car states.
     * @see CarState.h
     */
    virtual std::vector<CarState> getCarStateDataFromFile(const std::string &fileName) const noexcept = 0;
    /**
     * @brief Virtual class destructor.
     */
    virtual ~AbstractCarStateDataProvider() = default;
protected:
    /**
     * @brief fileNameValid function.
     * @details Check that given filename is valid.
     * @return True if name valid, false if not.
     */
    bool fileNameValid(const std::string &fileName) const;
    /**
     * @brief fileExists function.
     * @details Check that given file exists in hosts filesystem.
     * @return True if file exists, false if not.
     */
    bool fileExists(const std::string &fileName) const;
};

} // namespace path_reference_point_calculator::car_state_data_provider