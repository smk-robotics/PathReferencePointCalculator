/**
 * @file Line.h
 * @brief Custom structure for line equation.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include <iostream>

#pragma once

namespace path_reference_point_calculator {
/**
 * @brief Line structure.
 * @details Custom structure for line equation coefficient. May contant coefficients for normal line (y = kx + b) 
 * or vertical line (x = x0).
 */
struct Line {
    float k = 0.0f;  /**< K coefficient from classic line equation (y = kx +b). */
    float b = 0.0f;  /**< B coefficient from classic line equation (y = kx +b). */
    float x0 = 0.0f; /**< X coordinate for vertical line equation (x = x0). */
    bool vertical = true; /**< Parameter to determine vertical line (true if line is vertical and need to use equation 
    for vertical line). */
    /** 
     * @brief Constructor for a new Line struct.
     * @details Default constructor for Line structure. Creates vertical line in (0;0) point. 
     */
    Line() = default;
    /**
     * @brief Construct for a new Line struct.
     * @details Constructor for classic line.
     * @param[in] kCoeff K coefficient from classic line equation (y = kx + b).
     * @param[in] bCoeff B coefficient from classic line equation (y = kx + b).
     * @attention If pass wrong paramaneters, will create default vertical line.
     */
    Line(const float kCoeff, const float bCoeff) {
        if (kCoeff == 0.0f && bCoeff == 0.0f) {
            std::cerr << "[ERROR] - Line creating fail. k and b coefficients equals 0."<< std::endl;
            Line();
        } else {
            k = kCoeff;
            b = bCoeff;
            x0 = 0.0f;
            vertical = false;
        }
    };
    /**
     * @brief Construct a new Line object
     * @details Constructor for vertical line.
     * @param[in] xCoord X coordinate for vertical line equation (x = x0).
     */
    Line(const float xCoord) : k(0.0f), b(0.0f), x0(xCoord), vertical(true) {};
    /**
     * @brief Construct a new Line object.
     * @details Constructor for classic line.
     * @param[in] kCoeff K coefficient from classic line equation (y = kx + b).
     * @param[in] bCoeff B coefficient from classic line equation (y = kx + b).
     * @param[in] isVertical Parameter that determines that line is not vertical.
     * @attention If pass wrong paramaneters, will create default vertical line.
     */
    Line(const float kCoeff, const float bCoeff, const bool isVertical) {
        if (kCoeff != 0.0f && bCoeff != 0.0f && isVertical == false) {
            k = kCoeff;
            b = bCoeff;
            x0 = 0.0f;
            vertical = false;
        } else {
            std::cerr << "[ERROR] - Line creating fail. Maybe it's vertical?"<< std::endl;
            Line();
        }
    }
    /**
     * @brief Construct a new Line object.
     * @details Constructor for vertical line (x = x0).
     * @param[in] xCoord X coordinate for vertical line equation (x = x0).
     * @param[in] isVertical Check that line is really need to be vertical. 
     * @attention If pass wrong paramaneters, will create default vertical line.
     */
    Line(const float xCoord, const bool isVertical) {
        if (isVertical == true) {
            k = 0.0f;
            b = 0.0f;
            x0 = xCoord;
            vertical = true;
        } else {
            std::cerr << "[ERROR] - Line creating fail. Line is not vertical."<< std::endl;
        }
    }
};

} // path_reference_point_calculator