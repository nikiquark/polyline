include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(
  test_vector3
  test_vector3.cpp
)
target_link_libraries(
  test_vector3
  GTest::gtest_main
)

add_executable(
  test_utils
  test_utils.cpp
)
target_link_libraries(
  test_utils
  Vector3
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(test_vector3)
gtest_discover_tests(test_utils)
