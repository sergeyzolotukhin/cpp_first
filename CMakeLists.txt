cmake_minimum_required(VERSION 3.14)
project(cpp_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_2 main.cpp)
target_link_libraries(cpp_2 ${CMAKE_SOURCE_DIR}/lib/cpp_3.lib)