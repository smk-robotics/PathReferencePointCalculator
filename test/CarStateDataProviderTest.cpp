#include <gtest/gtest.h>
#include "TextCarStateDataProvider.h"

using namespace path_reference_point_calculator;
using namespace car_state_data_provider;

TEST(CarStateDataProviderTest, ConstructorTest) {
    TextCarStateDataProvider textCarStateDataProvider;
    ASSERT_NO_THROW(AbstractCarStateDataProvider &dataProvider = textCarStateDataProvider);
}

TEST(CarStateDataProviderTest, CarStateDefaultParamsTest) {
    CarState carState;
    EXPECT_FLOAT_EQ(carState.x, 0.0f);
    EXPECT_FLOAT_EQ(carState.y, 0.0f);
    EXPECT_FLOAT_EQ(carState.yaw, 0.0f);
    EXPECT_FLOAT_EQ(carState.speed, 0.0f);
}

TEST(CarStateDataProviderTest, CarStateConstructorTest) {
    CarState carState(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_FLOAT_EQ(carState.x, 1.0f);
    EXPECT_FLOAT_EQ(carState.y, 2.0f);
    EXPECT_FLOAT_EQ(carState.yaw, 3.0f);
    EXPECT_FLOAT_EQ(carState.speed, 4.0f);
}

TEST(CarStateDataProviderTest, BasicTurnCarStateDataFromFileTest) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/BasicTurn/CarStateData";
    TextCarStateDataProvider textCarStateDataProvider;
    AbstractCarStateDataProvider &dataProvider = textCarStateDataProvider;
    ASSERT_NO_THROW(dataProvider.getCarStateDataFromFile(testFilePath));
    auto carState = dataProvider.getCarStateDataFromFile(testFilePath);
    EXPECT_EQ(carState.size(), 91);
    EXPECT_FLOAT_EQ(carState.front().x, 0.0f);
    EXPECT_FLOAT_EQ(carState.front().y, 0.0f);
    EXPECT_FLOAT_EQ(carState.front().yaw, 0.0f);
    EXPECT_FLOAT_EQ(carState.front().speed, 0.0f);
    EXPECT_FLOAT_EQ(carState.back().x, 5.7794337f);
    EXPECT_FLOAT_EQ(carState.back().y, 5.67943f);
    EXPECT_FLOAT_EQ(carState.back().yaw, 1.570797f);
    EXPECT_FLOAT_EQ(carState.back().speed, 0.1f);
}

TEST(CarStateDataProviderTest, EightCurveCarStateDataFromFileTest) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/EightCurve/CarStateData";
    TextCarStateDataProvider textCarStateDataProvider;
    AbstractCarStateDataProvider &dataProvider = textCarStateDataProvider;
    ASSERT_NO_THROW(dataProvider.getCarStateDataFromFile(testFilePath));
    auto carState = dataProvider.getCarStateDataFromFile(testFilePath);
    EXPECT_EQ(carState.size(), 720);
    EXPECT_FLOAT_EQ(carState.front().x, 0.0f);
    EXPECT_FLOAT_EQ(carState.front().y, 0.0f);
    EXPECT_FLOAT_EQ(carState.front().yaw, 4.7123899f);
    EXPECT_FLOAT_EQ(carState.front().speed, 0.0f);
    EXPECT_FLOAT_EQ(carState.back().x, 0.099969141f);
    EXPECT_FLOAT_EQ(carState.back().y, -1.0188852e-07f);
    EXPECT_FLOAT_EQ(carState.back().yaw, 4.7298431f);
    EXPECT_FLOAT_EQ(carState.back().speed, 0.1f);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}