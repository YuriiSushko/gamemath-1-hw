cmake_minimum_required(VERSION 3.5)
project(Tasks LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

set(CMAKE_BUILD_TYPE Release)

add_executable(main src/main.cpp)
