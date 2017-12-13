# CMake version
cmake_minimum_required(VERSION 2.8)
# Project name
project(ImageBlur)
# Used libraries
find_package(OpenCV REQUIRED)
# Source files
set(SOURCES Gaussian.h Gaussian.cpp)
# Output files
add_executable(imageBlur main.cpp ${SOURCES})
# Link libraries to output files
target_link_libraries(imageBlur ${OpenCV_LIBS})
