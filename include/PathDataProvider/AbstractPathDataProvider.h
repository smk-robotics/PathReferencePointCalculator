/**
 * @file AbstractPathDataProvider.h
 * @brief Abstract path data provider for different file formats.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @copyright BSD-3-Clause License.
 */
#include <vector>
#include <string>
#include <utility>
#include "PathPoint.h"

#pragma once
namespace path_reference_point_calculator::path_data_provider {
/**
 * @brief AbstractPathDataProvider class.
 * @details Abstract base path data provider class for any file formats.
 */
class AbstractPathDataProvider {
public:
  /**
  * @brief getPathFromFile function.
  * @details Parse any file with path data to vector with points.
  * @return Vector with path points (std::pair<x_coord, y_coord>).
   */
  virtual std::vector<PathPoint> getPathFromFile(const std::string &pathFileName) const = 0;
  /**
   * @brief Virtual class destructor.
   */
  virtual ~AbstractPathDataProvider() = default;
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

} // namespace path_reference_point_calculator::path_data_provider