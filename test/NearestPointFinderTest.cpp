#include "NearestPointFinderTest.h"

TEST_F(NearestPointFinderTest, ConstructorTest) {
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    ASSERT_NO_THROW(NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder);
}

TEST_F(NearestPointFinderTest, BasicTurnPathTest) {
    ASSERT_EQ(mBasicTurnPath.size(), 10);
    ASSERT_FLOAT_EQ(mBasicTurnPath.front().x, 0.0f);
    ASSERT_FLOAT_EQ(mBasicTurnPath.front().y, 0.0f);
    ASSERT_FLOAT_EQ(mBasicTurnPath.back().x, 5.6775174f);
    ASSERT_FLOAT_EQ(mBasicTurnPath.back().y, 5.6774964f);
}

TEST_F(NearestPointFinderTest, EightCurvePathTest) {
    ASSERT_EQ(mEightCurvePath.size(), 81);
    ASSERT_FLOAT_EQ(mEightCurvePath.front().x, 0.0f);
    ASSERT_FLOAT_EQ(mEightCurvePath.front().y, 0.0f);
    ASSERT_FLOAT_EQ(mEightCurvePath.back().x, 0.00028545715f);
    ASSERT_FLOAT_EQ(mEightCurvePath.back().y, 0.11905058f);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}