cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
file(GLOB src "*.cpp")

project(YATM)

# add the executable
add_executable(yatm ${src})
