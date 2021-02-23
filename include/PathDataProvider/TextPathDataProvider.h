/**
 * @file TextPathDataProvider.h
 * @brief Custom provider for path data from txt files.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @license Proprietary.
 */
#include "AbstractPathDataProvider.h"

#pragma once
/**
 * @brief TextPathDataProvider class.
 * @details Custom provider for path data from txt files.
 */
class TextPathDataProvider : public AbstractPathDataProvider {
public:
    /**
     * @brief Class constructor.
     */
    TextPathDataProvider() = default;
    /**
     * @brief getPathFromFile function.
     * @detailt Parse txt file with path data to vector with points.
     * @return Vector with path points (std::pair<x_coord, y_coord>).
     */
    std::vector<std::pair<float, float>> getPathFromFile(const std::string &fileName) const override;
};
