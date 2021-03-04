#include <fstream>
#include <iostream>
#include "TextCarStateDataProvider.h"

using namespace path_reference_point_calculator;
using namespace car_state_data_provider;

std::vector<CarState> TextCarStateDataProvider::getCarStateDataFromFile(const std::string &fileName) const noexcept {
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
  float yaw = 0.0f; 
  float velocity = 0.0f;
  std::vector<CarState> carStates;
  while (pathFile >> x >> y >> yaw >> velocity) {
    carStates.push_back(CarState(x, y, yaw, velocity));
  }
  pathFile.close();
  return carStates;
}