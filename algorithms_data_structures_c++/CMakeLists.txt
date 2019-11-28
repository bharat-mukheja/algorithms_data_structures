cmake_minimum_required(VERSION 3.15)
project(data_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(data_structures
        data_structures/Dijkstra.cpp
        data_structures/disjoint_sets.cpp
        data_structures/graph.cpp
        data_structures/KruskalMST.cpp
        data_structures/main.cpp)
