cmake_minimum_required(VERSION 3.17)
project(RayTracingInOneWeekend)

set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_TOOLCHAIN_FILE "D:/github/vcpkg/scripts/buildsystems/vcpkg.cmake")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)

include_directories("D:/github/vcpkg/installed/x64-windows/include")
#find_path(STB_INCLUDE_DIRS "stb.h")

add_executable(RayTracingInOneWeekend main.cpp src/vec3.h src/color.h src/ray.h src/hittable.h src/sphere.h src/hittable_list.h src/rtweekend.h src/camera.h)
#target_include_directories(RayTracingInOneWeekend PRIVATE ${STB_INCLUDE_DIRS})