cmake_minimum_required(VERSION 3.10)
project(cpu_cache_optimization)


set(CMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fopenmp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

add_executable( example_1 "example1/test.cc" )
target_link_libraries(example_1 /usr/local/lib/libbenchmark.a pthread)


add_executable( example_2 "example2/test.cc" )
target_link_libraries(example_2 /usr/local/lib/libbenchmark.a pthread)

add_executable( example_3 "example3/test.cc" )
target_link_libraries(example_3 /usr/local/lib/libbenchmark.a pthread)

add_executable( example_4 "example4/test.cc" )
target_link_libraries(example_4 /usr/local/lib/libbenchmark.a pthread)

add_executable( example_5 "example5/test.cc" )
target_link_libraries(example_5 /usr/local/lib/libbenchmark.a pthread)

add_executable( example_6 "example6/test.cc" )
target_link_libraries(example_6 /usr/local/lib/libbenchmark.a pthread)