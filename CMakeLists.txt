cmake_minimum_required(VERSION 3.10.0)
project(PathReferencePointCalculator VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)

file(GLOB PATH_DATA_PROVIDER_SOURCES CONFIGURE_DEPENDS src/PathDataProvider/*.cpp)

add_library(PathDataProvider
  ${PATH_DATA_PROVIDER_SOURCES}
)

target_include_directories(PathDataProvider PUBLIC
    include/PathDataProvider
)

# Linking our gtest, gmock and benchmark libraries (from third-party).
set(GTEST_DIR ${PROJECT_SOURCE_DIR}/third-party/out/lib)
set(GTEST_ROOT ${PROJECT_SOURCE_DIR}/third-party/out/lib)
include_directories(${PROJECT_SOURCE_DIR}/third-party/out/include)

find_package(GTest REQUIRED)
# Checking, that used our gtest library (from third-party).
message("${PROJECT_NAME} -> GTEST_LIBRARIES - ${GTEST_LIBRARIES}")

add_executable(PathDataProviderTest
    test/PathDataProviderTest.cpp
)

target_link_libraries(PathDataProviderTest
    PathDataProvider
    ${GTEST_LIBRARIES}
)
