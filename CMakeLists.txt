cmake_minimum_required(VERSION 3.14)
project(main)

set(CMAKE_CXX_STANDARD 17)
#set(PDCDEBUG ON)
add_definitions(-DPDCDEBUG)

add_executable(main main.cpp)
target_link_libraries(main ${CMAKE_SOURCE_DIR}/lib/pdcurses.lib)