/**
 * @file TextPathDataProvider.h
 * @brief Custom provider for path data from txt files.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include "AbstractPathDataProvider.h"

#pragma once
namespace path_reference_point_calculator::path_data_provider {
/**
 * @brief TextPathDataProvider class.
 * @details Custom provider for path data from txt files.
 */
class TextPathDataProvider : public AbstractPathDataProvider {
public:
    /**
     * @brief TextPathDataProvider class constructor.
     */
    TextPathDataProvider() = default;
    /**
     * @brief getPathFromFile function.
     * @details Parse txt file with path data to vector with points.
     * @return Vector with path points (std::pair<x_coord, y_coord>).
     */
    std::vector<std::pair<float, float>> getPathFromFile(const std::string &fileName) const noexcept override;
};

} // namespace path_reference_point_calculator::path_data_provider