#include "CrossingPointCalculatorTest.h"

TEST_F(CrossingPointCalculatorTest, ConstructorTest) {
    PerpendicularLinesCrossingPointCalculator pLinesCrossingPointCalculator;
    ASSERT_NO_THROW(CrossingPointCalculatorInterface &crossingPointCalculator = pLinesCrossingPointCalculator);
}

TEST_F(CrossingPointCalculatorTest, LineCoefficientsCalculationTest1) {
    PathPoint p1(0.0, 0.0);
    PathPoint p2(1.0, 1.0);
    auto line = mCrossingPointCalculator.lineCoefficients(p1, p2);
    EXPECT_EQ(line.vertical, false);
    EXPECT_FLOAT_EQ(line.k, 1.0f);
    EXPECT_FLOAT_EQ(line.b, 0.0f);
}

TEST_F(CrossingPointCalculatorTest, LineCoefficientsCalculationTest2) {
    PathPoint p1(0.0, 0.0);
    PathPoint p2(-1.0, 1.0);
    auto line = mCrossingPointCalculator.lineCoefficients(p1, p2);
    EXPECT_EQ(line.vertical, false);
    EXPECT_FLOAT_EQ(line.k, -1.0f);
    EXPECT_FLOAT_EQ(line.b, 0.0f);
}

TEST_F(CrossingPointCalculatorTest, LineCoefficientsCalculationTest3) {
    PathPoint p1(0.0, 0.0);
    PathPoint p2(-1.0, -1.0);
    auto line = mCrossingPointCalculator.lineCoefficients(p1, p2);
    EXPECT_EQ(line.vertical, false);
    EXPECT_FLOAT_EQ(line.k, 1.0f);
    EXPECT_FLOAT_EQ(line.b, 0.0f);
}

TEST_F(CrossingPointCalculatorTest, LineCoefficientsCalculationTest4) {
    PathPoint p1(1.0, 0.0);
    PathPoint p2(3.0, 2.0);
    auto line = mCrossingPointCalculator.lineCoefficients(p1, p2);
    EXPECT_EQ(line.vertical, false);
    EXPECT_FLOAT_EQ(line.k, 1.0f);
    EXPECT_FLOAT_EQ(line.b, -1.0f);
}

TEST_F(CrossingPointCalculatorTest, LineCoefficientsCalculationTest5) {
    PathPoint p1(2.0, 0.0);
    PathPoint p2(2.0, 3.0);
    auto line = mCrossingPointCalculator.lineCoefficients(p1, p2);
    EXPECT_EQ(line.vertical, true);
    EXPECT_FLOAT_EQ(line.x0, 2.0f);
}

TEST_F(CrossingPointCalculatorTest, LineCoefficientsCalculationTest6) {
    PathPoint p1(-22.0, 0.0);
    PathPoint p2(-22.0, 3.0);
    auto line = mCrossingPointCalculator.lineCoefficients(p1, p2);
    EXPECT_EQ(line.vertical, true);
    EXPECT_FLOAT_EQ(line.x0, -22.0f);
}

TEST_F(CrossingPointCalculatorTest, PerpendicularLineCoefficientsCalculationTest1) {
    Line originLine(1.0f, 0.0f);
    CarState state(0.0f, 1.0f, 0.0f, 0.0f);
    auto pLine = mCrossingPointCalculator.perpendicularLineCoefficients(originLine, state);
    EXPECT_EQ(pLine.vertical, false);
    EXPECT_FLOAT_EQ(pLine.k, -1.0f);
    EXPECT_FLOAT_EQ(pLine.b, 1.0f);
}

TEST_F(CrossingPointCalculatorTest, PerpendicularLineCoefficientsCalculationTest2) {
    Line originLine(-1.0f, 0.0f);
    CarState state(0.0f, 1.0f, 0.0f, 0.0f);
    auto pLine = mCrossingPointCalculator.perpendicularLineCoefficients(originLine, state);
    EXPECT_EQ(pLine.vertical, false);
    EXPECT_FLOAT_EQ(pLine.k, 1.0f);
    EXPECT_FLOAT_EQ(pLine.b, 1.0f);
}

