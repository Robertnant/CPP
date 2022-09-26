cmake_minimum_required(VERSION 3.0)
project(is_prime_prog)

set(CMAKE_CXX_STANDARD 14)

add_library(is_prime_prog SHARED is_prime_prog.cpp)

add_executable(main main.cpp)

target_link_libraries(main is_prime_prog)
