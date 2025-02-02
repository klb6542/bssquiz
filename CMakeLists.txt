cmake_minimum_required(VERSION 3.10)
project(BSSQuiz)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find and link Raylib
find_package(raylib REQUIRED)

# Set the output directory for the executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(bssquiz
    src/main.cpp
    src/textlabel.cpp
    src/window.cpp
    src/timer.cpp
)

target_link_libraries(bssquiz raylib)
