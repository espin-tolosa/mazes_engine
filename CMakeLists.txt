cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -pedantic")

project(main)

add_executable( main src/main.cpp src/bmp_image/Bitmap.cpp src/bmp_image/BitmapFields.cpp src/path_finder_algo/mandelbrot.cpp src/path_finder_algo/PathFinder.cpp)
