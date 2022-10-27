cmake_minimum_required(VERSION 3.0)
project(cartesian_vector_variable)

set(CMAKE_CXX_STANDARD 17)

add_library(cartesian_vector_variable SHARED vector.cc)

add_executable(main main.cc)

target_link_libraries(main cartesian_vector_variable)