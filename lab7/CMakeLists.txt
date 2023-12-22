cmake_minimum_required(VERSION 3.16)
project(lab06)

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

add_library(npc ${SOURCES})
add_executable(07_test test/main.cpp)

target_link_libraries(07_test
 PRIVATE
  GTest::GTest
  npc)
enable_testing()

add_test(07_gtest 07_test)