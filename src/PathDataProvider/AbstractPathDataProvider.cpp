#include <fstream>
#include <iostream>
#include "AbstractPathDataProvider.h"

bool AbstractPathDataProvider::fileNameValid(const std::string &fileName) const noexcept {
    if (fileName.empty()) {
      std::cerr << "[PathDataProviderInterface] - Filename is empty!" << std::endl;
      return false;
    }
    return true;
}

bool AbstractPathDataProvider::fileExists(const std::string &fileName) const noexcept {
  if (!std::fstream(fileName.c_str())) {
    std::cerr << "[PathDataProviderInterface] - File " << fileName << " doesn't exists!" << std::endl;
    return false;
  }
  return true;
}
