cmake_minimum_required(VERSION 3.21)
project(sdl3test)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 CONFIG REQUIRED)

add_executable(main src/main.cpp)

target_link_libraries(main SDL3::SDL3)