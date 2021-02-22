#include <utility>
#include <list>

class AbstractPathDataProvider {
public:
  AbstractPathDataProvider(const std::string filename);
  virtual std::list<std::pair<float, float>> getPathFromFile(const std::string &pathFileName) = 0;
private:
  std::string mPathDataFilename;
};
