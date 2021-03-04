#include <gtest/gtest.h>
#include "TextPathDataProvider.h"

using namespace path_reference_point_calculator::path_data_provider;

TEST(PathDataProvidertest, ConstructorTest) {
    TextPathDataProvider TextPathDataProvider;
    ASSERT_NO_THROW(AbstractPathDataProvider &dataProvider = TextPathDataProvider);
}

TEST(PathDataProvidertest, BasicTurnPathFromFileTest) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/BasicTurn/Path";
    TextPathDataProvider TextPathDataProvider;
    AbstractPathDataProvider &dataProvider = TextPathDataProvider;
    ASSERT_NO_THROW(dataProvider.getPathFromFile(testFilePath));
    auto path = dataProvider.getPathFromFile(testFilePath);
    EXPECT_EQ(path.size(), 10);
    EXPECT_FLOAT_EQ(path.front().first, 0.0f);
    EXPECT_FLOAT_EQ(path.front().second, 0.0f);
    EXPECT_FLOAT_EQ(path.back().first, 5.6775174f);
    EXPECT_FLOAT_EQ(path.back().second, 5.6774964f);
}

TEST(PathDataProvidertest, EightCurvePathFromFileTest) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/EightCurve/Path";
    TextPathDataProvider TextPathDataProvider;
    AbstractPathDataProvider &dataProvider = TextPathDataProvider;
    ASSERT_NO_THROW(dataProvider.getPathFromFile(testFilePath));
    auto path = dataProvider.getPathFromFile(testFilePath);
    EXPECT_EQ(path.size(), 81);
    EXPECT_FLOAT_EQ(path.front().first, 0.0f);
    EXPECT_FLOAT_EQ(path.front().second, 0.0f);
    EXPECT_FLOAT_EQ(path.back().first, 0.00028545715f);
    EXPECT_FLOAT_EQ(path.back().second, 0.11905058f);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
