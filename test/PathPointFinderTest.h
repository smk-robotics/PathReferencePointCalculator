#include <string>
#include <gtest/gtest.h>
#include "TextPathDataProvider.h"
#include "GuidingPathPointFinder.h"

#pragma once

using namespace path_reference_point_calculator;
using namespace path_point_finder;
using namespace path_data_provider;

class PathPointFinderTest : public ::testing::Test {
public:    
    void SetUp() {
        TextPathDataProvider textPathDataProvider;
        AbstractPathDataProvider &dataProvider = textPathDataProvider;
        std::string testPathFile = __FILE__;
        testPathFile = testPathFile.substr(0, testPathFile.rfind("test"));
        testPathFile += "test-data/Turn/Path";
        mBasicTurnPath = dataProvider.getPathFromFile(testPathFile);
        testPathFile = testPathFile.substr(0, testPathFile.rfind("test"));
        testPathFile += "test-data/EightCurve/Path";
        mEightCurvePath = dataProvider.getPathFromFile(testPathFile);
    }
protected:
    std::vector<PathPoint> mBasicTurnPath;
    std::vector<PathPoint> mEightCurvePath;
};