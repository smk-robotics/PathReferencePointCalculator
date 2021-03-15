#include <opencv2/imgproc.hpp> 
#include <opencv2/highgui.hpp>
#include <iostream>
#include <limits>
#include "TextPathDataProvider.h"
#include "TextCarStateDataProvider.h"
#include "GuidingPathPointFinder.h"
#include "PerpendicularLinesCrossingPointCalculator.h"

using namespace path_reference_point_calculator;
using namespace path_data_provider;
using namespace car_state_data_provider;
using namespace path_point_finder;
using namespace crossing_point_calculator;

constexpr uint16_t WINDOW_SIZE = 850;

std::string getPathToFile(const std::string pathName) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/" + pathName;
    return testFilePath;
}

std::pair<float, float> centroidCoordinates(const std::vector<PathPoint> &path) {
    float maxX = std::numeric_limits<float>::min();
    float minX = std::numeric_limits<float>::max();
    float maxY = std::numeric_limits<float>::min();
    float minY = std::numeric_limits<float>::max();
    for (const auto &point : path) {
        if (point.x < minX) minX = point.x;
        if (point.x > maxX) maxX = point.x;
        if (point.y < minY) minY = point.y;
        if (point.y > maxY) maxY = point.y;
    }
    float dx = (fabs(maxX) - fabs(minX)) / 2.0f;
    float dy = (fabs(maxY) - fabs (minY)) / 2.0f;
    return std::make_pair(dx, dy);
}

uint8_t scaleFactor(const std::vector<PathPoint> &path, const cv::Mat &img) {
    float maxX = std::numeric_limits<float>::min();
    float minX = std::numeric_limits<float>::max();
    float maxY = std::numeric_limits<float>::min();
    float minY = std::numeric_limits<float>::max();
    for (const auto &point : path) {
        if (point.x < minX) minX = point.x;
        if (point.x > maxX) maxX = point.x;
        if (point.y < minY) minY = point.y;
        if (point.y > maxY) maxY = point.y;
    }
    float dx = (img.cols / (fabs(maxX) + fabs(minX))) * 0.5f;
    float dy = (img.rows / (fabs(maxY) + fabs(minY))) * 0.5f;
    return std::max(dx, dy);
}

void drawPath(const std::vector<PathPoint> &path, const std::string windowName, const cv::Mat &img) {
    auto centroid = centroidCoordinates(path);
    auto sFactor = scaleFactor(path, img);
    for (auto i = 0; i < path.size(); i++) {
        if (i == 0) {
            continue;
        }
        cv::Point segmentStartPoint(img.cols / 2 + (path.at(i - 1).x - centroid.first) * sFactor, 
                                    img.rows / 2 - (path.at(i - 1).y - centroid.second) * sFactor);
        cv::Point segmentFinishPoint(img.cols / 2 + (path.at(i).x - centroid.first) * sFactor, 
                                     img.rows / 2 - (path.at(i).y - centroid.second) * sFactor);
        cv::circle(img, segmentStartPoint, 3, cv::Scalar( 0, 255, 0 ), cv::FILLED, cv::LINE_8 );
        cv::circle(img, segmentFinishPoint, 3, cv::Scalar( 0, 255, 0 ), cv::FILLED, cv::LINE_8 );
        cv::line(img, segmentStartPoint, segmentFinishPoint, cv::Scalar( 0, 255, 0 ), 2, cv::LINE_8);
        cv::imshow(windowName, img);
    }
}

void drawCarState(std::vector<PathPoint> &path, const std::vector<CarState> &carStates, 
                  const std::string windowName, const cv::Mat &img) {
    GuidingPathPointFinder guidingPathPointFinder;
    PathPointFinderInterface &pathPointFinder = guidingPathPointFinder;
    PerpendicularLinesCrossingPointCalculator pLinesCrossingPointCalculator;
    auto centroid = centroidCoordinates(path);
    auto sFactor = scaleFactor(path, img);
    CrossingPointCalculatorInterface &scrossingPointCalculator = pLinesCrossingPointCalculator;
    for (auto i = 1; i < carStates.size(); i++) {
        cv::Point carPosition(img.cols / 2 + (carStates.at(i).x - centroid.first) * sFactor, 
                              img.rows / 2 - (carStates.at(i).y - centroid.second) * sFactor);
        cv::circle(img, carPosition, 3, cv::Scalar( 255, 0, 255 ), cv::FILLED, cv::LINE_8 );
        auto pointIndex = guidingPathPointFinder.pathPointIndex(carStates.at(i), path);
        cv::Point guidingPoint(img.cols / 2 + (path.at(pointIndex).x - centroid.first) * sFactor, 
                               img.rows / 2 - (path.at(pointIndex).y - centroid.second) * sFactor);
        cv::circle(img, guidingPoint, 2, cv::Scalar( 255, 0, 0 ), cv::FILLED, cv::LINE_8 );
        auto referencePoint = scrossingPointCalculator.crossingPoint(carStates.at(i), path.at(pointIndex - 1),
                                                                                      path.at(pointIndex));
        cv::Point refPoint(img.cols / 2 + (referencePoint.x - centroid.first) * sFactor, 
                           img.rows / 2 - (referencePoint.y - centroid.second) * sFactor);
        cv::circle(img, refPoint, 3, cv::Scalar( 255, 255, 255 ), cv::FILLED, cv::LINE_8 );                                                                                      
        cv::imshow(windowName, img);
        auto k = cv::waitKey(50);
        if (k == 27) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cerr << "[ERROR] - Need to pass path name as argument!"<< std::endl;
        return 0;
    }
    std::string pathFile = getPathToFile(argv[1]) + "/Path";
    TextPathDataProvider textPathDataProvider;
    AbstractPathDataProvider &pathDataProvider = textPathDataProvider;
    auto path = pathDataProvider.getPathFromFile(pathFile);
    
    cv::Mat img = cv::Mat::zeros(WINDOW_SIZE, WINDOW_SIZE, CV_8UC3);
    cv::imshow("TurnPathVisualization", img);
    drawPath(path, "TurnPathVisualization", img);
    std::string carStatePath = getPathToFile(argv[1]) + "/CarStateData";
    TextCarStateDataProvider textCarStateDataProvider;
    AbstractCarStateDataProvider &carStateDataProvider = textCarStateDataProvider;
    auto carStates = carStateDataProvider.getCarStateDataFromFile(carStatePath);
    drawCarState(path, carStates, "TurnPathVisualization", img);
    int k = cv::waitKey(0); // Wait for a keystroke in the window
    return 0;
}