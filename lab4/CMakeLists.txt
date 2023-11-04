cmake_minimum_required(VERSION 3.16)
project(lab04)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_library(figure ${SOURCES})
add_executable(04_test test/test04.cpp)

target_link_libraries(04_test
 PRIVATE
  GTest::GTest
  figure)
enable_testing()

add_test(04_gtest 04_test)