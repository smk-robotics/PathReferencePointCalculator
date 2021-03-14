[![Build Status](https://travis-ci.com/smk-robotics/PathReferencePointCalculator.svg?branch=develop)](https://travis-ci.com/github/smk-robotics/PathReferencePointCalculator)

# PathReferencePointCalculator
Path reference point calculator library. Calculates reference point on path for given car state.

# Build

If you want to just build libraries run: 
```
mkdir -p build && cd build
cmake .. && make -j6
```
# Tests

Before you can build and run tests you will need to build third-party gtest library:
```
cd third-party
./build_third_party.sh
```
After that you can build and run tests:
```
mkdir -p build && cd build
cmake -DBUILD_TESTS=ON .. && make -j6 
GTEST_COLOR=1 ctest --output-on-failure
``` 

# Visualization:

If you want to build and run visualization:
```
mkdir -p build && cd build
cmake -DBUILD_VISUALIZATION=ON .. && make -j6
./test/Visualization ${TEST_PATH}
``` 
*${TEST_PATH}* - name of path from test-data folder (Turn, Circle, EightCurve).

Visualization uses default opencv library (no need to install on Ubuntu 18.04).

# Maintainer

* Smirnov Kirill <smk-robotics@gmail.com>
