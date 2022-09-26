cmake_minimum_required(VERSION 3.0)

project(find_motive)

add_library(find_motive SHARED find_motive.cpp)

add_executable(main main.cpp)

target_link_libraries(main find_motive)