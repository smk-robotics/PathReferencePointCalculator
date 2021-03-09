#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp> 
#include <opencv2/highgui.hpp>
#include <unistd.h>
#include <iostream>
#include "TextPathDataProvider.h"
#include "TextCarStateDataProvider.h"
#include "SimpleNearestPathPointFinder.h"

using namespace path_reference_point_calculator;
using namespace path_data_provider;
using namespace car_state_data_provider;
using namespace nearest_path_point_finder;

std::string getPathToFile(const std::string pathName) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/" + pathName;
    return testFilePath;
}

void drawPath(const std::vector<PathPoint> &path, const std::string windowName, const cv::Mat &img) {
    for (auto i = 0; i < path.size(); i++) {
        if (i == 0) {
            continue;
        }
        cv::Point pt1(path.at(i - 1).x * 75, 500 - path.at(i - 1).y * 75);
        cv::Point pt2(path.at(i).x * 75, 500 - path.at(i).y * 75);
        cv::circle(img, pt1, 3, cv::Scalar( 0, 255, 0 ), cv::FILLED, cv::LINE_8 );
        cv::circle(img, pt2, 3, cv::Scalar( 0, 255, 0 ), cv::FILLED, cv::LINE_8 );
        cv::line(img, pt1, pt2, cv::Scalar( 0, 255, 0 ), 2, cv::LINE_8);
        cv::imshow(windowName, img);
    }
}

void drawCarState(const std::vector<PathPoint> &path, const std::vector<CarState> &carStates, 
                  const std::string windowName, const cv::Mat &img) {
    SimpleNearestPathPointFinder simpleNearestPathPointFinder;
    NearestPathPointFinderInterface &nearestPathPointFinder = simpleNearestPathPointFinder;
    for (auto i = 0; i < carStates.size(); i++) {
        if (i == 0) {
            continue;
        }
        cv::Point pt1(carStates.at(i - 1).x * 75, 500 - carStates.at(i - 1).y * 75);
        cv::Point pt2(carStates.at(i).x * 75, 500 - carStates.at(i).y * 75);
        cv::circle(img, pt1, 2, cv::Scalar( 255, 0, 255 ), cv::FILLED, cv::LINE_8 );
        cv::circle(img, pt2, 2, cv::Scalar( 255, 0, 255 ), cv::FILLED, cv::LINE_8 );
        cv::line(img, pt1, pt2, cv::Scalar( 255, 0, 255 ), 2, cv::LINE_8);
        auto pointIndex = simpleNearestPathPointFinder.nearestPathPointIndex(carStates.at(i), path);
        cv::Point pt3(path.at(pointIndex).x * 75, 500 - path.at(pointIndex).y * 75);
        cv::circle(img, pt3, 4, cv::Scalar( 0, 0, 255 ), cv::FILLED, cv::LINE_8 );
        cv::imshow(windowName, img);
        cv::waitKey(100);
    }
}

int main(int argc, char *argv[]) {
    cv::Mat img = cv::Mat::zeros(500, 500, CV_8UC3 );
    cv::imshow("TurnPathVisualization", img);
    std::string pathFile = getPathToFile(argv[1]) + "/Path";
    TextPathDataProvider textPathDataProvider;
    AbstractPathDataProvider &pathDataProvider = textPathDataProvider;
    auto path = pathDataProvider.getPathFromFile(pathFile);
    drawPath(path, "TurnPathVisualization", img);
    std::string carStatePath = getPathToFile(argv[1]) + "/CarStateData";
    TextCarStateDataProvider textCarStateDataProvider;
    AbstractCarStateDataProvider &carStateDataProvider = textCarStateDataProvider;
    auto carStates = carStateDataProvider.getCarStateDataFromFile(carStatePath);
    drawCarState(path, carStates, "TurnPathVisualization", img);
    int k = cv::waitKey(0); // Wait for a keystroke in the window
    return 0;
}