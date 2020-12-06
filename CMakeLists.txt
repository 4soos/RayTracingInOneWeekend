cmake_minimum_required(VERSION 3.17)
project(RayTracingInOneWeekend)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)

add_executable(RayTracingInOneWeekend main.cpp src/vec3.h src/color.h src/ray.h)