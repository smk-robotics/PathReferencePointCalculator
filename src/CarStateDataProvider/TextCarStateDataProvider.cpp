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
  CarState currentCarState;
  std::vector<CarState> carStates;
  while (pathFile >> currentCarState.x >> currentCarState.y >> currentCarState.yaw >> currentCarState.speed) {
    carStates.push_back(currentCarState);
  }
  pathFile.close();
  return carStates;
}