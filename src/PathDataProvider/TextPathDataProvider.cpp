#include <fstream>
#include <iostream>
#include <stdexcept>
#include "TextPathDataProvider.h"

std::vector<std::pair<float, float>> TextPathDataProvider::getPathFromFile(const std::string &fileName) const {
  if (!this->fileNameValid(fileName) || !this->fileExists(fileName)) {
    return {};
  }
  std::ifstream pathFile(fileName);
  if (!pathFile.is_open()) {
    std::cerr << "[TextPathDataProvider] - Can't open " << fileName << " file!" << std::endl;
    return {};
  }
  float x = 0.0f, y = 0.0f;
  std::vector<std::pair<float, float>> path;
  while (pathFile >> x >> y) {
    path.push_back(std::make_pair(x, y));
  }
  pathFile.close();
  return path;
}
