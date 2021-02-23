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

set(GTEST_ROOT ${PROJECT_SOURCE_DIR}/third-party/out/lib)
find_package(GTest REQUIRED)

add_executable(PathDataProviderTest
    test/PathDataProviderTest.cpp
)

target_link_libraries(PathDataProviderTest
    PathDataProvider
    ${GTEST_LIBRARIES}
)
