/**
 * @file AbstractPathDataProvider.h
 * @brief Abstract path data provider for different file formats.
 * @author Smirnov Kirill <smk-robotics@gmail.com>
 * @license Proprietary.
 */
#include <vector>
#include <string>
#include <utility>

#pragma once
/**
 * @brief AbstractPathDataProvider class.
 * @details Abstract base path data provider class for any file formats..
 */
class AbstractPathDataProvider {
public:
  /**
  * @brief getPathFromFile function.
  * @detailt Parse any file with path data to vector with points.
  * @return Vector with path points (std::pair<x_coord, y_coord>).
   */
  virtual std::vector<std::pair<float, float>> getPathFromFile(const std::string &pathFileName) const = 0;
  /**
   * @brief Virtual class destructor.
   */
  virtual ~AbstractPathDataProvider() = default;
protected:
  /**
   * @brief fileNameValid function.
   * @detailt Check that given filename is valid.
   * @return True if name valid, false if not.
   */
  bool fileNameValid(const std::string &fileName) const noexcept;
  /**
   * @brief fileExists function.
   * @detailt Check that given file exists in hosts filesystem.
   * @return True if file exists, false if not.
   */
  bool fileExists(const std::string &fileName) const noexcept;
};
