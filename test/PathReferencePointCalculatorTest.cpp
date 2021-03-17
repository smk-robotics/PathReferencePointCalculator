#include <gtest/gtest.h>
#include "TextPathDataProvider.h"
#include "PathReferncePointCalculator.h"

constexpr float MAX_SEARCH_ANGLE = 1.5708f;

using namespace path_reference_point_calculator;
using namespace path_data_provider;

class PathReferncePointCalculatorTest : public ::testing::Test {
public:
    void SetUp() {
        TextPathDataProvider textPathDataProvider;
        AbstractPathDataProvider &dataProvider = textPathDataProvider;
        std::string testPathFile = __FILE__;
        testPathFile = testPathFile.substr(0, testPathFile.rfind("test"));
        testPathFile += "test-data/VerticalLine/Path";
        mVLinePath = dataProvider.getPathFromFile(testPathFile);
        testPathFile = testPathFile.substr(0, testPathFile.rfind("test"));
        testPathFile += "test-data/HorizontalLine/Path";
        mHLinePath = dataProvider.getPathFromFile(testPathFile);
        testPathFile = testPathFile.substr(0, testPathFile.rfind("test"));
        testPathFile += "test-data/Angle/Path";
        mAnglePath = dataProvider.getPathFromFile(testPathFile);
    }
protected:
    std::vector<PathPoint> mVLinePath;
    std::vector<PathPoint> mHLinePath;
    std::vector<PathPoint> mAnglePath;
};

TEST_F(PathReferncePointCalculatorTest, HorizontalLineTest) {
    PathReferncePointCalculator pathReferncePointCalculator(mHLinePath, MAX_SEARCH_ANGLE);
    CarState carState(0.0f, 1.0f, 0.0f, 0.0f);
    std::optional<PathPoint> rPoint; 
    EXPECT_NO_THROW(rPoint = pathReferncePointCalculator.pathReferencePoint(carState));
    EXPECT_EQ(rPoint.has_value(), true);
    EXPECT_FLOAT_EQ(rPoint.value().x, 0.0f);
    EXPECT_FLOAT_EQ(rPoint.value().y, 0.0f);
    carState = {1.0f, 1.0f, 0.0f, 0.0f};
    EXPECT_NO_THROW(rPoint = pathReferncePointCalculator.pathReferencePoint(carState));
    EXPECT_EQ(rPoint.has_value(), true);
    EXPECT_FLOAT_EQ(rPoint.value().x, 1.0f);
    EXPECT_FLOAT_EQ(rPoint.value().y, 0.0f);
    carState = {3.0f, 11.0f, 0.0f, 0.0f};
    EXPECT_NO_THROW(rPoint = pathReferncePointCalculator.pathReferencePoint(carState));
    EXPECT_EQ(rPoint.has_value(), true);
    EXPECT_FLOAT_EQ(rPoint.value().x, 3.0f);
    EXPECT_FLOAT_EQ(rPoint.value().y, 0.0f);
}

TEST_F(PathReferncePointCalculatorTest, VerticalLineTest1) {
    PathReferncePointCalculator pathReferncePointCalculator(mVLinePath, MAX_SEARCH_ANGLE);
    CarState carState(0.0f, 1.0f, 1.5708f, 0.0f);
    std::optional<PathPoint> rPoint; 
    EXPECT_NO_THROW(rPoint = pathReferncePointCalculator.pathReferencePoint(carState));
    EXPECT_EQ(rPoint.has_value(), true);
    EXPECT_FLOAT_EQ(rPoint.value().x, 0.0f);
    EXPECT_FLOAT_EQ(rPoint.value().y, 1.0f);
    carState = {1.0f, 1.0f, 1.5708f, 0.0f};
    EXPECT_EQ(rPoint.has_value(), true);
    EXPECT_FLOAT_EQ(rPoint.value().x, 0.0f);
    EXPECT_FLOAT_EQ(rPoint.value().y, 1.0f);
    carState = {1.0f, 1.0f, 0.0f, 0.0f};
    EXPECT_NO_THROW(rPoint = pathReferncePointCalculator.pathReferencePoint(carState));
    EXPECT_EQ(rPoint.has_value(), false);
}

TEST_F(PathReferncePointCalculatorTest, VerticalLineTest2) {
    PathReferncePointCalculator pathReferncePointCalculator(mVLinePath, MAX_SEARCH_ANGLE);
    CarState carState(11.0f, 8.0f, 1.5708f, 0.0f);
    std::optional<PathPoint> rPoint; 
    EXPECT_NO_THROW(rPoint = pathReferncePointCalculator.pathReferencePoint(carState));
    EXPECT_EQ(rPoint.has_value(), true);
    EXPECT_FLOAT_EQ(rPoint.value().x, 0.0f);
    EXPECT_FLOAT_EQ(rPoint.value().y, 8.0f);
}

TEST_F(PathReferncePointCalculatorTest, VerticalLineTest3) {
    PathReferncePointCalculator pathReferncePointCalculator(mVLinePath, MAX_SEARCH_ANGLE);
    CarState carState(11.0f, 8.0f, 1.5708f, 0.0f);
    std::optional<PathPoint> rPoint; 
    EXPECT_NO_THROW(rPoint = pathReferncePointCalculator.pathReferencePoint(carState));
    EXPECT_EQ(rPoint.has_value(), true);
    EXPECT_FLOAT_EQ(rPoint.value().x, 0.0f);
    EXPECT_FLOAT_EQ(rPoint.value().y, 8.0f);
}

TEST_F(PathReferncePointCalculatorTest, VerticalLineTest4) {
    PathReferncePointCalculator pathReferncePointCalculator(mVLinePath, MAX_SEARCH_ANGLE);
    CarState carState(3.0f, 11.0f, 1.5708f, 0.0f);
    std::optional<PathPoint> rPoint; 
    EXPECT_NO_THROW(rPoint = pathReferncePointCalculator.pathReferencePoint(carState));
    EXPECT_EQ(rPoint.has_value(), false);
}

TEST_F(PathReferncePointCalculatorTest, AnglePathTest1) {
    PathReferncePointCalculator pathReferncePointCalculator(mAnglePath, MAX_SEARCH_ANGLE);
    CarState carState(3.5f, 2.5f, -1.5708f, 0.0f);
    std::optional<PathPoint> rPoint; 
    EXPECT_NO_THROW(rPoint = pathReferncePointCalculator.pathReferencePoint(carState));
    EXPECT_EQ(rPoint.has_value(), true);
    EXPECT_FLOAT_EQ(rPoint.value().x, 2.0f);
    EXPECT_FLOAT_EQ(rPoint.value().y, 2.0f);
}

TEST_F(PathReferncePointCalculatorTest, AnglePathTest2) {
    PathReferncePointCalculator pathReferncePointCalculator(mAnglePath, MAX_SEARCH_ANGLE);
    CarState carState(0.0f, 0.0f, 0.0f, 0.0f);
    std::optional<PathPoint> rPoint; 
    EXPECT_NO_THROW(rPoint = pathReferncePointCalculator.pathReferencePoint(carState));
    EXPECT_EQ(rPoint.has_value(), true);
    EXPECT_FLOAT_EQ(rPoint.value().x, 1.0f);
    EXPECT_FLOAT_EQ(rPoint.value().y, 1.0f);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}