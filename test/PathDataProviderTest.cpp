#include <gtest/gtest.h>
#include "TextPathDataProvider.h"

using namespace path_reference_point_calculator;
using namespace path_data_provider;

TEST(PathDataProvidertest, ConstructorTest) {
    TextPathDataProvider textPathDataProvider;
    ASSERT_NO_THROW(AbstractPathDataProvider &dataProvider = textPathDataProvider);
}

TEST(CarStateDataProviderTest, PathPointDefaultParamsTest) {
    PathPoint pathPoint;
    EXPECT_FLOAT_EQ(pathPoint.x, 0.0f);
    EXPECT_FLOAT_EQ(pathPoint.y, 0.0f);
}

TEST(CarStateDataProviderTest, PathPointConstructorTest) {
    PathPoint pathPoint(1.0f, 2.0f);
    EXPECT_FLOAT_EQ(pathPoint.x, 1.0f);
    EXPECT_FLOAT_EQ(pathPoint.y, 2.0f);
}

TEST(PathDataProvidertest, TurnPathFromFileTest) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/Turn/Path";
    TextPathDataProvider textPathDataProvider;
    AbstractPathDataProvider &dataProvider = textPathDataProvider;
    ASSERT_NO_THROW(dataProvider.getPathFromFile(testFilePath));
    auto path = dataProvider.getPathFromFile(testFilePath);
    EXPECT_EQ(path.size(), 11);
    EXPECT_FLOAT_EQ(path.front().x, 0.0f);
    EXPECT_FLOAT_EQ(path.front().y, 0.0f);
    EXPECT_FLOAT_EQ(path.back().x, 6.6474967f);
    EXPECT_FLOAT_EQ(path.back().y, 5.6775174f);
}

TEST(PathDataProvidertest, EightCurvePathFromFileTest) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/EightCurve/Path";
    TextPathDataProvider textPathDataProvider;
    AbstractPathDataProvider &dataProvider = textPathDataProvider;
    ASSERT_NO_THROW(dataProvider.getPathFromFile(testFilePath));
    auto path = dataProvider.getPathFromFile(testFilePath);
    EXPECT_EQ(path.size(), 83);
    EXPECT_FLOAT_EQ(path.front().x, 0.0f);
    EXPECT_FLOAT_EQ(path.front().y, 0.0f);
    EXPECT_FLOAT_EQ(path.back().x, 0.0);
    EXPECT_FLOAT_EQ(path.back().y, 0.0f);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
