#include <fstream>
#include <iostream>
#include "AbstractCarStateDataProvider.h"

using namespace path_reference_point_calculator::car_state_data_provider;

bool AbstractCarStateDataProvider::fileNameValid(const std::string &fileName) const {
    if (fileName.empty()) {
      std::cerr << "[PathDataProviderInterface] - Filename is empty!" << std::endl;
      return false;
    }
    return true;
}

bool AbstractCarStateDataProvider::fileExists(const std::string &fileName) const {
    if (!std::fstream(fileName.c_str())) {
        std::cerr << "[PathDataProviderInterface] - File " << fileName << " doesn't exists!" << std::endl;
    return false;
  }
  return true;
}