include_directories(/usr/src/googletest)
include(FetchContent)

# Fetch Google Test
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# Add test executable
add_executable(tests function_tests.cpp)

# Link against Google Test
target_link_libraries(tests PRIVATE gtest gtest_main)

# Ensure the Google Test include directory is available
target_include_directories(tests PRIVATE ${googletest_SOURCE_DIR}/include)
