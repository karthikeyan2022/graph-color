cmake_minimum_required(VERSION 4.0)
project(graph_color)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph_color main.cpp
        src/graph.cpp
        inc/graph.h
        src/bfs.cpp
        inc/bfs.h
        inc/dfs.h
        src/dfs.cpp)

file(COPY ${CMAKE_SOURCE_DIR}/input DESTINATION ${CMAKE_BINARY_DIR})
