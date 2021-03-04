cmake_minimum_required(VERSION 3.10.0)
project(PathReferencePointCalculator VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

##########################
### PATH_POINT_LIBRARY ###
##########################
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
#########################
### CAR_STATE_LIBRARY ###
#########################
add_library(CarState INTERFACE)

target_include_directories(CarState INTERFACE
    include/CarState
)

#######################################
### CAR_STATE_DATA_PROVIDER_LIBRARY ###
#######################################
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

if (BUILD_TESTS) 
    enable_testing()
    add_subdirectory(test)
endif()