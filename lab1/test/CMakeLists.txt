include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(shiz_test test01.cpp)

target_link_libraries(shiz_test
 PRIVATE
  GTest::GTest
  shiz)

add_test(shiz_gtest shiz_test)