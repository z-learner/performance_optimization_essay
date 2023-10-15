cmake_minimum_required(VERSION 3.10)
project(cpu_cache_optimization)


set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(benchmark REQUIRED)

include_directories(include)



add_executable( example_1 "example1/test.cc" )
target_link_libraries(example_1 benchmark pthread)


add_executable( example_2 "example2/test.cc" )
target_link_libraries(example_2 benchmark pthread)

add_executable( example_3 "example3/test.cc" )
target_link_libraries(example_3 benchmark pthread)