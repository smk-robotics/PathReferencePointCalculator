cmake_minimum_required(VERSION 3.10.0)
project(PathReferencePointCalculator LANGUAGES CXX VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

##################
### PATH_POINT ###
##################
add_library(PathPoint INTERFACE)

target_include_directories(PathPoint INTERFACE
    include/PathPoint
)
##################################
### PATH_DATA_PROVIDER_LIBRARY ###
##################################
file(GLOB PATH_DATA_PROVIDER_SOURCES CONFIGURE_DEPENDS src/PathDataProvider/*.cpp)

add_library(PathDataProvider
  ${PATH_DATA_PROVIDER_SOURCES}
)

target_link_libraries(PathDataProvider PUBLIC
    PathPoint
)

target_include_directories(PathDataProvider PUBLIC
    include/PathDataProvider
)
#################
### CAR_STATE ###
#################
add_library(CarState INTERFACE)

target_include_directories(CarState INTERFACE
    include/CarState
)
###############################
### CAR_STATE_DATA_PROVIDER ###
###############################
file(GLOB CAR_STATE_DATA_PROVIDER_SOURCES CONFIGURE_DEPENDS src/CarStateDataProvider/*.cpp)

add_library(CarStateDataProvider
  ${CAR_STATE_DATA_PROVIDER_SOURCES}
)

target_link_libraries(CarStateDataProvider PUBLIC
    CarState
)

target_include_directories(CarStateDataProvider PUBLIC
    include/CarStateDataProvider
)
#########################
### PATH_POINT_FINDER ###
#########################
file(GLOB PATH_POINT_FINDER_SOURCES CONFIGURE_DEPENDS src/PathPointFinder/*.cpp)

add_library(PathPointFinder
  ${PATH_POINT_FINDER_SOURCES}
)

target_link_libraries(PathPointFinder PUBLIC
    CarState
    PathPoint
)

target_include_directories(PathPointFinder PUBLIC
    include/PathPointFinder
)
############
### LINE ###
############
add_library(Line INTERFACE)

target_include_directories(Line INTERFACE 
    include/Line
)
#################################
### CROSSING_POINT_CALCULATOR ###
#################################
file(GLOB CROSSING_POINT_CALCULATOR_SOURCES CONFIGURE_DEPENDS src/CrossingPointCalculator/*.cpp)

add_library(CrossingPointCalculator
  ${CROSSING_POINT_CALCULATOR_SOURCES}
)

target_link_libraries(CrossingPointCalculator PUBLIC
    CarState
    PathPoint
    Line
)

target_include_directories(CrossingPointCalculator PUBLIC
    include/CrossingPointCalculator
)

#######################################
### PATH_REFERENCE_POINT_CALCULATOR ###
#######################################
add_library(PathReferencePointCalculator
  src/PathReferencePointCalculator/PathReferencePointCalculator.cpp
)

target_link_libraries(PathReferencePointCalculator PUBLIC
    CrossingPointCalculator
    PathPointFinder
)

target_include_directories(PathReferencePointCalculator PUBLIC
    include/PathReferencePointCalculator
)
#############
### TESTS ###
#############
if (BUILD_TESTS) 
    enable_testing()
    add_subdirectory(test)
endif()
#####################
### VISUALIZATION ###
#####################
if (BUILD_VISUALIZATION)
find_package(OpenCV REQUIRED)

add_executable(Visualization
    test/Visualization.cpp
)

target_link_libraries(Visualization
    PathDataProvider
    CarStateDataProvider
    PathReferencePointCalculator
    ${OpenCV_LIBRARIES}
)
endif()