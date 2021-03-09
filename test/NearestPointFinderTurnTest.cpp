#include "NearestPointFinderTest.h"

TEST_F(NearestPointFinderTest, FindNearestPointBasicTurnTest1) {
    CarState carState(0.0f, 0.0f, 0.0f, 0.0f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    auto pointIndex = 0;
    ASSERT_NO_THROW(pointIndex = nearestPathPointFinder.nearestPathPointIndex(carState, mBasicTurnPath));
    EXPECT_EQ(pointIndex, 0);
}

TEST_F(NearestPointFinderTest, FindNearestPointBasicTurnTest2) {
    CarState carState(-1.0f, -1.0f, 0.0f, 0.0f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mBasicTurnPath), 0);
}

TEST_F(NearestPointFinderTest, FindNearestPointBasicTurnTest3) {
    CarState carState(5.6775174f, 5.6774964f, 0.0f, 0.0f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mBasicTurnPath), 9);
}

TEST_F(NearestPointFinderTest, FindNearestPointBasicTurnTest4) {
    CarState carState(7.0f, 7.0f, 0.0f, 0.0f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mBasicTurnPath), 9);
}

TEST_F(NearestPointFinderTest, FindNearestPointBasicTurnTest5) {
    CarState carState(0.694117729740599f, 2.68395291409013f, 0.4886924f,	0.1f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mBasicTurnPath), 3);
}

TEST_F(NearestPointFinderTest, FindNearestPointBasicTurnTest6) {
    CarState carState(0.694117729740599f, 2.68395291409013f, 0.4886924f,	0.1f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mBasicTurnPath), 3);
}

TEST_F(NearestPointFinderTest, FindNearestPointBasicTurnTest7) {
    CarState carState(3.26275540704174f, 5.12149735658379f, 1.1170112f, 0.1f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mBasicTurnPath), 6);
}

TEST_F(NearestPointFinderTest, FindNearestPointBasicTurnTest8) {
    CarState carState(3.0f, 4.0f, 1.0f, 0.1f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    auto pointIndex = 0;
    ASSERT_NO_THROW(pointIndex = nearestPathPointFinder.nearestPathPointIndex(carState, mBasicTurnPath));
    EXPECT_EQ(pointIndex, 6);
}

TEST_F(NearestPointFinderTest, FindNearestPointBasicTurnTest9) {
    CarState carState(-1.0f, -1.0f, 0.0f, 0.1f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mBasicTurnPath), 0);
}

TEST_F(NearestPointFinderTest, FindNearestPointBasicTurnTest10) {
    CarState carState(10.0f, 10.0f, 0.0f, 0.0f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    EXPECT_EQ(nearestPathPointFinder.nearestPathPointIndex(carState, mBasicTurnPath), 9);
}