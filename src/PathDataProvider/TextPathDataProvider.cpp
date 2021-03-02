#include <fstream>
#include <iostream>
#include <stdexcept>
#include "TextPathDataProvider.h"

using namespace path_reference_point_calculator::path_data_provider;

std::vector<std::pair<float, float>> TextPathDataProvider::getPathFromFile(const std::string &fileName) const noexcept {
  if (!this->fileNameValid(fileName) || !this->fileExists(fileName)) {
    return {};
  }
  std::ifstream pathFile(fileName);
  if (!pathFile.is_open()) {
    std::cerr << "[TextPathDataProvider] - Can't open " << fileName << " file!" << std::endl;
    return {};
  }
  float x = 0.0f;
  float y = 0.0f;
  std::vector<std::pair<float, float>> path;
  while (pathFile >> x >> y) {
    path.push_back(std::make_pair(x, y));
  }
  pathFile.close();
  return path;
}