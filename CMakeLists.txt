cmake_minimum_required(VERSION 3.24)

# "What Happens When"?
project(whw LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(modulus negative_modulus.cpp)
add_executable(boolean_precedence boolean_precedence.cpp)
add_executable(null_terminators null_terminators.cpp)
add_executable(string_view_stream_parsing string_view_stream_parsing.cpp)
