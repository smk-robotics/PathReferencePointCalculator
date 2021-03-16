#include <fstream>
#include <iostream>
#include <stdexcept>
#include "TextPathDataProvider.h"

using namespace path_reference_point_calculator;
using namespace path_data_provider;

std::vector<PathPoint> TextPathDataProvider::getPathFromFile(const std::string &fileName) const noexcept {
  if (!this->fileNameValid(fileName) || !this->fileExists(fileName)) {
    return {};
  }
  std::ifstream pathFile(fileName);
  if (!pathFile.is_open()) {
    std::cerr << "[TextPathDataProvider] - Can't open " << fileName << " file!" << std::endl;
    return {};
  }
  PathPoint currentPathPoint;
  currentPathPoint.passed = false;
  std::vector<PathPoint> path;
  while (pathFile >> currentPathPoint.x >> currentPathPoint.y) {
    path.push_back(currentPathPoint);
  }
  pathFile.close();
  return path;
}