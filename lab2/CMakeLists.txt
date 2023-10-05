cmake_minimum_required(VERSION 3.16)
project(lab02)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")
file(GLOB TEST "test/*.cpp")

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_library(eleven ${SOURCES})
add_executable(02_test ${TEST})

target_link_libraries(02_test
 PRIVATE
  GTest::GTest
  eleven)
enable_testing()

add_test(02_gtest 02_test)