TEST_F(CrossingPointCalculatorTest, PerpendicularLineCoefficientsCalculationTest3) {
    Line originLine(2.0f);
    CarState state(0.0f, 1.0f, 0.0f, 0.0f);
    auto pLine = mCrossingPointCalculator.perpendicularLineCoefficients(originLine, state);
    EXPECT_EQ(pLine.vertical, false);
    EXPECT_FLOAT_EQ(pLine.k, 0.0f);
    EXPECT_FLOAT_EQ(pLine.b, 1.0f);
}

TEST_F(CrossingPointCalculatorTest, PerpendicularLineCoefficientsCalculationTest4) {
    Line originLine(0.333f, 9.0f);
    CarState state(-9.0f, -1.0f, 0.0f, 0.0f);
    auto pLine = mCrossingPointCalculator.perpendicularLineCoefficients(originLine, state);
    EXPECT_EQ(pLine.vertical, false);
    EXPECT_FLOAT_EQ(pLine.k, -3.0030029f);
    EXPECT_FLOAT_EQ(pLine.b, -28.027025f);
}

TEST_F(CrossingPointCalculatorTest, PerpendicularLineCoefficientsCalculationTest5) {
    Line originLine(0.0);
    CarState state(10.0f, 1.0f, 0.0f, 0.0f);
    auto pLine = mCrossingPointCalculator.perpendicularLineCoefficients(originLine, state);
    EXPECT_EQ(pLine.vertical, false);
    EXPECT_FLOAT_EQ(pLine.k, 0.0f);
    EXPECT_FLOAT_EQ(pLine.b, 1.0f);
}

TEST_F(CrossingPointCalculatorTest, PerpendicularLineCoefficientsCalculationTest6) {
    Line originLine(0.0f);
    CarState state(-2.0f, -3.0f, 0.0f, 0.0f);
    auto pLine = mCrossingPointCalculator.perpendicularLineCoefficients(originLine, state);
    EXPECT_EQ(pLine.vertical, false);
    EXPECT_FLOAT_EQ(pLine.k, 0.0f);
    EXPECT_FLOAT_EQ(pLine.b, -3.0f);
}

TEST_F(CrossingPointCalculatorTest, LinesCrossingPointCalculationTest1) {
    Line originLine(1.0f, 0.0f);
    Line perpendicularLine(-1.0f, 0.0f);
    auto point = mCrossingPointCalculator.crossingPoint(originLine, perpendicularLine);
    EXPECT_FLOAT_EQ(point.x, 0.0f);
    EXPECT_FLOAT_EQ(point.y, 0.0f);
}

TEST_F(CrossingPointCalculatorTest, LinesCrossingPointCalculationTest2) {
    Line originLine(1.0f, 0.0f);
    Line perpendicularLine(0.0f, 1.0f);
    auto point = mCrossingPointCalculator.crossingPoint(originLine, perpendicularLine);
    EXPECT_FLOAT_EQ(point.x, 1.0f);
    EXPECT_FLOAT_EQ(point.y, 1.0f);
}

TEST_F(CrossingPointCalculatorTest, LinesCrossingPointCalculationTest3) {
    Line originLine(0.0f);
    Line perpendicularLine(0.0f, 3.0f);
    auto point = mCrossingPointCalculator.crossingPoint(originLine, perpendicularLine);
    EXPECT_FLOAT_EQ(point.x, 0.0f);
    EXPECT_FLOAT_EQ(point.y, 3.0f);
}

TEST_F(CrossingPointCalculatorTest, LinesCrossingPointCalculationTest4) {
    Line originLine(-2.0f);
    Line anotherLine(1.0f, 5.0f);
    auto point = mCrossingPointCalculator.crossingPoint(originLine, anotherLine);
    EXPECT_FLOAT_EQ(point.x, -2.0f);
    EXPECT_FLOAT_EQ(point.y, 3.0f);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}