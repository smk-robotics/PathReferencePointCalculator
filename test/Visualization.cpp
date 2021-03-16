#include <opencv2/imgproc.hpp> 
#include <opencv2/highgui.hpp>
#include <tuple>
#include <limits>
#include <iostream>
#include "TextPathDataProvider.h"
#include "TextCarStateDataProvider.h"
#include "PathReferncePointCalculator.h"

using namespace path_reference_point_calculator;
using namespace path_data_provider;
using namespace car_state_data_provider;

constexpr uint16_t WINDOW_SIZE = 850;

std::string getPathToFile(const std::string pathName) {
    std::string testFilePath = __FILE__;
    testFilePath = testFilePath.substr(0, testFilePath.rfind("test"));
    testFilePath += "test-data/" + pathName;
    return testFilePath;
}

std::tuple<float, float, float> scaleParameters(const std::vector<PathPoint> &path, const cv::Mat &img) {
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
    auto centerX = (fabs(maxX) - fabs(minX)) / 2.0f;
    auto centerY = (fabs(maxY) - fabs (minY)) / 2.0f;
    auto scaleCoeffX = (img.cols / (fabs(maxX) + fabs(minX))) * 0.5f;
    auto scaleCoeffY = (img.rows / (fabs(maxY) + fabs(minY))) * 0.5f;
    auto scale = std::max(scaleCoeffX, scaleCoeffY);
    return std::make_tuple(centerX, centerY, scale);
}

void drawPath(const std::vector<PathPoint> &path, const std::string windowName, const cv::Mat &img) {
    float centroidX = 0.0f;
    float centroidY = 0.0f;
    float sFactor = 1.0f;
    std::tie(centroidX, centroidY, sFactor) = scaleParameters(path, img);
    for (auto i = 0; i < path.size(); i++) {
        if (i== 0) {
            continue;
        }
        cv::Point segmentStartPoint(img.cols / 2 + (path.at(i - 1).x - centroidX) * sFactor, 
                                    img.rows / 2 - (path.at(i - 1).y - centroidY) * sFactor);
        cv::Point segmentFinishPoint(img.cols / 2 + (path.at(i).x - centroidX) * sFactor, 
                                     img.rows / 2 - (path.at(i).y - centroidY) * sFactor);
        cv::circle(img, segmentStartPoint, 3, cv::Scalar( 0, 255, 0 ), cv::FILLED, cv::LINE_8 );
        cv::circle(img, segmentFinishPoint, 3, cv::Scalar( 0, 255, 0 ), cv::FILLED, cv::LINE_8 );
        cv::line(img, segmentStartPoint, segmentFinishPoint, cv::Scalar( 0, 255, 0 ), 2, cv::LINE_8);
        cv::imshow(windowName, img);
    }
}

void drawCarState(std::vector<PathPoint> &path, const std::vector<CarState> &carStates, 
                  const std::string windowName, const cv::Mat &img) {
    float centroidX = 0.0f;
    float centroidY = 0.0f;
    float sFactor = 1.0f;
    std::tie(centroidX, centroidY, sFactor) = scaleParameters(path, img);
    PathReferncePointCalculator referencePointCalculator(path, 1.5709f);
    for (auto i = 1; i < carStates.size(); i++) {
        cv::Point carPosition(img.cols / 2 + (carStates.at(i).x - centroidX) * sFactor, 
                              img.rows / 2 - (carStates.at(i).y - centroidY) * sFactor);
        cv::circle(img, carPosition, 2, cv::Scalar( 255, 0, 255 ), cv::FILLED, cv::LINE_8 );
        auto referencePoint = referencePointCalculator.pathReferencePoint(carStates.at(i));
        if (!referencePoint) {
            continue;
        }
        cv::Point refPoint(img.cols / 2 + (referencePoint.value().x - centroidX) * sFactor, 
                           img.rows / 2 - (referencePoint.value().y - centroidY) * sFactor);
        cv::circle(img, refPoint, 2, cv::Scalar( 0, 255, 255 ), cv::FILLED, cv::LINE_8);                                                                                      
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
    /**< Getting path data. */
    std::string pathFile = getPathToFile(argv[1]) + "/Path";
    TextPathDataProvider textPathDataProvider;
    AbstractPathDataProvider &pathDataProvider = textPathDataProvider;
    auto path = pathDataProvider.getPathFromFile(pathFile);
    /**< Getting car state data. */
    std::string carStatePath = getPathToFile(argv[1]) + "/CarStateData";
    TextCarStateDataProvider textCarStateDataProvider;
    AbstractCarStateDataProvider &carStateDataProvider = textCarStateDataProvider;
    auto carStates = carStateDataProvider.getCarStateDataFromFile(carStatePath);
    /**< Visualization. */
    cv::Mat img = cv::Mat::zeros(WINDOW_SIZE, WINDOW_SIZE, CV_8UC3);
    cv::imshow("TurnPathVisualization", img);
    drawPath(path, "TurnPathVisualization", img);
    drawCarState(path, carStates, "TurnPathVisualization", img);
    cv::waitKey(1000);
    return 0;
}