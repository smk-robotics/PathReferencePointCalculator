#include <gtest/gtest.h>
#include "TextPathDataProvider.h"
#include "SimpleNearestPathPointFinder.h"

using namespace path_reference_point_calculator;
using namespace nearest_path_point_finder;
using namespace path_data_provider;

TEST(NearestPathPointFinderTest, ConstructorTest) {
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    ASSERT_NO_THROW(NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder);
}

TEST(NearestPathPointFinderTest, FindNearestPathPointTest1) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/BasicTurn/Path";
    TextPathDataProvider textPathDataProvider;
    AbstractPathDataProvider &dataProvider = textPathDataProvider;
    auto path = dataProvider.getPathFromFile(testFilePath);
    CarState carState(0.0f, 0.0f, 0.0f, 0.0f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    auto pointIndex = 0;
    ASSERT_NO_THROW(pointIndex = nearestPathPointFinder.nearestPathPointIndex(carState, path));
    EXPECT_EQ(pointIndex, 0);
}

TEST(NearestPathPointFinderTest, FindNearestPathPointTest2) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/BasicTurn/Path";
    TextPathDataProvider textPathDataProvider;
    AbstractPathDataProvider &dataProvider = textPathDataProvider;
    auto path = dataProvider.getPathFromFile(testFilePath);
    CarState carState(-1.0f, -1.0f, 0.0f, 0.0f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    auto pointIndex = 0;
    ASSERT_NO_THROW(pointIndex = nearestPathPointFinder.nearestPathPointIndex(carState, path));
    EXPECT_EQ(pointIndex, 0);
}

TEST(NearestPathPointFinderTest, FindNearestPathPointTest3) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/BasicTurn/Path";
    TextPathDataProvider textPathDataProvider;
    AbstractPathDataProvider &dataProvider = textPathDataProvider;
    auto path = dataProvider.getPathFromFile(testFilePath);
    CarState carState(5.6775174f, 5.6774964f, 0.0f, 0.0f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    auto pointIndex = 0;
    ASSERT_NO_THROW(pointIndex = nearestPathPointFinder.nearestPathPointIndex(carState, path));
    EXPECT_EQ(pointIndex, 9);
}

TEST(NearestPathPointFinderTest, FindNearestPathPointTest4) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/BasicTurn/Path";
    TextPathDataProvider textPathDataProvider;
    AbstractPathDataProvider &dataProvider = textPathDataProvider;
    auto path = dataProvider.getPathFromFile(testFilePath);
    CarState carState(7.0f, 7.0f, 0.0f, 0.0f);
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    auto pointIndex = 0;
    ASSERT_NO_THROW(pointIndex = nearestPathPointFinder.nearestPathPointIndex(carState, path));
    EXPECT_EQ(pointIndex, 9);
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}