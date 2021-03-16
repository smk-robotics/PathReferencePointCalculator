#include "PathPointFinderTest.h"

TEST_F(PathPointFinderTest, ConstructorTest) {
    GuidingPathPointFinder guidingPathPointFinder;
    ASSERT_NO_THROW(PathPointFinderInterface &pathPointFinder = guidingPathPointFinder);
}

TEST_F(PathPointFinderTest, BasicTurnPathTest) {
    ASSERT_EQ(mBasicTurnPath.size(), 11);
    ASSERT_FLOAT_EQ(mBasicTurnPath.front().x, 0.0f);
    ASSERT_FLOAT_EQ(mBasicTurnPath.front().y, 0.0f);
    ASSERT_FLOAT_EQ(mBasicTurnPath.back().x, 6.6474967f);
    ASSERT_FLOAT_EQ(mBasicTurnPath.back().y, 5.6775174f);
}

TEST_F(PathPointFinderTest, EightCurvePathTest) {
    ASSERT_EQ(mEightCurvePath.size(), 83);
    ASSERT_FLOAT_EQ(mEightCurvePath.front().x, 0.0f);
    ASSERT_FLOAT_EQ(mEightCurvePath.front().y, 0.0f);
    ASSERT_FLOAT_EQ(mEightCurvePath.back().x, 0.0);
    ASSERT_FLOAT_EQ(mEightCurvePath.back().y, 0.0f);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}