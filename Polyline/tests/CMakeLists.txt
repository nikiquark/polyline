include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
  test_polyline
  test_polyline.cpp
)
target_link_libraries(
  test_polyline
  Polyline
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_polyline)