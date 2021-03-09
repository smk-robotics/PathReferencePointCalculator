# Linking third party gtest, gmock and benchmark libraries.
set(GTEST_DIR ${PROJECT_SOURCE_DIR}/third-party/out/lib)
set(GTEST_ROOT ${PROJECT_SOURCE_DIR}/third-party/out/lib)
set(GTEST_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/third-party/out/include)
include_directories(${PROJECT_SOURCE_DIR}/third-party/out/include)

find_package(GTest REQUIRED)
# Checking, that used our gtest library (from third-party).
message("${PROJECT_NAME} -> GTEST_LIBRARIES - ${GTEST_LIBRARIES}")

add_executable(PathDataProviderTest
    PathDataProviderTest.cpp
)

target_link_libraries(PathDataProviderTest
    PathDataProvider
    ${GTEST_LIBRARIES}
)

add_executable(CarStateDataProviderTest
    CarStateDataProviderTest.cpp
)

target_link_libraries(CarStateDataProviderTest
    CarStateDataProvider
    ${GTEST_LIBRARIES}
)

add_executable(NearestPathPointFinderTest
    NearestPointFinderTest.cpp
    NearestPointFinderTurnTest.cpp
    NearestPointFinderEightTest.cpp
)

target_link_libraries(NearestPathPointFinderTest
    PathDataProvider
    NearestPathPointFinder
    ${GTEST_LIBRARIES}
)

gtest_discover_tests(PathDataProviderTest)
gtest_discover_tests(CarStateDataProviderTest)
gtest_discover_tests(NearestPathPointFinderTest) 
#####################
### VISUALIZATION ###
#####################
if (BUILD_VISUALIZATION)
find_package(OpenCV REQUIRED)

add_executable(TurnPathVisualization
    TurnPathVisualization.cpp
)

target_link_libraries(TurnPathVisualization
    PathDataProvider
    CarStateDataProvider
    NearestPathPointFinder
    ${OpenCV_LIBRARIES}
)
endif()