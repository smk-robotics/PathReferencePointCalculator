#include "PathPointFinderTest.h"

TEST_F(PathPointFinderTest, FindNearestPointEightCurveTest1) {
    CarState carState(0.0f, 0.0f, 3.14159f, 0.0f);
    GuidingPathPointFinder guidingPathPointFinder;
    PathPointFinderInterface &pathPointFinder = guidingPathPointFinder;
    EXPECT_EQ(guidingPathPointFinder.pathPointIndex(carState, mEightCurvePath), 1);
}

TEST_F(PathPointFinderTest, FindNearestPointEightCurveTest2) {
    CarState carState(-2.68395220635568f, 0.694120466339709f, 2.6528976f, 0.1f);
    GuidingPathPointFinder guidingPathPointFinder;
    PathPointFinderInterface &pathPointFinder = guidingPathPointFinder;
    EXPECT_EQ(guidingPathPointFinder.pathPointIndex(carState, mEightCurvePath), 4);
}

TEST_F(PathPointFinderTest, FindNearestPointEightCurveTest3) {
    CarState carState(0.199969350504888f, 0.001744306893717f, -3.1066914f, 0.1f);
    GuidingPathPointFinder guidingPathPointFinder;
    PathPointFinderInterface &pathPointFinder = guidingPathPointFinder;
    EXPECT_EQ(guidingPathPointFinder.pathPointIndex(carState, mEightCurvePath), 41);
}





