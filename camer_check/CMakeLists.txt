cmake_minimum_required(VERSION 3.20)
project(camer_check)

set(CMAKE_CXX_STANDARD 14)
set(OpenCV_DIR /home/aiit/opencv-4.5.0/build)
find_package(OpenCV 4.5.0)

add_executable(camer_check
        camer_check.cpp)

target_link_libraries(camer_check ${OpenCV_LIBRARIES})
