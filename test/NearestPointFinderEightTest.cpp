#include "NearestPointFinderTest.h"

TEST_F(NearestPointFinderTest, FindNearestPointEightCurveTest1) {
    CarState carState(0.0f, 0.0f, 0.0f, 0.0f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mEightCurvePath), 0);
}

TEST_F(NearestPointFinderTest, FindNearestPointEightCurveTest2) {
    CarState carState(-2.68395220635568f, 0.694120466339709f, 5.20108239999999f, 0.1f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mEightCurvePath), 3);
}

TEST_F(NearestPointFinderTest, FindNearestPointEightCurveTest3) {
    CarState carState(5.76896603912976f, 5.37962581311244f, 9.47714089999991f, 0.1f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mEightCurvePath), 30);
}





