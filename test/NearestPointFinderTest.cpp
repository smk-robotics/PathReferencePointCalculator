#include "NearestPointFinderTest.h"

TEST_F(NearestPointFinderTest, ConstructorTest) {
    GuidingPathPointFinder guidingPathPointFinder;
    ASSERT_NO_THROW(PathPointFinderInterface &pathPointFinder = guidingPathPointFinder);
}

TEST_F(NearestPointFinderTest, BasicTurnPathTest) {
    ASSERT_EQ(mBasicTurnPath.size(), 11);
    ASSERT_FLOAT_EQ(mBasicTurnPath.front().x, 0.0f);
    ASSERT_FLOAT_EQ(mBasicTurnPath.front().y, 0.0f);
    ASSERT_FLOAT_EQ(mBasicTurnPath.back().x, 6.6474967f);
    ASSERT_FLOAT_EQ(mBasicTurnPath.back().y, 5.6775174f);
}

TEST_F(NearestPointFinderTest, EightCurvePathTest) {
    ASSERT_EQ(mEightCurvePath.size(), 83);
    ASSERT_FLOAT_EQ(mEightCurvePath.front().x, 0.0f);
    ASSERT_FLOAT_EQ(mEightCurvePath.front().y, 0.0f);
    ASSERT_FLOAT_EQ(mEightCurvePath.back().x, -0.83159143f);
    ASSERT_FLOAT_EQ(mEightCurvePath.back().y, 0.02987529f);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}