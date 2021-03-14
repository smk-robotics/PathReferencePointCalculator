#include <gtest/gtest.h>
#include "PerpendicularLinesCrossingPointCalculator.h"

using namespace path_reference_point_calculator;
using namespace crossing_point_calculator;

class MockPerpendicularLinesCrossingPointCalculator : public PerpendicularLinesCrossingPointCalculator {
public:
    using PerpendicularLinesCrossingPointCalculator::lineCoefficients;
    using PerpendicularLinesCrossingPointCalculator::perpendicularLineCoefficients;
    using PerpendicularLinesCrossingPointCalculator::crossingPoint;
};

class CrossingPointCalculatorTest : public ::testing::Test {
public:
    void SetUp() {
        
    }
    MockPerpendicularLinesCrossingPointCalculator mCrossingPointCalculator;
};